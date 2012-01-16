/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2012 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#ifndef GUESTFS_GOBJECT_H__
#define GUESTFS_GOBJECT_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* Guestfs::Session object definition */
#define GUESTFS_TYPE_SESSION             (guestfs_session_get_type())
#define GUESTFS_SESSION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ( (obj), GUESTFS_TYPE_SESSION, GuestfsSession))
#define GUESTFS_SESSION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ( (klass), GUESTFS_TYPE_SESSION, GuestfsSessionClass))
#define GUESTFS_IS_SESSION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ( (obj), GUESTFS_TYPE_SESSION))
#define GUESTFS_IS_SESSION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ( (klass), GUESTFS_TYPE_SESSION))
#define GUESTFS_SESSION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ( (obj), GUESTFS_TYPE_SESSION, GuestfsSessionClass))

typedef struct _GuestfsSession GuestfsSession;
typedef struct _GuestfsSessionClass GuestfsSessionClass;
typedef struct _GuestfsSessionPrivate GuestfsSessionPrivate;

struct _GuestfsSession
{
  GObject parent;
  GuestfsSessionPrivate *priv;
};

struct _GuestfsSessionClass
{
  GObjectClass parent_class;
};

GType guestfs_session_get_type(void);
GuestfsSession *guestfs_session_new(void);

/* Guestfs::Tristate */
typedef enum
{
  GUESTFS_TRISTATE_FALSE,
  GUESTFS_TRISTATE_TRUE,
  GUESTFS_TRISTATE_NONE
} GuestfsTristate;

GType guestfs_tristate_get_type(void);
#define GUESTFS_TYPE_TRISTATE (guestfs_tristate_get_type())

/* Structs */
typedef struct _GuestfsIntBool GuestfsIntBool;
struct _GuestfsIntBool {
  gint32 i;
  gint32 b;
};
GType guestfs_int_bool_get_type(void);

typedef struct _GuestfsPV GuestfsPV;
struct _GuestfsPV {
  gchar *pv_name;
  /* The next field is NOT nul-terminated, be careful when printing it: */
  gchar pv_uuid[32];
  gchar *pv_fmt;
  guint64 pv_size;
  guint64 dev_size;
  guint64 pv_free;
  guint64 pv_used;
  gchar *pv_attr;
  gint64 pv_pe_count;
  gint64 pv_pe_alloc_count;
  gchar *pv_tags;
  guint64 pe_start;
  gint64 pv_mda_count;
  guint64 pv_mda_free;
};
GType guestfs_lvm_pv_get_type(void);

typedef struct _GuestfsVG GuestfsVG;
struct _GuestfsVG {
  gchar *vg_name;
  /* The next field is NOT nul-terminated, be careful when printing it: */
  gchar vg_uuid[32];
  gchar *vg_fmt;
  gchar *vg_attr;
  guint64 vg_size;
  guint64 vg_free;
  gchar *vg_sysid;
  guint64 vg_extent_size;
  gint64 vg_extent_count;
  gint64 vg_free_count;
  gint64 max_lv;
  gint64 max_pv;
  gint64 pv_count;
  gint64 lv_count;
  gint64 snap_count;
  gint64 vg_seqno;
  gchar *vg_tags;
  gint64 vg_mda_count;
  guint64 vg_mda_free;
};
GType guestfs_lvm_vg_get_type(void);

typedef struct _GuestfsLV GuestfsLV;
struct _GuestfsLV {
  gchar *lv_name;
  /* The next field is NOT nul-terminated, be careful when printing it: */
  gchar lv_uuid[32];
  gchar *lv_attr;
  gint64 lv_major;
  gint64 lv_minor;
  gint64 lv_kernel_major;
  gint64 lv_kernel_minor;
  guint64 lv_size;
  gint64 seg_count;
  gchar *origin;
  /* The next field is [0..100] or -1 meaning 'not present': */
  gfloat snap_percent;
  /* The next field is [0..100] or -1 meaning 'not present': */
  gfloat copy_percent;
  gchar *move_pv;
  gchar *lv_tags;
  gchar *mirror_log;
  gchar *modules;
};
GType guestfs_lvm_lv_get_type(void);

typedef struct _GuestfsStat GuestfsStat;
struct _GuestfsStat {
  gint64 dev;
  gint64 ino;
  gint64 mode;
  gint64 nlink;
  gint64 uid;
  gint64 gid;
  gint64 rdev;
  gint64 size;
  gint64 blksize;
  gint64 blocks;
  gint64 atime;
  gint64 mtime;
  gint64 ctime;
};
GType guestfs_stat_get_type(void);

typedef struct _GuestfsStatVFS GuestfsStatVFS;
struct _GuestfsStatVFS {
  gint64 bsize;
  gint64 frsize;
  gint64 blocks;
  gint64 bfree;
  gint64 bavail;
  gint64 files;
  gint64 ffree;
  gint64 favail;
  gint64 fsid;
  gint64 flag;
  gint64 namemax;
};
GType guestfs_statvfs_get_type(void);

typedef struct _GuestfsDirent GuestfsDirent;
struct _GuestfsDirent {
  gint64 ino;
  gchar ftyp;
  gchar *name;
};
GType guestfs_dirent_get_type(void);

typedef struct _GuestfsVersion GuestfsVersion;
struct _GuestfsVersion {
  gint64 major;
  gint64 minor;
  gint64 release;
  gchar *extra;
};
GType guestfs_version_get_type(void);

typedef struct _GuestfsXAttr GuestfsXAttr;
struct _GuestfsXAttr {
  gchar *attrname;
  guint8 *attrval;
  guint32 attrval_size;
};
GType guestfs_xattr_get_type(void);

typedef struct _GuestfsINotifyEvent GuestfsINotifyEvent;
struct _GuestfsINotifyEvent {
  gint64 in_wd;
  guint32 in_mask;
  guint32 in_cookie;
  gchar *in_name;
};
GType guestfs_inotify_event_get_type(void);

typedef struct _GuestfsPartition GuestfsPartition;
struct _GuestfsPartition {
  gint32 part_num;
  guint64 part_start;
  guint64 part_end;
  guint64 part_size;
};
GType guestfs_partition_get_type(void);

typedef struct _GuestfsApplication GuestfsApplication;
struct _GuestfsApplication {
  gchar *app_name;
  gchar *app_display_name;
  gint32 app_epoch;
  gchar *app_version;
  gchar *app_release;
  gchar *app_install_path;
  gchar *app_trans_path;
  gchar *app_publisher;
  gchar *app_url;
  gchar *app_source_package;
  gchar *app_summary;
  gchar *app_description;
};
GType guestfs_application_get_type(void);

/* Optional arguments */

/* GuestfsAddDriveOpts */
#define GUESTFS_TYPE_ADD_DRIVE_OPTS (guestfs_add_drive_opts_get_type())
#define GUESTFS_ADD_DRIVE_OPTS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_ADD_DRIVE_OPTS, GuestfsAddDriveOpts))
#define GUESTFS_ADD_DRIVE_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_ADD_DRIVE_OPTS, GuestfsAddDriveOptsClass))
#define GUESTFS_IS_ADD_DRIVE_OPTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_ADD_DRIVE_OPTS))
#define GUESTFS_IS_ADD_DRIVE_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_ADD_DRIVE_OPTS))
#define GUESTFS_ADD_DRIVE_OPTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_ADD_DRIVE_OPTS, GuestfsAddDriveOptsClass))

