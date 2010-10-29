/* libguestfs
 * Copyright (C) 2010 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <errno.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <utime.h>

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs-internal-actions.h"
#include "guestfs_protocol.h"

static const char *kernel_name = "vmlinuz." host_cpu;
static const char *initrd_name = "initramfs." host_cpu ".img";

static int find_path (guestfs_h *g, int (*pred) (guestfs_h *g, const char *pelem, void *data), void *data, char **pelem);
static int dir_contains_file (const char *dir, const char *file);
static int dir_contains_files (const char *dir, ...);
static int contains_supermin_appliance (guestfs_h *g, const char *path, void *data);
static int contains_ordinary_appliance (guestfs_h *g, const char *path, void *data);
static char *calculate_supermin_checksum (guestfs_h *g, const char *supermin_path);
static int check_for_cached_appliance (guestfs_h *g, const char *supermin_path, const char *checksum, char **kernel, char **initrd, char **appliance);
static int build_supermin_appliance (guestfs_h *g, const char *supermin_path, const char *checksum, char **kernel, char **initrd, char **appliance);
static int run_supermin_helper (guestfs_h *g, const char *supermin_path, const char *cachedir, size_t cdlen);

/* Locate or build the appliance.
 *
 * This function locates or builds the appliance as necessary,
 * handling the supermin appliance, caching of supermin-built
 * appliances, or using an ordinary appliance.
 *
 * The return value is 0 = good, -1 = error.  Returned in '*kernel'
 * will be the name of the kernel to use, '*initrd' the name of the
 * initrd, '*appliance' the name of the ext2 root filesystem.
 * '*appliance' can be NULL, meaning that we are using an ordinary
 * (non-ext2) appliance.  All three strings must be freed by the
 * caller.  However the referenced files themselves must not be
 * deleted.
 *
 * The process is as follows:
 *
 * (1) Look for the first element of g->path which contains a
 * supermin appliance skeleton.  If no element has this, skip
 * straight to step (5).
 * (2) Calculate the checksum of this supermin appliance.
 * (3) Check whether $TMPDIR/$checksum/ directory exists, contains
 * a cached appliance, and passes basic security checks.  If so,
 * return this appliance.
 * (4) Try to build the supermin appliance into $TMPDIR/$checksum/.
 * If this is successful, return it.
 * (5) Check each element of g->path, looking for an ordinary appliance.
 * If one is found, return it.
 */
int
guestfs___build_appliance (guestfs_h *g,
                           char **kernel, char **initrd, char **appliance)
{
  int r;

  /* Step (1). */
  char *supermin_path;
  r = find_path (g, contains_supermin_appliance, NULL, &supermin_path);
  if (r == -1)
    return -1;

  if (r == 1) {
    /* Step (2): calculate checksum. */
    char *checksum = calculate_supermin_checksum (g, supermin_path);
    if (checksum) {
      /* Step (3): cached appliance exists? */
      r = check_for_cached_appliance (g, supermin_path, checksum,
                                      kernel, initrd, appliance);
      if (r != 0) {
        free (supermin_path);
        free (checksum);
        return r == 1 ? 0 : -1;
      }

      /* Step (4): build supermin appliance. */
      r = build_supermin_appliance (g, supermin_path, checksum,
                                    kernel, initrd, appliance);
      free (supermin_path);
      free (checksum);
      return r;
    }
    free (supermin_path);
  }

  /* Step (5). */
  char *path;
  r = find_path (g, contains_ordinary_appliance, NULL, &path);
  if (r == -1)
    return -1;

  if (r == 1) {
    size_t len = strlen (path);
    *kernel = safe_malloc (g, len + strlen (kernel_name) + 2);
    *initrd = safe_malloc (g, len + strlen (initrd_name) + 2);
    sprintf (*kernel, "%s/%s", path, kernel_name);
    sprintf (*initrd, "%s/%s", path, initrd_name);
    *appliance = NULL;

    free (path);
    return 0;
  }

  error (g, _("cannot find any suitable libguestfs supermin or ordinary appliance on LIBGUESTFS_PATH (search path: %s)"),
         g->path);
  return -1;
}

static int
contains_supermin_appliance (guestfs_h *g, const char *path, void *data)
{
  return dir_contains_files (path, "supermin.d", "kmod.whitelist", NULL);
}

static int
contains_ordinary_appliance (guestfs_h *g, const char *path, void *data)
{
  return dir_contains_files (path, kernel_name, initrd_name, NULL);
}

/* supermin_path is a path which is known to contain a supermin
 * appliance.  Using febootstrap-supermin-helper -f checksum calculate
 * the checksum so we can see if it is cached.
 */
