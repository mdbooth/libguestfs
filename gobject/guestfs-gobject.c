/* libguestfs GObject bindings
 * Copyright (C) 2011 Red Hat Inc.
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

#include <glib.h>
#include <glib-object.h>
#include <guestfs.h>
#include <string.h>

#include <stdio.h>

#include "guestfs-gobject.h"

/**
 * SECTION: guestfs-session
 * @short_description: Libguestfs session
 * @include: guestfs-gobject.h
 *
 * A libguestfs session which can be used to inspect and modify virtual disk
 * images.
 */

#define GUESTFS_SESSION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ( \
                                            (obj), \
                                            GUESTFS_TYPE_SESSION, \
                                            GuestfsSessionPrivate))

struct _GuestfsSessionPrivate
{
  guestfs_h *g;
};

G_DEFINE_TYPE(GuestfsSession, guestfs_session, G_TYPE_OBJECT);

#define GUESTFS_SESSION_ERROR guestfs_session_error_quark()

static GQuark
guestfs_session_error_quark(void)
{
  return g_quark_from_static_string("guestfs-session");
}

static void
guestfs_session_finalize(GObject *object)
{
  GuestfsSession *session = GUESTFS_SESSION(object);
  GuestfsSessionPrivate *priv = session->priv;

  if (priv->g) guestfs_close(priv->g);

  G_OBJECT_CLASS(guestfs_session_parent_class)->finalize(object);
}

static void
guestfs_session_class_init(GuestfsSessionClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);

  object_class->finalize = guestfs_session_finalize;

  g_type_class_add_private(klass, sizeof(GuestfsSessionPrivate));
}

static void
guestfs_session_init(GuestfsSession *session)
{
  session->priv = GUESTFS_SESSION_GET_PRIVATE(session);

  session->priv->g = guestfs_create();
}

/**
 * guestfs_session_new:
 *
 * Create a new libguestfs session.
 *
 * Returns: (transfer full): a new guestfs session object
 */
GuestfsSession *
guestfs_session_new(void)
{
  return GUESTFS_SESSION(g_object_new(GUESTFS_TYPE_SESSION, NULL));
}

/* Structs */
static GuestfsVersion *
guestfs_version_copy(GuestfsVersion *src)
{
  return g_slice_dup(GuestfsVersion, src);
}

static void
guestfs_version_free(GuestfsVersion *src)
{
  g_slice_free(GuestfsVersion, src);
}

G_DEFINE_BOXED_TYPE(GuestfsVersion, guestfs_version,
                    guestfs_version_copy, guestfs_version_free)

/* Generated methods */

/**
 * guestfs_session_add_drive:
 *
 * add an image to examine or modify
 *
 * This function is the equivalent of calling C<guestfs_add_drive_opts>
 * with no optional parameters, so the disk is added writable, with
 * the format being detected automatically.
 *
 * Automatic detection of the format opens you up to a potential
 * security hole when dealing with untrusted raw-format images.
 * See CVE-2010-3851 and RHBZ#642934.  Specifying the format closes
 * this security hole.  Therefore you should think about replacing
 * calls to this function with calls to C<guestfs_add_drive_opts>,
 * and specifying the format.
 *
 * @filename: (transfer none):
 *
 * Returns: true on success, false on failure
 */
gboolean
guestfs_session_add_drive(GuestfsSession *session, gchar *filename,
                                   GError **err)
{
  guestfs_h *g = session->priv->g;
  if (guestfs_add_drive(g, filename) == 0) return TRUE;

  g_set_error_literal(err, GUESTFS_SESSION_ERROR, 0, guestfs_last_error(g));
  return FALSE;
}

/**
 * guestfs_launch:
 *
 * launch the qemu subprocess
 *
 * Internally libguestfs is implemented by running a virtual machine
 * using L<qemu(1)>.
 *
 * You should call this after configuring the handle
 * (eg. adding drives) but before performing any actions.
 *
 * Returns: true on success, false on failure
 */
gboolean
guestfs_session_launch(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  if (guestfs_launch(g) == 0) return TRUE;

  g_set_error_literal(err, GUESTFS_SESSION_ERROR, 0, guestfs_last_error(g));
  return FALSE;
}

/**
 * guestfs_session_version:
 *
 * get the library version number
 *
 * Return the libguestfs version number that the program is linked
 * against.
 *
 * Note that because of dynamic linking this is not necessarily
 * the version of libguestfs that you compiled against.  You can
 * compile the program, and then at runtime dynamically link
 * against a completely different C<libguestfs.so> library.
 *
 * This call was added in version C<1.0.58>.  In previous
 * versions of libguestfs there was no way to get the version
 * number.  From C code you can use dynamic linker functions
 * to find out if this symbol exists (if it doesn't, then
 * it's an earlier version).
 *
 * The call returns a structure with four elements.  The first
 * three (C<major>, C<minor> and C<release>) are numbers and
 * correspond to the usual version triplet.  The fourth element
 * (C<extra>) is a string and is normally empty, but may be
 * used for distro-specific information.
 *
 * To construct the original version string:
 * C<$major.$minor.$release$extra>
 *
 * See also: L<guestfs(3)/LIBGUESTFS VERSION NUMBERS>.
 *
 * I<Note:> Don't use this call to test for availability
 * of features.  In enterprise distributions we backport
 * features from later versions into earlier versions,
 * making this an unreliable way to test for features.
 * Use C<guestfs_available> instead.
 *
 * Returns: (transfer full):
 */
GuestfsVersion *
guestfs_session_version(GuestfsSession *session, GError **err)
{
  guestfs_h *g = session->priv->g;
  struct guestfs_version *v = guestfs_version(g);
  if (v == NULL) {
    g_set_error_literal(err, GUESTFS_SESSION_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsVersion *ret = g_slice_new(GuestfsVersion);
  ret->major = v->major;
  ret->minor = v->minor;
  ret->release = v->release;
  ret->extra = strdup(v->extra);

  guestfs_free_version(v);

  return ret;
}