typedef struct _GuestfsAddDriveOpts GuestfsAddDriveOpts;
typedef struct _GuestfsAddDriveOptsPrivate GuestfsAddDriveOptsPrivate;
typedef struct _GuestfsAddDriveOptsClass GuestfsAddDriveOptsClass;

struct _GuestfsAddDriveOpts {
  GObject parent;
  GuestfsAddDriveOptsPrivate *priv;
};

struct _GuestfsAddDriveOptsClass {
  GObjectClass parent_class;
};

GType guestfs_add_drive_opts_get_type(void);
GuestfsAddDriveOpts *guestfs_add_drive_opts_new(void);

/* GuestfsAddDomain */
#define GUESTFS_TYPE_ADD_DOMAIN (guestfs_add_domain_get_type())
#define GUESTFS_ADD_DOMAIN(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_ADD_DOMAIN, GuestfsAddDomain))
#define GUESTFS_ADD_DOMAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_ADD_DOMAIN, GuestfsAddDomainClass))
#define GUESTFS_IS_ADD_DOMAIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_ADD_DOMAIN))
#define GUESTFS_IS_ADD_DOMAIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_ADD_DOMAIN))
#define GUESTFS_ADD_DOMAIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_ADD_DOMAIN, GuestfsAddDomainClass))

typedef struct _GuestfsAddDomain GuestfsAddDomain;
typedef struct _GuestfsAddDomainPrivate GuestfsAddDomainPrivate;
typedef struct _GuestfsAddDomainClass GuestfsAddDomainClass;

struct _GuestfsAddDomain {
  GObject parent;
  GuestfsAddDomainPrivate *priv;
};

struct _GuestfsAddDomainClass {
  GObjectClass parent_class;
};

GType guestfs_add_domain_get_type(void);
GuestfsAddDomain *guestfs_add_domain_new(void);

/* GuestfsInspectGetIcon */
#define GUESTFS_TYPE_INSPECT_GET_ICON (guestfs_inspect_get_icon_get_type())
#define GUESTFS_INSPECT_GET_ICON(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_INSPECT_GET_ICON, GuestfsInspectGetIcon))
#define GUESTFS_INSPECT_GET_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_INSPECT_GET_ICON, GuestfsInspectGetIconClass))
#define GUESTFS_IS_INSPECT_GET_ICON(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_INSPECT_GET_ICON))
#define GUESTFS_IS_INSPECT_GET_ICON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_INSPECT_GET_ICON))
#define GUESTFS_INSPECT_GET_ICON_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_INSPECT_GET_ICON, GuestfsInspectGetIconClass))

typedef struct _GuestfsInspectGetIcon GuestfsInspectGetIcon;
typedef struct _GuestfsInspectGetIconPrivate GuestfsInspectGetIconPrivate;
typedef struct _GuestfsInspectGetIconClass GuestfsInspectGetIconClass;

struct _GuestfsInspectGetIcon {
  GObject parent;
  GuestfsInspectGetIconPrivate *priv;
};

struct _GuestfsInspectGetIconClass {
  GObjectClass parent_class;
};

GType guestfs_inspect_get_icon_get_type(void);
GuestfsInspectGetIcon *guestfs_inspect_get_icon_new(void);

/* GuestfsMkfsOpts */
#define GUESTFS_TYPE_MKFS_OPTS (guestfs_mkfs_opts_get_type())
#define GUESTFS_MKFS_OPTS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_MKFS_OPTS, GuestfsMkfsOpts))
#define GUESTFS_MKFS_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_MKFS_OPTS, GuestfsMkfsOptsClass))
#define GUESTFS_IS_MKFS_OPTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_MKFS_OPTS))
#define GUESTFS_IS_MKFS_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_MKFS_OPTS))
#define GUESTFS_MKFS_OPTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_MKFS_OPTS, GuestfsMkfsOptsClass))

typedef struct _GuestfsMkfsOpts GuestfsMkfsOpts;
typedef struct _GuestfsMkfsOptsPrivate GuestfsMkfsOptsPrivate;
typedef struct _GuestfsMkfsOptsClass GuestfsMkfsOptsClass;

struct _GuestfsMkfsOpts {
  GObject parent;
  GuestfsMkfsOptsPrivate *priv;
};

struct _GuestfsMkfsOptsClass {
  GObjectClass parent_class;
};

GType guestfs_mkfs_opts_get_type(void);
GuestfsMkfsOpts *guestfs_mkfs_opts_new(void);

/* GuestfsMount9P */
#define GUESTFS_TYPE_MOUNT_9P (guestfs_mount_9p_get_type())
#define GUESTFS_MOUNT_9P(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9P))
#define GUESTFS_MOUNT_9P_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9PClass))
#define GUESTFS_IS_MOUNT_9P(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_MOUNT_9P))
#define GUESTFS_IS_MOUNT_9P_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_MOUNT_9P))
#define GUESTFS_MOUNT_9P_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9PClass))

typedef struct _GuestfsMount9P GuestfsMount9P;
typedef struct _GuestfsMount9PPrivate GuestfsMount9PPrivate;
typedef struct _GuestfsMount9PClass GuestfsMount9PClass;

struct _GuestfsMount9P {
  GObject parent;
  GuestfsMount9PPrivate *priv;
};

struct _GuestfsMount9PClass {
  GObjectClass parent_class;
};

GType guestfs_mount_9p_get_type(void);
GuestfsMount9P *guestfs_mount_9p_new(void);

/* GuestfsNTFSResizeOpts */
#define GUESTFS_TYPE_NTFSRESIZE_OPTS (guestfs_ntfsresize_opts_get_type())
#define GUESTFS_NTFSRESIZE_OPTS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOpts))
#define GUESTFS_NTFSRESIZE_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOptsClass))
#define GUESTFS_IS_NTFSRESIZE_OPTS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_NTFSRESIZE_OPTS))
#define GUESTFS_IS_NTFSRESIZE_OPTS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_NTFSRESIZE_OPTS))
#define GUESTFS_NTFSRESIZE_OPTS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOptsClass))

typedef struct _GuestfsNTFSResizeOpts GuestfsNTFSResizeOpts;
typedef struct _GuestfsNTFSResizeOptsPrivate GuestfsNTFSResizeOptsPrivate;
typedef struct _GuestfsNTFSResizeOptsClass GuestfsNTFSResizeOptsClass;

struct _GuestfsNTFSResizeOpts {
  GObject parent;
  GuestfsNTFSResizeOptsPrivate *priv;
};

struct _GuestfsNTFSResizeOptsClass {
  GObjectClass parent_class;
};

GType guestfs_ntfsresize_opts_get_type(void);
GuestfsNTFSResizeOpts *guestfs_ntfsresize_opts_new(void);

/* GuestfsBTRFSFilesystemResize */
#define GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE (guestfs_btrfs_filesystem_resize_get_type())
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE, GuestfsBTRFSFilesystemResize))
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE, GuestfsBTRFSFilesystemResizeClass))
#define GUESTFS_IS_BTRFS_FILESYSTEM_RESIZE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE))
#define GUESTFS_IS_BTRFS_FILESYSTEM_RESIZE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE))
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE, GuestfsBTRFSFilesystemResizeClass))