static char *
calculate_supermin_checksum (guestfs_h *g, const char *supermin_path)
{
  size_t len = 2 * strlen (supermin_path) + 256;
  char cmd[len];
  int pass_u_g_args = getuid () != geteuid () || getgid () != getegid ();

  if (!pass_u_g_args)
    snprintf (cmd, len,
              "febootstrap-supermin-helper%s "
              "-f checksum "
              "'%s/supermin.d' "
              host_cpu,
              g->verbose ? " --verbose" : "",
              supermin_path);
  else
    snprintf (cmd, len,
              "febootstrap-supermin-helper%s "
              "-u %i "
              "-g %i "
              "-f checksum "
              "'%s/supermin.d' "
              host_cpu,
              g->verbose ? " --verbose" : "",
              geteuid (), getegid (),
              supermin_path);

  if (g->verbose)
    guestfs___print_timestamped_message (g, "%s", cmd);

  /* Errors here are non-fatal, so we don't need to call error(). */
  FILE *pp = popen (cmd, "r");
  if (pp == NULL)
    return NULL;

  char checksum[256];
  if (fgets (checksum, sizeof checksum, pp) == NULL) {
    pclose (pp);
    return NULL;
  }

  if (pclose (pp) == -1) {
    perror ("pclose");
    return NULL;
  }

  len = strlen (checksum);

  if (len < 16) {               /* sanity check */
    fprintf (stderr, "libguestfs: internal error: febootstrap-supermin-helper -f checksum returned a short string\n");
    return NULL;
  }

  if (len > 0 && checksum[len-1] == '\n')
    checksum[--len] = '\0';

  return safe_strndup (g, checksum, len);
}

/* Check for cached appliance in $TMPDIR/$checksum.  Check it exists
 * and passes some basic security checks.
 *
 * Returns:
 * 1 = exists, and passes
 * 0 = does not exist
 * -1 = error which should abort the whole launch process
 */
static int
security_check_cache_file (guestfs_h *g, const char *filename,
                           const struct stat *statbuf)
{
  uid_t uid = geteuid ();

  if (statbuf->st_uid != uid) {
    error (g, ("libguestfs cached appliance %s is not owned by UID %d\n"),
           filename, uid);
    return -1;
  }

  if ((statbuf->st_mode & 0022) != 0) {
    error (g, ("libguestfs cached appliance %s is writable by group or other (mode %o)\n"),
           filename, statbuf->st_mode);
    return -1;
  }

  return 0;
}

static int
check_for_cached_appliance (guestfs_h *g,
                            const char *supermin_path, const char *checksum,
                            char **kernel, char **initrd, char **appliance)
{
  const char *tmpdir = guestfs_tmpdir ();

  size_t len = strlen (tmpdir) + strlen (checksum) + 10;
  char cachedir[len];
  snprintf (cachedir, len, "%s/guestfs.%s", tmpdir, checksum);

  /* Touch the directory to prevent it being deleting in a rare race
   * between us doing the checks and a tmp cleaner running.  Note this
   * doesn't create the directory, and we ignore any error.
   */
  (void) utime (cachedir, NULL);

  /* See if the cache directory exists and passes some simple checks
   * to make sure it has not been tampered with.  Note that geteuid()
   * forms a part of the checksum.
   */
  struct stat statbuf;
  if (lstat (cachedir, &statbuf) == -1)
    return 0;

  if (security_check_cache_file (g, cachedir, &statbuf) == -1)
    return -1;

  int ret;

  *kernel = safe_malloc (g, len + 8 /* / + "kernel" + \0 */);
  *initrd = safe_malloc (g, len + 8 /* / + "initrd" + \0 */);
  *appliance = safe_malloc (g, len + 6 /* / + "root" + \0 */);
  sprintf (*kernel, "%s/kernel", cachedir);
  sprintf (*initrd, "%s/initrd", cachedir);
  sprintf (*appliance, "%s/root", cachedir);

  /* Touch the files to prevent them being deleted, and to bring the
   * cache up to date.  Note this doesn't create the files.
   */
  (void) utime (*kernel, NULL);

  /* NB. *kernel is a symlink, so we want to check the kernel, not the
   * link (stat, not lstat).  We don't do a security check on the
   * kernel since it's always under /boot.
   */
  if (stat (*kernel, &statbuf) == -1) {
    ret = 0;
    goto error;
  }

  (void) utime (*initrd, NULL);

  if (lstat (*initrd, &statbuf) == -1) {
    ret = 0;
    goto error;
  }

  if (security_check_cache_file (g, *initrd, &statbuf) == -1) {
    ret = -1;
    goto error;
  }

  (void) utime (*appliance, NULL);

  if (lstat (*appliance, &statbuf) == -1) {
    ret = 0;
    goto error;
  }

  if (security_check_cache_file (g, *appliance, &statbuf) == -1) {
    ret = -1;
    goto error;
  }

  /* Exists! */
  return 1;

 error:
  free (*kernel);
  free (*initrd);
  free (*appliance);
  return ret;
}

