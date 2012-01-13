/* libguestfs GObject bindings
 * Copyright (C) 2011,2012 Red Hat Inc.
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

#ifndef GUESTFS_GOBJECT_H__
#define GUESTFS_GOBJECT_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* Guestfs::Session gobject definition */
#define GUESTFS_TYPE_SESSION             (guestfs_session_get_type())
#define GUESTFS_SESSION(obj)             (G_TYPE_CHECK_INSTANCE_CAST ( \
                                          (obj), \
                                          GUESTFS_TYPE_SESSION, \
                                          GuestfsSession))
#define GUESTFS_SESSION_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ( \
                                          (klass), \
                                          GUESTFS_TYPE_SESSION, \
                                          GuestfsSessionClass))
#define GUESTFS_IS_SESSION(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ( \
                                          (obj), \
                                          GUESTFS_TYPE_SESSION))
#define GUESTFS_IS_SESSION_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ( \
                                          (klass), \
                                          GUESTFS_TYPE_SESSION))
#define GUESTFS_SESSION_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ( \
                                          (obj), \
                                          GUESTFS_TYPE_SESSION, \
                                          GuestfsSessionClass))

typedef struct _GuestfsSession GuestfsSession;
typedef struct _GuestfsSessionPrivate GuestfsSessionPrivate;
typedef struct _GuestfsSessionClass GuestfsSessionClass;

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

/* Optarg objects */

#define GUESTFS_TYPE_ADD_DRIVE_OPTS         (guestfs_add_drive_opts_get_type())
#define GUESTFS_ADD_DRIVE_OPTS(obj)             (G_TYPE_CHECK_INSTANCE_CAST ( \
                                                 (obj), \
                                                 GUESTFS_TYPE_ADD_DRIVE_OPTS, \
                                                 GuestfsAddDriveOpts))
#define GUESTFS_ADD_DRIVE_OPTS_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ( \
                                                 (klass), \
                                                 GUESTFS_TYPE_ADD_DRIVE_OPTS, \
                                                 GuestfsAddDriveOptsClass))
#define GUESTFS_IS_ADD_DRIVE_OPTS(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ( \
                                                 (obj), \
                                                 GUESTFS_TYPE_ADD_DRIVE_OPTS))
#define GUESTFS_IS_ADD_DRIVE_OPTS_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ( \
                                                 (klass), \
                                                 GUESTFS_TYPE_ADD_DRIVE_OPTS))
#define GUESTFS_ADD_DRIVE_OPTS_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ( \
                                                 (obj), \
                                                 GUESTFS_TYPE_ADD_DRIVE_OPTS, \
                                                 GuestfsAddDriveOptsClass))

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

/* Structs */
typedef struct _GuestfsVersion GuestfsVersion;
struct _GuestfsVersion {
  gint64 major;
  gint64 minor;
  gint64 release;
  gchar *extra;
};

GType guestfs_version_get_type(void);

/* Generated methods */
gboolean guestfs_session_add_drive(GuestfsSession *session, gchar *filename,
                                   GError **err);
gboolean guestfs_session_launch(GuestfsSession *session, GError **err);
GuestfsVersion *guestfs_session_version(GuestfsSession *session, GError **err);

G_END_DECLS

#endif