typedef struct _GuestfsBTRFSFilesystemResize GuestfsBTRFSFilesystemResize;
typedef struct _GuestfsBTRFSFilesystemResizePrivate GuestfsBTRFSFilesystemResizePrivate;
typedef struct _GuestfsBTRFSFilesystemResizeClass GuestfsBTRFSFilesystemResizeClass;

struct _GuestfsBTRFSFilesystemResize {
  GObject parent;
  GuestfsBTRFSFilesystemResizePrivate *priv;
};

struct _GuestfsBTRFSFilesystemResizeClass {
  GObjectClass parent_class;
};

GType guestfs_btrfs_filesystem_resize_get_type(void);
GuestfsBTRFSFilesystemResize *guestfs_btrfs_filesystem_resize_new(void);

/* GuestfsCompressOut */
#define GUESTFS_TYPE_COMPRESS_OUT (guestfs_compress_out_get_type())
#define GUESTFS_COMPRESS_OUT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_COMPRESS_OUT, GuestfsCompressOut))
#define GUESTFS_COMPRESS_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_COMPRESS_OUT, GuestfsCompressOutClass))
#define GUESTFS_IS_COMPRESS_OUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_COMPRESS_OUT))
#define GUESTFS_IS_COMPRESS_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_COMPRESS_OUT))
#define GUESTFS_COMPRESS_OUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_COMPRESS_OUT, GuestfsCompressOutClass))

typedef struct _GuestfsCompressOut GuestfsCompressOut;
typedef struct _GuestfsCompressOutPrivate GuestfsCompressOutPrivate;
typedef struct _GuestfsCompressOutClass GuestfsCompressOutClass;

struct _GuestfsCompressOut {
  GObject parent;
  GuestfsCompressOutPrivate *priv;
};

struct _GuestfsCompressOutClass {
  GObjectClass parent_class;
};

GType guestfs_compress_out_get_type(void);
GuestfsCompressOut *guestfs_compress_out_new(void);

/* GuestfsCompressDeviceOut */
#define GUESTFS_TYPE_COMPRESS_DEVICE_OUT (guestfs_compress_device_out_get_type())
#define GUESTFS_COMPRESS_DEVICE_OUT(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_COMPRESS_DEVICE_OUT, GuestfsCompressDeviceOut))
#define GUESTFS_COMPRESS_DEVICE_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_COMPRESS_DEVICE_OUT, GuestfsCompressDeviceOutClass))
#define GUESTFS_IS_COMPRESS_DEVICE_OUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_COMPRESS_DEVICE_OUT))
#define GUESTFS_IS_COMPRESS_DEVICE_OUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_COMPRESS_DEVICE_OUT))
#define GUESTFS_COMPRESS_DEVICE_OUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_COMPRESS_DEVICE_OUT, GuestfsCompressDeviceOutClass))

typedef struct _GuestfsCompressDeviceOut GuestfsCompressDeviceOut;
typedef struct _GuestfsCompressDeviceOutPrivate GuestfsCompressDeviceOutPrivate;
typedef struct _GuestfsCompressDeviceOutClass GuestfsCompressDeviceOutClass;

struct _GuestfsCompressDeviceOut {
  GObject parent;
  GuestfsCompressDeviceOutPrivate *priv;
};

struct _GuestfsCompressDeviceOutClass {
  GObjectClass parent_class;
};

GType guestfs_compress_device_out_get_type(void);
GuestfsCompressDeviceOut *guestfs_compress_device_out_new(void);

/* GuestfsCopyDeviceToDevice */
#define GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE (guestfs_copy_device_to_device_get_type())
#define GUESTFS_COPY_DEVICE_TO_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDevice))
#define GUESTFS_COPY_DEVICE_TO_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDeviceClass))
#define GUESTFS_IS_COPY_DEVICE_TO_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE))
#define GUESTFS_IS_COPY_DEVICE_TO_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE))
#define GUESTFS_COPY_DEVICE_TO_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDeviceClass))

typedef struct _GuestfsCopyDeviceToDevice GuestfsCopyDeviceToDevice;
typedef struct _GuestfsCopyDeviceToDevicePrivate GuestfsCopyDeviceToDevicePrivate;
typedef struct _GuestfsCopyDeviceToDeviceClass GuestfsCopyDeviceToDeviceClass;

struct _GuestfsCopyDeviceToDevice {
  GObject parent;
  GuestfsCopyDeviceToDevicePrivate *priv;
};

struct _GuestfsCopyDeviceToDeviceClass {
  GObjectClass parent_class;
};

GType guestfs_copy_device_to_device_get_type(void);
GuestfsCopyDeviceToDevice *guestfs_copy_device_to_device_new(void);

/* GuestfsCopyDeviceToFile */
#define GUESTFS_TYPE_COPY_DEVICE_TO_FILE (guestfs_copy_device_to_file_get_type())
#define GUESTFS_COPY_DEVICE_TO_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_COPY_DEVICE_TO_FILE, GuestfsCopyDeviceToFile))
#define GUESTFS_COPY_DEVICE_TO_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_COPY_DEVICE_TO_FILE, GuestfsCopyDeviceToFileClass))
#define GUESTFS_IS_COPY_DEVICE_TO_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_COPY_DEVICE_TO_FILE))
#define GUESTFS_IS_COPY_DEVICE_TO_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_COPY_DEVICE_TO_FILE))
#define GUESTFS_COPY_DEVICE_TO_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_COPY_DEVICE_TO_FILE, GuestfsCopyDeviceToFileClass))

typedef struct _GuestfsCopyDeviceToFile GuestfsCopyDeviceToFile;
typedef struct _GuestfsCopyDeviceToFilePrivate GuestfsCopyDeviceToFilePrivate;
typedef struct _GuestfsCopyDeviceToFileClass GuestfsCopyDeviceToFileClass;

struct _GuestfsCopyDeviceToFile {
  GObject parent;
  GuestfsCopyDeviceToFilePrivate *priv;
};

struct _GuestfsCopyDeviceToFileClass {
  GObjectClass parent_class;
};

GType guestfs_copy_device_to_file_get_type(void);
GuestfsCopyDeviceToFile *guestfs_copy_device_to_file_new(void);

/* GuestfsCopyFileToDevice */
#define GUESTFS_TYPE_COPY_FILE_TO_DEVICE (guestfs_copy_file_to_device_get_type())
#define GUESTFS_COPY_FILE_TO_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_COPY_FILE_TO_DEVICE, GuestfsCopyFileToDevice))
#define GUESTFS_COPY_FILE_TO_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_COPY_FILE_TO_DEVICE, GuestfsCopyFileToDeviceClass))
#define GUESTFS_IS_COPY_FILE_TO_DEVICE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_COPY_FILE_TO_DEVICE))
#define GUESTFS_IS_COPY_FILE_TO_DEVICE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_COPY_FILE_TO_DEVICE))
#define GUESTFS_COPY_FILE_TO_DEVICE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_COPY_FILE_TO_DEVICE, GuestfsCopyFileToDeviceClass))

typedef struct _GuestfsCopyFileToDevice GuestfsCopyFileToDevice;
typedef struct _GuestfsCopyFileToDevicePrivate GuestfsCopyFileToDevicePrivate;
typedef struct _GuestfsCopyFileToDeviceClass GuestfsCopyFileToDeviceClass;

struct _GuestfsCopyFileToDevice {
  GObject parent;
  GuestfsCopyFileToDevicePrivate *priv;
};

struct _GuestfsCopyFileToDeviceClass {
  GObjectClass parent_class;
};