/* Build supermin appliance from supermin_path to $TMPDIR/$checksum.
 *
 * Returns:
 * 0 = built
 * -1 = error (aborts launch)
 */
static int
build_supermin_appliance (guestfs_h *g,
                          const char *supermin_path, const char *checksum,
                          char **kernel, char **initrd, char **appliance)
{
  if (g->verbose)
    guestfs___print_timestamped_message (g, "begin building supermin appliance");

  const char *tmpdir = guestfs_tmpdir ();

  size_t tmpcdlen = strlen (tmpdir) + 16;
  char tmpcd[tmpcdlen];
  snprintf (tmpcd, tmpcdlen, "%s/guestfs.XXXXXX", tmpdir);

  if (NULL == mkdtemp (tmpcd)) {
    error (g, _("failed to create temporary cache directory: %m"));
    return -1;
  }

  if (g->verbose)
    guestfs___print_timestamped_message (g, "run febootstrap-supermin-helper");

  int r = run_supermin_helper (g, supermin_path, tmpcd, tmpcdlen);
  if (r == -1)
    return -1;

  if (g->verbose)
    guestfs___print_timestamped_message (g, "finished building supermin appliance");

  size_t cdlen = strlen (tmpdir) + strlen (checksum) + 10;
  char cachedir[cdlen];
  snprintf (cachedir, cdlen, "%s/guestfs.%s", tmpdir, checksum);

  /* Make the temporary directory world readable */
  if (chmod (tmpcd, 0755) == -1) {
    error (g, "chmod %s: %m", tmpcd);
  }

  /* Try to rename the temporary directory to its non-temporary name */
  if (rename (tmpcd, cachedir) == -1) {
    /* If the cache directory now exists, we may have been racing with another
     * libguestfs process. Check the new directory and use it if it's valid. */
    if (errno == ENOTEMPTY || errno == EEXIST) {
      /* Appliance cache consists of 2 files and a symlink in the cache
       * directory. Delete them first. */
      DIR *dir = opendir (tmpcd);
      if (dir == NULL) {
        error (g, "opendir %s: %m", tmpcd);
        return -1;
      }

      int fd = dirfd (dir);
      if (fd == -1) {
        error (g, "dirfd: %m");
        closedir (dir);
        return -1;
      }

      struct dirent *dirent;
      for (;;) {
        errno = 0;
        dirent = readdir (dir);

        if (dirent == NULL) {
          break;
        }

        /* Check that dirent is a file so we don't try to delete . and .. */
        struct stat st;
        if (fstatat (fd, dirent->d_name, &st, AT_SYMLINK_NOFOLLOW) == -1) {
          error (g, "fstatat %s: %m", dirent->d_name);
          return -1;
        }

        if (!S_ISDIR(st.st_mode)) {
          if (unlinkat (fd, dirent->d_name, 0) == -1) {
            error (g, "unlinkat %s: %m", dirent->d_name);
            closedir (dir);
            return -1;
          }
        }
      }

      if (errno != 0) {
        error (g, "readdir %s: %m", tmpcd);
        closedir (dir);
        return -1;
      }

      closedir (dir);

      /* Delete the temporary cache directory itself. */
      if (rmdir (tmpcd) == -1) {
        error (g, "rmdir %s: %m", tmpcd);
        return -1;
      }

      /* Check the new cache directory, and return it if valid */
      return check_for_cached_appliance (g, supermin_path, checksum,
                                         kernel, initrd, appliance);
    }

    else {
      error (g, _("error renaming temporary cache directory: %m"));
      return -1;
    }
  }

  *kernel = safe_malloc (g, cdlen + 8 /* / + "kernel" + \0 */);
  *initrd = safe_malloc (g, cdlen + 8 /* / + "initrd" + \0 */);
  *appliance = safe_malloc (g, cdlen + 6 /* / + "root" + \0 */);
  sprintf (*kernel, "%s/kernel", cachedir);
  sprintf (*initrd, "%s/initrd", cachedir);
  sprintf (*appliance, "%s/root", cachedir);

  return 0;
}

/* Run febootstrap-supermin-helper and tell it to generate the
 * appliance.
 */