GType guestfs_copy_file_to_device_get_type(void);
GuestfsCopyFileToDevice *guestfs_copy_file_to_device_new(void);

/* GuestfsCopyFileToFile */
#define GUESTFS_TYPE_COPY_FILE_TO_FILE (guestfs_copy_file_to_file_get_type())
#define GUESTFS_COPY_FILE_TO_FILE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_COPY_FILE_TO_FILE, GuestfsCopyFileToFile))
#define GUESTFS_COPY_FILE_TO_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_COPY_FILE_TO_FILE, GuestfsCopyFileToFileClass))
#define GUESTFS_IS_COPY_FILE_TO_FILE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_COPY_FILE_TO_FILE))
#define GUESTFS_IS_COPY_FILE_TO_FILE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_COPY_FILE_TO_FILE))
#define GUESTFS_COPY_FILE_TO_FILE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_COPY_FILE_TO_FILE, GuestfsCopyFileToFileClass))

typedef struct _GuestfsCopyFileToFile GuestfsCopyFileToFile;
typedef struct _GuestfsCopyFileToFilePrivate GuestfsCopyFileToFilePrivate;
typedef struct _GuestfsCopyFileToFileClass GuestfsCopyFileToFileClass;

struct _GuestfsCopyFileToFile {
  GObject parent;
  GuestfsCopyFileToFilePrivate *priv;
};

struct _GuestfsCopyFileToFileClass {
  GObjectClass parent_class;
};

GType guestfs_copy_file_to_file_get_type(void);
GuestfsCopyFileToFile *guestfs_copy_file_to_file_new(void);

/* GuestfsTune2FS */
#define GUESTFS_TYPE_TUNE2FS (guestfs_tune2fs_get_type())
#define GUESTFS_TUNE2FS(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FS))
#define GUESTFS_TUNE2FS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FSClass))
#define GUESTFS_IS_TUNE2FS(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_TUNE2FS))
#define GUESTFS_IS_TUNE2FS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_TUNE2FS))
#define GUESTFS_TUNE2FS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FSClass))

typedef struct _GuestfsTune2FS GuestfsTune2FS;
typedef struct _GuestfsTune2FSPrivate GuestfsTune2FSPrivate;
typedef struct _GuestfsTune2FSClass GuestfsTune2FSClass;

struct _GuestfsTune2FS {
  GObject parent;
  GuestfsTune2FSPrivate *priv;
};

struct _GuestfsTune2FSClass {
  GObjectClass parent_class;
};

GType guestfs_tune2fs_get_type(void);
GuestfsTune2FS *guestfs_tune2fs_new(void);

/* GuestfsMDCreate */
#define GUESTFS_TYPE_MD_CREATE (guestfs_md_create_get_type())
#define GUESTFS_MD_CREATE(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj), GUESTFS_TYPE_MD_CREATE, GuestfsMDCreate))
#define GUESTFS_MD_CREATE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), GUESTFS_TYPE_MD_CREATE, GuestfsMDCreateClass))
#define GUESTFS_IS_MD_CREATE(obj) (G_TYPE_CHECK_INSTANCE_TYPE((klass), GUESTFS_TYPE_MD_CREATE))
#define GUESTFS_IS_MD_CREATE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), GUESTFS_TYPE_MD_CREATE))
#define GUESTFS_MD_CREATE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj), GUESTFS_TYPE_MD_CREATE, GuestfsMDCreateClass))

typedef struct _GuestfsMDCreate GuestfsMDCreate;
typedef struct _GuestfsMDCreatePrivate GuestfsMDCreatePrivate;
typedef struct _GuestfsMDCreateClass GuestfsMDCreateClass;

struct _GuestfsMDCreate {
  GObject parent;
  GuestfsMDCreatePrivate *priv;
};

struct _GuestfsMDCreateClass {
  GObjectClass parent_class;
};

GType guestfs_md_create_get_type(void);
GuestfsMDCreate *guestfs_md_create_new(void);

/* Generated methods */
gboolean guestfs_session_test0(GuestfsSession *session, const gchar *str, const gchar *optstr, const gchar **strlist, gboolean b, gint32 integer, gint64 integer64, const gchar *filein, const gchar *fileout, const guint8 *bufferin, gsize bufferin_size, GError **err);
gint32 guestfs_session_test0rint(GuestfsSession *session, const gchar *val, GError **err);
gint32 guestfs_session_test0rinterr(GuestfsSession *session, GError **err);
gint64 guestfs_session_test0rint64(GuestfsSession *session, const gchar *val, GError **err);
gint64 guestfs_session_test0rint64err(GuestfsSession *session, GError **err);
gint8 guestfs_session_test0rbool(GuestfsSession *session, const gchar *val, GError **err);
gint8 guestfs_session_test0rboolerr(GuestfsSession *session, GError **err);
gchar *guestfs_session_test0rconststring(GuestfsSession *session, const gchar *val, GError **err);
gchar *guestfs_session_test0rconststringerr(GuestfsSession *session, GError **err);
gchar *guestfs_session_test0rconstoptstring(GuestfsSession *session, const gchar *val);
gchar *guestfs_session_test0rconstoptstringerr(GuestfsSession *session);
gchar *guestfs_session_test0rstring(GuestfsSession *session, const gchar *val, GError **err);
gchar *guestfs_session_test0rstringerr(GuestfsSession *session, GError **err);
gchar **guestfs_session_test0rstringlist(GuestfsSession *session, const gchar *val, GError **err);
gchar **guestfs_session_test0rstringlisterr(GuestfsSession *session, GError **err);
GuestfsPV *guestfs_session_test0rstruct(GuestfsSession *session, const gchar *val, GError **err);
GuestfsPV *guestfs_session_test0rstructerr(GuestfsSession *session, GError **err);
GuestfsPV **guestfs_session_test0rstructlist(GuestfsSession *session, const gchar *val, GError **err);
GuestfsPV **guestfs_session_test0rstructlisterr(GuestfsSession *session, GError **err);
GHashTable *guestfs_session_test0rhashtable(GuestfsSession *session, const gchar *val, GError **err);
GHashTable *guestfs_session_test0rhashtableerr(GuestfsSession *session, GError **err);
gboolean guestfs_session_launch(GuestfsSession *session, GError **err);
gboolean guestfs_session_wait_ready(GuestfsSession *session, GError **err);
gboolean guestfs_session_kill_subprocess(GuestfsSession *session, GError **err);
gboolean guestfs_session_add_drive(GuestfsSession *session, const gchar *filename, GError **err);
gboolean guestfs_session_add_cdrom(GuestfsSession *session, const gchar *filename, GError **err);
gboolean guestfs_session_add_drive_ro(GuestfsSession *session, const gchar *filename, GError **err);
gboolean guestfs_session_config(GuestfsSession *session, const gchar *qemuparam, const gchar *qemuvalue, GError **err);
gboolean guestfs_session_set_qemu(GuestfsSession *session, const gchar *qemu, GError **err);
gchar *guestfs_session_get_qemu(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_path(GuestfsSession *session, const gchar *searchpath, GError **err);
gchar *guestfs_session_get_path(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_append(GuestfsSession *session, const gchar *append, GError **err);
gchar *guestfs_session_get_append(GuestfsSession *session);
gboolean guestfs_session_set_autosync(GuestfsSession *session, gboolean autosync, GError **err);
gint8 guestfs_session_get_autosync(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_verbose(GuestfsSession *session, gboolean verbose, GError **err);
gint8 guestfs_session_get_verbose(GuestfsSession *session, GError **err);
gint8 guestfs_session_is_ready(GuestfsSession *session, GError **err);
gint8 guestfs_session_is_config(GuestfsSession *session, GError **err);
gint8 guestfs_session_is_launching(GuestfsSession *session, GError **err);
gint8 guestfs_session_is_busy(GuestfsSession *session, GError **err);
gint32 guestfs_session_get_state(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_memsize(GuestfsSession *session, gint32 memsize, GError **err);
gint32 guestfs_session_get_memsize(GuestfsSession *session, GError **err);
gint32 guestfs_session_get_pid(GuestfsSession *session, GError **err);
GuestfsVersion *guestfs_session_version(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_selinux(GuestfsSession *session, gboolean selinux, GError **err);
gint8 guestfs_session_get_selinux(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_trace(GuestfsSession *session, gboolean trace, GError **err);
gint8 guestfs_session_get_trace(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_direct(GuestfsSession *session, gboolean direct, GError **err);
gint8 guestfs_session_get_direct(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_recovery_proc(GuestfsSession *session, gboolean recoveryproc, GError **err);
gint8 guestfs_session_get_recovery_proc(GuestfsSession *session, GError **err);
gboolean guestfs_session_add_drive_with_if(GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err);
gboolean guestfs_session_add_drive_ro_with_if(GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err);
gchar *guestfs_session_file_architecture(GuestfsSession *session, const gchar *filename, GError **err);
gchar **guestfs_session_inspect_os(GuestfsSession *session, GError **err);
gchar *guestfs_session_inspect_get_type(GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_arch(GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_distro(GuestfsSession *session, const gchar *root, GError **err);
gint32 guestfs_session_inspect_get_major_version(GuestfsSession *session, const gchar *root, GError **err);
gint32 guestfs_session_inspect_get_minor_version(GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_product_name(GuestfsSession *session, const gchar *root, GError **err);
GHashTable *guestfs_session_inspect_get_mountpoints(GuestfsSession *session, const gchar *root, GError **err);
gchar **guestfs_session_inspect_get_filesystems(GuestfsSession *session, const gchar *root, GError **err);
gboolean guestfs_session_set_network(GuestfsSession *session, gboolean network, GError **err);
gint8 guestfs_session_get_network(GuestfsSession *session, GError **err);
GHashTable *guestfs_session_list_filesystems(GuestfsSession *session, GError **err);
gboolean guestfs_session_add_drive_opts(GuestfsSession *session, const gchar *filename, GuestfsAddDriveOpts *optargs, GError **err);
gchar *guestfs_session_inspect_get_windows_systemroot(GuestfsSession *session, const gchar *root, GError **err);
gchar **guestfs_session_inspect_get_roots(GuestfsSession *session, GError **err);
gchar **guestfs_session_debug_cmdline(GuestfsSession *session, GError **err);
gchar **guestfs_session_debug_drives(GuestfsSession *session, GError **err);
gint32 guestfs_session_add_domain(GuestfsSession *session, const gchar *dom, GuestfsAddDomain *optargs, GError **err);
gchar *guestfs_session_inspect_get_package_format(GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_package_management(GuestfsSession *session, const gchar *root, GError **err);
GuestfsApplication **guestfs_session_inspect_list_applications(GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_hostname(GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_format(GuestfsSession *session, const gchar *root, GError **err);
gint8 guestfs_session_inspect_is_live(GuestfsSession *session, const gchar *root, GError **err);
gint8 guestfs_session_inspect_is_netinst(GuestfsSession *session, const gchar *root, GError **err);
gint8 guestfs_session_inspect_is_multipart(GuestfsSession *session, const gchar *root, GError **err);
gboolean guestfs_session_set_attach_method(GuestfsSession *session, const gchar *attachmethod, GError **err);
gchar *guestfs_session_get_attach_method(GuestfsSession *session, GError **err);
gchar *guestfs_session_inspect_get_product_variant(GuestfsSession *session, const gchar *root, GError **err);
gchar *guestfs_session_inspect_get_windows_current_control_set(GuestfsSession *session, const gchar *root, GError **err);
GHashTable *guestfs_session_inspect_get_drive_mappings(GuestfsSession *session, const gchar *root, GError **err);
guint *guestfs_session_inspect_get_icon(GuestfsSession *session, const gchar *root, GuestfsInspectGetIcon *optargs, gsize *size_r, GError **err);
gboolean guestfs_session_set_pgroup(GuestfsSession *session, gboolean pgroup, GError **err);
gint8 guestfs_session_get_pgroup(GuestfsSession *session, GError **err);
gboolean guestfs_session_set_smp(GuestfsSession *session, gint32 smp, GError **err);
gint32 guestfs_session_get_smp(GuestfsSession *session, GError **err);
gboolean guestfs_session_mount(GuestfsSession *session, const gchar *device, const gchar *mountpoint, GError **err);
gboolean guestfs_session_sync(GuestfsSession *session, GError **err);
gboolean guestfs_session_touch(GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_cat(GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_ll(GuestfsSession *session, const gchar *directory, GError **err);
gchar **guestfs_session_ls(GuestfsSession *session, const gchar *directory, GError **err);
gchar **guestfs_session_list_devices(GuestfsSession *session, GError **err);
gchar **guestfs_session_list_partitions(GuestfsSession *session, GError **err);
gchar **guestfs_session_pvs(GuestfsSession *session, GError **err);
gchar **guestfs_session_vgs(GuestfsSession *session, GError **err);
gchar **guestfs_session_lvs(GuestfsSession *session, GError **err);
GuestfsPV **guestfs_session_pvs_full(GuestfsSession *session, GError **err);
GuestfsVG **guestfs_session_vgs_full(GuestfsSession *session, GError **err);
GuestfsLV **guestfs_session_lvs_full(GuestfsSession *session, GError **err);
gchar **guestfs_session_read_lines(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_aug_init(GuestfsSession *session, const gchar *root, gint32 flags, GError **err);
gboolean guestfs_session_aug_close(GuestfsSession *session, GError **err);
gint32 guestfs_session_aug_defvar(GuestfsSession *session, const gchar *name, const gchar *expr, GError **err);
GuestfsIntBool *guestfs_session_aug_defnode(GuestfsSession *session, const gchar *name, const gchar *expr, const gchar *val, GError **err);
gchar *guestfs_session_aug_get(GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_set(GuestfsSession *session, const gchar *augpath, const gchar *val, GError **err);
gboolean guestfs_session_aug_insert(GuestfsSession *session, const gchar *augpath, const gchar *label, gboolean before, GError **err);
gint32 guestfs_session_aug_rm(GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_mv(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gchar **guestfs_session_aug_match(GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_aug_save(GuestfsSession *session, GError **err);
gboolean guestfs_session_aug_load(GuestfsSession *session, GError **err);
gchar **guestfs_session_aug_ls(GuestfsSession *session, const gchar *augpath, GError **err);
gboolean guestfs_session_rm(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_rmdir(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_rm_rf(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_mkdir(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_mkdir_p(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_chmod(GuestfsSession *session, gint32 mode, const gchar *path, GError **err);
gboolean guestfs_session_chown(GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err);
gint8 guestfs_session_exists(GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_file(GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_dir(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_pvcreate(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_vgcreate(GuestfsSession *session, const gchar *volgroup, const gchar **physvols, GError **err);
gboolean guestfs_session_lvcreate(GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 mbytes, GError **err);
gboolean guestfs_session_mkfs(GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err);
gboolean guestfs_session_sfdisk(GuestfsSession *session, const gchar *device, gint32 cyls, gint32 heads, gint32 sectors, const gchar **lines, GError **err);
gboolean guestfs_session_write_file(GuestfsSession *session, const gchar *path, const gchar *content, gint32 size, GError **err);
gboolean guestfs_session_umount(GuestfsSession *session, const gchar *pathordevice, GError **err);
gchar **guestfs_session_mounts(GuestfsSession *session, GError **err);
gboolean guestfs_session_umount_all(GuestfsSession *session, GError **err);
gboolean guestfs_session_lvm_remove_all(GuestfsSession *session, GError **err);
gchar *guestfs_session_file(GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_command(GuestfsSession *session, const gchar **arguments, GError **err);
gchar **guestfs_session_command_lines(GuestfsSession *session, const gchar **arguments, GError **err);
GuestfsStat *guestfs_session_stat(GuestfsSession *session, const gchar *path, GError **err);
GuestfsStat *guestfs_session_lstat(GuestfsSession *session, const gchar *path, GError **err);
GuestfsStatVFS *guestfs_session_statvfs(GuestfsSession *session, const gchar *path, GError **err);
GHashTable *guestfs_session_tune2fs_l(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_setro(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_setrw(GuestfsSession *session, const gchar *device, GError **err);
gint8 guestfs_session_blockdev_getro(GuestfsSession *session, const gchar *device, GError **err);
gint32 guestfs_session_blockdev_getss(GuestfsSession *session, const gchar *device, GError **err);
gint32 guestfs_session_blockdev_getbsz(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_setbsz(GuestfsSession *session, const gchar *device, gint32 blocksize, GError **err);
gint64 guestfs_session_blockdev_getsz(GuestfsSession *session, const gchar *device, GError **err);
gint64 guestfs_session_blockdev_getsize64(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_flushbufs(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_blockdev_rereadpt(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_upload(GuestfsSession *session, const gchar *filename, const gchar *remotefilename, GError **err);
gboolean guestfs_session_download(GuestfsSession *session, const gchar *remotefilename, const gchar *filename, GError **err);
gchar *guestfs_session_checksum(GuestfsSession *session, const gchar *csumtype, const gchar *path, GError **err);
gboolean guestfs_session_tar_in(GuestfsSession *session, const gchar *tarfile, const gchar *directory, GError **err);
gboolean guestfs_session_tar_out(GuestfsSession *session, const gchar *directory, const gchar *tarfile, GError **err);
gboolean guestfs_session_tgz_in(GuestfsSession *session, const gchar *tarball, const gchar *directory, GError **err);
gboolean guestfs_session_tgz_out(GuestfsSession *session, const gchar *directory, const gchar *tarball, GError **err);
gboolean guestfs_session_mount_ro(GuestfsSession *session, const gchar *device, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mount_options(GuestfsSession *session, const gchar *options, const gchar *device, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mount_vfs(GuestfsSession *session, const gchar *options, const gchar *vfstype, const gchar *device, const gchar *mountpoint, GError **err);
gchar *guestfs_session_debug(GuestfsSession *session, const gchar *subcmd, const gchar **extraargs, GError **err);
gboolean guestfs_session_lvremove(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_vgremove(GuestfsSession *session, const gchar *vgname, GError **err);
gboolean guestfs_session_pvremove(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_set_e2label(GuestfsSession *session, const gchar *device, const gchar *label, GError **err);
gchar *guestfs_session_get_e2label(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_set_e2uuid(GuestfsSession *session, const gchar *device, const gchar *uuid, GError **err);
gchar *guestfs_session_get_e2uuid(GuestfsSession *session, const gchar *device, GError **err);
gint32 guestfs_session_fsck(GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err);
gboolean guestfs_session_zero(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_grub_install(GuestfsSession *session, const gchar *root, const gchar *device, GError **err);
gboolean guestfs_session_cp(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gboolean guestfs_session_cp_a(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gboolean guestfs_session_mv(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gboolean guestfs_session_drop_caches(GuestfsSession *session, gint32 whattodrop, GError **err);
gchar *guestfs_session_dmesg(GuestfsSession *session, GError **err);
gboolean guestfs_session_ping_daemon(GuestfsSession *session, GError **err);
gint8 guestfs_session_equal(GuestfsSession *session, const gchar *file1, const gchar *file2, GError **err);
gchar **guestfs_session_strings(GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_strings_e(GuestfsSession *session, const gchar *encoding, const gchar *path, GError **err);
gchar *guestfs_session_hexdump(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_zerofree(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_pvresize(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_sfdisk_N(GuestfsSession *session, const gchar *device, gint32 partnum, gint32 cyls, gint32 heads, gint32 sectors, const gchar *line, GError **err);
gchar *guestfs_session_sfdisk_l(GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_sfdisk_kernel_geometry(GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_sfdisk_disk_geometry(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_vg_activate_all(GuestfsSession *session, gboolean activate, GError **err);
gboolean guestfs_session_vg_activate(GuestfsSession *session, gboolean activate, const gchar **volgroups, GError **err);
gboolean guestfs_session_lvresize(GuestfsSession *session, const gchar *device, gint32 mbytes, GError **err);
gboolean guestfs_session_resize2fs(GuestfsSession *session, const gchar *device, GError **err);
gchar **guestfs_session_find(GuestfsSession *session, const gchar *directory, GError **err);
gboolean guestfs_session_e2fsck_f(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_sleep(GuestfsSession *session, gint32 secs, GError **err);
gint32 guestfs_session_ntfs_3g_probe(GuestfsSession *session, gboolean rw, const gchar *device, GError **err);
gchar *guestfs_session_sh(GuestfsSession *session, const gchar *command, GError **err);
gchar **guestfs_session_sh_lines(GuestfsSession *session, const gchar *command, GError **err);
gchar **guestfs_session_glob_expand(GuestfsSession *session, const gchar *pattern, GError **err);
gboolean guestfs_session_scrub_device(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_scrub_file(GuestfsSession *session, const gchar *file, GError **err);
gboolean guestfs_session_scrub_freespace(GuestfsSession *session, const gchar *dir, GError **err);
gchar *guestfs_session_mkdtemp(GuestfsSession *session, const gchar *template, GError **err);
gint32 guestfs_session_wc_l(GuestfsSession *session, const gchar *path, GError **err);
gint32 guestfs_session_wc_w(GuestfsSession *session, const gchar *path, GError **err);
gint32 guestfs_session_wc_c(GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_head(GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_head_n(GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err);
gchar **guestfs_session_tail(GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_tail_n(GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err);
gchar *guestfs_session_df(GuestfsSession *session, GError **err);
gchar *guestfs_session_df_h(GuestfsSession *session, GError **err);
gint64 guestfs_session_du(GuestfsSession *session, const gchar *path, GError **err);
gchar **guestfs_session_initrd_list(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_mount_loop(GuestfsSession *session, const gchar *file, const gchar *mountpoint, GError **err);
gboolean guestfs_session_mkswap(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_mkswap_L(GuestfsSession *session, const gchar *label, const gchar *device, GError **err);
gboolean guestfs_session_mkswap_U(GuestfsSession *session, const gchar *uuid, const gchar *device, GError **err);
gboolean guestfs_session_mknod(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err);
gboolean guestfs_session_mkfifo(GuestfsSession *session, gint32 mode, const gchar *path, GError **err);
gboolean guestfs_session_mknod_b(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err);
gboolean guestfs_session_mknod_c(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err);
gint32 guestfs_session_umask(GuestfsSession *session, gint32 mask, GError **err);
GuestfsDirent **guestfs_session_readdir(GuestfsSession *session, const gchar *dir, GError **err);
gboolean guestfs_session_sfdiskM(GuestfsSession *session, const gchar *device, const gchar **lines, GError **err);
gchar *guestfs_session_zfile(GuestfsSession *session, const gchar *meth, const gchar *path, GError **err);
GuestfsXAttr **guestfs_session_getxattrs(GuestfsSession *session, const gchar *path, GError **err);
GuestfsXAttr **guestfs_session_lgetxattrs(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_setxattr(GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err);
gboolean guestfs_session_lsetxattr(GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err);
gboolean guestfs_session_removexattr(GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err);
gboolean guestfs_session_lremovexattr(GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err);
GHashTable *guestfs_session_mountpoints(GuestfsSession *session, GError **err);
gboolean guestfs_session_mkmountpoint(GuestfsSession *session, const gchar *exemptpath, GError **err);
gboolean guestfs_session_rmmountpoint(GuestfsSession *session, const gchar *exemptpath, GError **err);
guint *guestfs_session_read_file(GuestfsSession *session, const gchar *path, gsize *size_r, GError **err);
gchar **guestfs_session_grep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_egrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_fgrep(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar **guestfs_session_grepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_egrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_fgrepi(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar **guestfs_session_zgrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_zegrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_zfgrep(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar **guestfs_session_zgrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_zegrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err);
gchar **guestfs_session_zfgrepi(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err);
gchar *guestfs_session_realpath(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_ln(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gboolean guestfs_session_ln_f(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gboolean guestfs_session_ln_s(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gboolean guestfs_session_ln_sf(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err);
gchar *guestfs_session_readlink(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_fallocate(GuestfsSession *session, const gchar *path, gint32 len, GError **err);
gboolean guestfs_session_swapon_device(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_swapoff_device(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_swapon_file(GuestfsSession *session, const gchar *file, GError **err);
gboolean guestfs_session_swapoff_file(GuestfsSession *session, const gchar *file, GError **err);
gboolean guestfs_session_swapon_label(GuestfsSession *session, const gchar *label, GError **err);
gboolean guestfs_session_swapoff_label(GuestfsSession *session, const gchar *label, GError **err);
gboolean guestfs_session_swapon_uuid(GuestfsSession *session, const gchar *uuid, GError **err);
gboolean guestfs_session_swapoff_uuid(GuestfsSession *session, const gchar *uuid, GError **err);
gboolean guestfs_session_mkswap_file(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_inotify_init(GuestfsSession *session, gint32 maxevents, GError **err);
gint64 guestfs_session_inotify_add_watch(GuestfsSession *session, const gchar *path, gint32 mask, GError **err);
gboolean guestfs_session_inotify_rm_watch(GuestfsSession *session, gint32 wd, GError **err);
GuestfsINotifyEvent **guestfs_session_inotify_read(GuestfsSession *session, GError **err);
gchar **guestfs_session_inotify_files(GuestfsSession *session, GError **err);
gboolean guestfs_session_inotify_close(GuestfsSession *session, GError **err);
gboolean guestfs_session_setcon(GuestfsSession *session, const gchar *context, GError **err);
gchar *guestfs_session_getcon(GuestfsSession *session, GError **err);
gboolean guestfs_session_mkfs_b(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, GError **err);
gboolean guestfs_session_mke2journal(GuestfsSession *session, gint32 blocksize, const gchar *device, GError **err);
gboolean guestfs_session_mke2journal_L(GuestfsSession *session, gint32 blocksize, const gchar *label, const gchar *device, GError **err);
gboolean guestfs_session_mke2journal_U(GuestfsSession *session, gint32 blocksize, const gchar *uuid, const gchar *device, GError **err);
gboolean guestfs_session_mke2fs_J(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *journal, GError **err);
gboolean guestfs_session_mke2fs_JL(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *label, GError **err);
gboolean guestfs_session_mke2fs_JU(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *uuid, GError **err);
gboolean guestfs_session_modprobe(GuestfsSession *session, const gchar *modulename, GError **err);
gchar *guestfs_session_echo_daemon(GuestfsSession *session, const gchar **words, GError **err);
gboolean guestfs_session_find0(GuestfsSession *session, const gchar *directory, const gchar *files, GError **err);
gchar *guestfs_session_case_sensitive_path(GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_vfs_type(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_truncate(GuestfsSession *session, const gchar *path, GError **err);
gboolean guestfs_session_truncate_size(GuestfsSession *session, const gchar *path, gint64 size, GError **err);
gboolean guestfs_session_utimens(GuestfsSession *session, const gchar *path, gint64 atsecs, gint64 atnsecs, gint64 mtsecs, gint64 mtnsecs, GError **err);
gboolean guestfs_session_mkdir_mode(GuestfsSession *session, const gchar *path, gint32 mode, GError **err);
gboolean guestfs_session_lchown(GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err);
GuestfsStat **guestfs_session_lstatlist(GuestfsSession *session, const gchar *path, const gchar **names, GError **err);
GuestfsXAttr **guestfs_session_lxattrlist(GuestfsSession *session, const gchar *path, const gchar **names, GError **err);
gchar **guestfs_session_readlinklist(GuestfsSession *session, const gchar *path, const gchar **names, GError **err);
guint *guestfs_session_pread(GuestfsSession *session, const gchar *path, gint32 count, gint64 offset, gsize *size_r, GError **err);
gboolean guestfs_session_part_init(GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err);
gboolean guestfs_session_part_add(GuestfsSession *session, const gchar *device, const gchar *prlogex, gint64 startsect, gint64 endsect, GError **err);
gboolean guestfs_session_part_disk(GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err);
gboolean guestfs_session_part_set_bootable(GuestfsSession *session, const gchar *device, gint32 partnum, gboolean bootable, GError **err);
gboolean guestfs_session_part_set_name(GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *name, GError **err);
GuestfsPartition **guestfs_session_part_list(GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_part_get_parttype(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_fill(GuestfsSession *session, gint32 c, gint32 len, const gchar *path, GError **err);
gboolean guestfs_session_available(GuestfsSession *session, const gchar **groups, GError **err);
gboolean guestfs_session_dd(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err);
gint64 guestfs_session_filesize(GuestfsSession *session, const gchar *file, GError **err);
gboolean guestfs_session_lvrename(GuestfsSession *session, const gchar *logvol, const gchar *newlogvol, GError **err);
gboolean guestfs_session_vgrename(GuestfsSession *session, const gchar *volgroup, const gchar *newvolgroup, GError **err);
guint *guestfs_session_initrd_cat(GuestfsSession *session, const gchar *initrdpath, const gchar *filename, gsize *size_r, GError **err);
gchar *guestfs_session_pvuuid(GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_vguuid(GuestfsSession *session, const gchar *vgname, GError **err);
gchar *guestfs_session_lvuuid(GuestfsSession *session, const gchar *device, GError **err);
gchar **guestfs_session_vgpvuuids(GuestfsSession *session, const gchar *vgname, GError **err);
gchar **guestfs_session_vglvuuids(GuestfsSession *session, const gchar *vgname, GError **err);
gboolean guestfs_session_copy_size(GuestfsSession *session, const gchar *src, const gchar *dest, gint64 size, GError **err);
gboolean guestfs_session_zero_device(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_txz_in(GuestfsSession *session, const gchar *tarball, const gchar *directory, GError **err);
gboolean guestfs_session_txz_out(GuestfsSession *session, const gchar *directory, const gchar *tarball, GError **err);
gboolean guestfs_session_ntfsresize(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_vgscan(GuestfsSession *session, GError **err);
gboolean guestfs_session_part_del(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gint8 guestfs_session_part_get_bootable(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gint32 guestfs_session_part_get_mbr_id(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err);
gboolean guestfs_session_part_set_mbr_id(GuestfsSession *session, const gchar *device, gint32 partnum, gint32 idbyte, GError **err);
gchar *guestfs_session_checksum_device(GuestfsSession *session, const gchar *csumtype, const gchar *device, GError **err);
gboolean guestfs_session_lvresize_free(GuestfsSession *session, const gchar *lv, gint32 percent, GError **err);
gboolean guestfs_session_aug_clear(GuestfsSession *session, const gchar *augpath, GError **err);
gint32 guestfs_session_get_umask(GuestfsSession *session, GError **err);
gboolean guestfs_session_debug_upload(GuestfsSession *session, const gchar *filename, const gchar *tmpname, gint32 mode, GError **err);
gboolean guestfs_session_base64_in(GuestfsSession *session, const gchar *base64file, const gchar *filename, GError **err);
gboolean guestfs_session_base64_out(GuestfsSession *session, const gchar *filename, const gchar *base64file, GError **err);
gboolean guestfs_session_checksums_out(GuestfsSession *session, const gchar *csumtype, const gchar *directory, const gchar *sumsfile, GError **err);
gboolean guestfs_session_fill_pattern(GuestfsSession *session, const gchar *pattern, gint32 len, const gchar *path, GError **err);
gboolean guestfs_session_write(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err);
gint32 guestfs_session_pwrite(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, gint64 offset, GError **err);
gboolean guestfs_session_resize2fs_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err);
gboolean guestfs_session_pvresize_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err);
gboolean guestfs_session_ntfsresize_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err);
gchar **guestfs_session_available_all_groups(GuestfsSession *session, GError **err);
gboolean guestfs_session_fallocate64(GuestfsSession *session, const gchar *path, gint64 len, GError **err);
gchar *guestfs_session_vfs_label(GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_vfs_uuid(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_lvm_set_filter(GuestfsSession *session, const gchar **devices, GError **err);
gboolean guestfs_session_lvm_clear_filter(GuestfsSession *session, GError **err);
gboolean guestfs_session_luks_open(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err);
gboolean guestfs_session_luks_open_ro(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err);
gboolean guestfs_session_luks_close(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_luks_format(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err);
gboolean guestfs_session_luks_format_cipher(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, const gchar *cipher, GError **err);
gboolean guestfs_session_luks_add_key(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *newkey, gint32 keyslot, GError **err);
gboolean guestfs_session_luks_kill_slot(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err);
gint8 guestfs_session_is_lv(GuestfsSession *session, const gchar *device, GError **err);
gchar *guestfs_session_findfs_uuid(GuestfsSession *session, const gchar *uuid, GError **err);
gchar *guestfs_session_findfs_label(GuestfsSession *session, const gchar *label, GError **err);
gint8 guestfs_session_is_chardev(GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_blockdev(GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_fifo(GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_symlink(GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_socket(GuestfsSession *session, const gchar *path, GError **err);
gchar *guestfs_session_part_to_dev(GuestfsSession *session, const gchar *partition, GError **err);
gboolean guestfs_session_upload_offset(GuestfsSession *session, const gchar *filename, const gchar *remotefilename, gint64 offset, GError **err);
gboolean guestfs_session_download_offset(GuestfsSession *session, const gchar *remotefilename, const gchar *filename, gint64 offset, gint64 size, GError **err);
gint32 guestfs_session_pwrite_device(GuestfsSession *session, const gchar *device, const guint8 *content, gsize content_size, gint64 offset, GError **err);
guint *guestfs_session_pread_device(GuestfsSession *session, const gchar *device, gint32 count, gint64 offset, gsize *size_r, GError **err);
gchar *guestfs_session_lvm_canonical_lv_name(GuestfsSession *session, const gchar *lvname, GError **err);
gboolean guestfs_session_mkfs_opts(GuestfsSession *session, const gchar *fstype, const gchar *device, GuestfsMkfsOpts *optargs, GError **err);
guint *guestfs_session_getxattr(GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err);
guint *guestfs_session_lgetxattr(GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err);
gboolean guestfs_session_resize2fs_M(GuestfsSession *session, const gchar *device, GError **err);
gboolean guestfs_session_internal_autosync(GuestfsSession *session, GError **err);
gint8 guestfs_session_is_zero(GuestfsSession *session, const gchar *path, GError **err);
gint8 guestfs_session_is_zero_device(GuestfsSession *session, const gchar *device, GError **err);
gchar **guestfs_session_list_9p(GuestfsSession *session, GError **err);
gboolean guestfs_session_mount_9p(GuestfsSession *session, const gchar *mounttag, const gchar *mountpoint, GuestfsMount9P *optargs, GError **err);
gchar **guestfs_session_list_dm_devices(GuestfsSession *session, GError **err);
gboolean guestfs_session_ntfsresize_opts(GuestfsSession *session, const gchar *device, GuestfsNTFSResizeOpts *optargs, GError **err);
gboolean guestfs_session_btrfs_filesystem_resize(GuestfsSession *session, const gchar *mountpoint, GuestfsBTRFSFilesystemResize *optargs, GError **err);
gboolean guestfs_session_write_append(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err);
gboolean guestfs_session_compress_out(GuestfsSession *session, const gchar *ctype, const gchar *file, const gchar *zfile, GuestfsCompressOut *optargs, GError **err);
gboolean guestfs_session_compress_device_out(GuestfsSession *session, const gchar *ctype, const gchar *device, const gchar *zdevice, GuestfsCompressDeviceOut *optargs, GError **err);
gint32 guestfs_session_part_to_partnum(GuestfsSession *session, const gchar *partition, GError **err);
gboolean guestfs_session_copy_device_to_device(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToDevice *optargs, GError **err);
gboolean guestfs_session_copy_device_to_file(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToFile *optargs, GError **err);
gboolean guestfs_session_copy_file_to_device(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToDevice *optargs, GError **err);
gboolean guestfs_session_copy_file_to_file(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToFile *optargs, GError **err);
gboolean guestfs_session_tune2fs(GuestfsSession *session, const gchar *device, GuestfsTune2FS *optargs, GError **err);
gboolean guestfs_session_md_create(GuestfsSession *session, const gchar *name, const gchar **devices, GuestfsMDCreate *optargs, GError **err);
gchar **guestfs_session_list_md_devices(GuestfsSession *session, GError **err);
GHashTable *guestfs_session_md_detail(GuestfsSession *session, const gchar *md, GError **err);
gboolean guestfs_session_md_stop(GuestfsSession *session, const gchar *md, GError **err);
GHashTable *guestfs_session_blkid(GuestfsSession *session, const gchar *device, GError **err);