static int
run_supermin_helper (guestfs_h *g, const char *supermin_path,
                     const char *cachedir, size_t cdlen)
{
  size_t pathlen = strlen (supermin_path);

  const char *argv[30];
  size_t i = 0;

  char uid[32];
  snprintf (uid, sizeof uid, "%i", geteuid ());
  char gid[32];
  snprintf (gid, sizeof gid, "%i", getegid ());
  char supermin_d[pathlen + 32];
  snprintf (supermin_d, pathlen + 32, "%s/supermin.d", supermin_path);
  char kernel[cdlen + 32];
  snprintf (kernel, cdlen + 32, "%s/kernel", cachedir);
  char initrd[cdlen + 32];
  snprintf (initrd, cdlen + 32, "%s/initrd", cachedir);
  char root[cdlen + 32];
  snprintf (root, cdlen + 32, "%s/root", cachedir);

  int pass_u_g_args = getuid () != geteuid () || getgid () != getegid ();

  argv[i++] = "febootstrap-supermin-helper";
  if (g->verbose)
    argv[i++] = "--verbose";
  if (pass_u_g_args) {
    argv[i++] = "-u";
    argv[i++] = uid;
    argv[i++] = "-g";
    argv[i++] = gid;
  }
  argv[i++] = "-f";
  argv[i++] = "ext2";
  argv[i++] = supermin_d;
  argv[i++] = host_cpu;
  argv[i++] = kernel;
  argv[i++] = initrd;
  argv[i++] = root;
  argv[i++] = NULL;

  pid_t pid = fork ();
  if (pid == -1) {
    perrorf (g, "fork");
    return -1;
  }

  if (pid > 0) {                /* Parent. */
    if (g->verbose)
      guestfs___print_timestamped_argv (g, argv);

    int status;
    if (waitpid (pid, &status, 0) == -1) {
      perrorf (g, "waitpid");
      return -1;
    }
    if (!WIFEXITED (status) || WEXITSTATUS (status) != 0) {
      error (g, _("external command failed, see earlier error messages"));
      return -1;
    }
    return 0;
  }

  /* Child. */

  /* Set a sensible umask in the subprocess, so kernel and initrd
   * output files are world-readable (RHBZ#610880).
   */
  umask (0022);

  execvp ("febootstrap-supermin-helper", (char * const *) argv);
  perror ("execvp");
  _exit (EXIT_FAILURE);
}

/* Search elements of g->path, returning the first path element which
 * matches the predicate function 'pred'.
 *
 * Function 'pred' must return a true or false value.  If it returns
 * -1 then the entire search is aborted.
 *
 * Return values:
 * 1 = a path element matched, it is returned in *pelem_ret and must be
 *     freed by the caller,
 * 0 = no path element matched, *pelem_ret is set to NULL, or
 * -1 = error which aborts the launch process
 */
static int
find_path (guestfs_h *g,
           int (*pred) (guestfs_h *g, const char *pelem, void *data),
           void *data,
           char **pelem_ret)
{
  size_t len;
  int r;
  const char *pelem = g->path;

  /* Note that if g->path is an empty string, we want to check the
   * current directory (for backwards compatibility with
   * libguestfs < 1.5.4).
   */
  do {
    len = strcspn (pelem, ":");

    /* Empty element or "." means current directory. */
    if (len == 0)
      *pelem_ret = safe_strdup (g, ".");
    else
      *pelem_ret = safe_strndup (g, pelem, len);

    r = pred (g, *pelem_ret, data);
    if (r == -1) {
      free (*pelem_ret);
      return -1;
    }

    if (r != 0)                 /* predicate matched */
      return 1;

    free (*pelem_ret);

    if (pelem[len] == ':')
      pelem += len + 1;
    else
      pelem += len;
  } while (*pelem);

  /* Predicate didn't match on any path element. */
  *pelem_ret = NULL;
  return 0;
}

/* Returns true iff file is contained in dir. */
static int
dir_contains_file (const char *dir, const char *file)
{
  size_t dirlen = strlen (dir);
  size_t filelen = strlen (file);
  size_t len = dirlen + filelen + 2;
  char path[len];

  snprintf (path, len, "%s/%s", dir, file);
  return access (path, F_OK) == 0;
}

/* Returns true iff every listed file is contained in 'dir'. */
static int
dir_contains_files (const char *dir, ...)
{
  va_list args;
  const char *file;

  va_start (args, dir);
  while ((file = va_arg (args, const char *)) != NULL) {
    if (!dir_contains_file (dir, file)) {
      va_end (args);
      return 0;
    }
  }
  va_end (args);
  return 1;
}