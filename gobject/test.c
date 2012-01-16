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

#define GUESTFS_SESSION_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ( (obj), GUESTFS_TYPE_SESSION, GuestfsSessionPrivate))

struct _GuestfsSessionPrivate
{
  guestfs_h *g;
};

G_DEFINE_TYPE(GuestfsSession, guestfs_session, G_TYPE_OBJECT);

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

/* Guestfs::Tristate */
GType
guestfs_tristate_get_type(void)
{
  static GType etype = 0;
  if (etype == 0) {
    static const GEnumValue values[] = {
      { GUESTFS_TRISTATE_FALSE, "GUESTFS_TRISTATE_FALSE", "false" },
      { GUESTFS_TRISTATE_TRUE,  "GUESTFS_TRISTATE_TRUE",  "true" },
      { GUESTFS_TRISTATE_NONE,  "GUESTFS_TRISTATE_NONE",  "none" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static("GuestfsTristate", values);
  }
  return etype;
}

/* Error quark */

#define GUESTFS_ERROR guestfs_error_quark()

static GQuark
guestfs_error_quark(void)
{
  return g_quark_from_static_string("guestfs");
}

/* Structs */

/* GuestfsIntBool */
static GuestfsIntBool *
guestfs_int_bool_copy(GuestfsIntBool *src)
{
  return g_slice_dup(GuestfsIntBool, src);
}

static void
guestfs_int_bool_free(GuestfsIntBool *src)
{
  g_slice_free(GuestfsIntBool, src);
}

G_DEFINE_BOXED_TYPE(GuestfsIntBool, guestfs_int_bool, guestfs_int_bool_copy, guestfs_int_bool_free)

/* GuestfsPV */
static GuestfsPV *
guestfs_lvm_pv_copy(GuestfsPV *src)
{
  return g_slice_dup(GuestfsPV, src);
}

static void
guestfs_lvm_pv_free(GuestfsPV *src)
{
  g_slice_free(GuestfsPV, src);
}

G_DEFINE_BOXED_TYPE(GuestfsPV, guestfs_lvm_pv, guestfs_lvm_pv_copy, guestfs_lvm_pv_free)

/* GuestfsVG */
static GuestfsVG *
guestfs_lvm_vg_copy(GuestfsVG *src)
{
  return g_slice_dup(GuestfsVG, src);
}

static void
guestfs_lvm_vg_free(GuestfsVG *src)
{
  g_slice_free(GuestfsVG, src);
}

G_DEFINE_BOXED_TYPE(GuestfsVG, guestfs_lvm_vg, guestfs_lvm_vg_copy, guestfs_lvm_vg_free)

/* GuestfsLV */
static GuestfsLV *
guestfs_lvm_lv_copy(GuestfsLV *src)
{
  return g_slice_dup(GuestfsLV, src);
}

static void
guestfs_lvm_lv_free(GuestfsLV *src)
{
  g_slice_free(GuestfsLV, src);
}

G_DEFINE_BOXED_TYPE(GuestfsLV, guestfs_lvm_lv, guestfs_lvm_lv_copy, guestfs_lvm_lv_free)

/* GuestfsStat */
static GuestfsStat *
guestfs_stat_copy(GuestfsStat *src)
{
  return g_slice_dup(GuestfsStat, src);
}

static void
guestfs_stat_free(GuestfsStat *src)
{
  g_slice_free(GuestfsStat, src);
}

G_DEFINE_BOXED_TYPE(GuestfsStat, guestfs_stat, guestfs_stat_copy, guestfs_stat_free)

/* GuestfsStatVFS */
static GuestfsStatVFS *
guestfs_statvfs_copy(GuestfsStatVFS *src)
{
  return g_slice_dup(GuestfsStatVFS, src);
}

static void
guestfs_statvfs_free(GuestfsStatVFS *src)
{
  g_slice_free(GuestfsStatVFS, src);
}

G_DEFINE_BOXED_TYPE(GuestfsStatVFS, guestfs_statvfs, guestfs_statvfs_copy, guestfs_statvfs_free)

/* GuestfsDirent */
static GuestfsDirent *
guestfs_dirent_copy(GuestfsDirent *src)
{
  return g_slice_dup(GuestfsDirent, src);
}

static void
guestfs_dirent_free(GuestfsDirent *src)
{
  g_slice_free(GuestfsDirent, src);
}

G_DEFINE_BOXED_TYPE(GuestfsDirent, guestfs_dirent, guestfs_dirent_copy, guestfs_dirent_free)

/* GuestfsVersion */
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

G_DEFINE_BOXED_TYPE(GuestfsVersion, guestfs_version, guestfs_version_copy, guestfs_version_free)

/* GuestfsXAttr */
static GuestfsXAttr *
guestfs_xattr_copy(GuestfsXAttr *src)
{
  return g_slice_dup(GuestfsXAttr, src);
}

static void
guestfs_xattr_free(GuestfsXAttr *src)
{
  g_slice_free(GuestfsXAttr, src);
}

G_DEFINE_BOXED_TYPE(GuestfsXAttr, guestfs_xattr, guestfs_xattr_copy, guestfs_xattr_free)

/* GuestfsINotifyEvent */
static GuestfsINotifyEvent *
guestfs_inotify_event_copy(GuestfsINotifyEvent *src)
{
  return g_slice_dup(GuestfsINotifyEvent, src);
}

static void
guestfs_inotify_event_free(GuestfsINotifyEvent *src)
{
  g_slice_free(GuestfsINotifyEvent, src);
}

G_DEFINE_BOXED_TYPE(GuestfsINotifyEvent, guestfs_inotify_event, guestfs_inotify_event_copy, guestfs_inotify_event_free)

/* GuestfsPartition */
static GuestfsPartition *
guestfs_partition_copy(GuestfsPartition *src)
{
  return g_slice_dup(GuestfsPartition, src);
}

static void
guestfs_partition_free(GuestfsPartition *src)
{
  g_slice_free(GuestfsPartition, src);
}

G_DEFINE_BOXED_TYPE(GuestfsPartition, guestfs_partition, guestfs_partition_copy, guestfs_partition_free)

/* GuestfsApplication */
static GuestfsApplication *
guestfs_application_copy(GuestfsApplication *src)
{
  return g_slice_dup(GuestfsApplication, src);
}

static void
guestfs_application_free(GuestfsApplication *src)
{
  g_slice_free(GuestfsApplication, src);
}

G_DEFINE_BOXED_TYPE(GuestfsApplication, guestfs_application, guestfs_application_copy, guestfs_application_free)

/* Optarg objects */

/* GuestfsAddDriveOpts */
#define GUESTFS_ADD_DRIVE_OPTS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_ADD_DRIVE_OPTS, GuestfsAddDriveOptsPrivate))

struct _GuestfsAddDriveOptsPrivate {
  GuestfsTristate readonly;
  gchar *format;
  gchar *iface;
  gchar *name;
};

G_DEFINE_TYPE(GuestfsAddDriveOpts, guestfs_add_drive_opts, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_ADD_DRIVE_OPTS_PROP0,
  PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY,
  PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT,
  PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE,
  PROP_GUESTFS_ADD_DRIVE_OPTS_NAME
};

static void
guestfs_add_drive_opts_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAddDriveOpts *self = GUESTFS_ADD_DRIVE_OPTS(object);
  GuestfsAddDriveOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY:
      priv->readonly = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT:
      g_free(priv->format);
      priv->format = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE:
      g_free(priv->iface);
      priv->iface = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_NAME:
      g_free(priv->name);
      priv->name = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_opts_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAddDriveOpts *self = GUESTFS_ADD_DRIVE_OPTS(object);
  GuestfsAddDriveOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY:
      g_value_set_g_value_set_enum(value, priv->readonly);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT:
      g_value_set_g_value_set_string(value, priv->format);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE:
      g_value_set_g_value_set_string(value, priv->iface);
      break;

    case PROP_GUESTFS_ADD_DRIVE_OPTS_NAME:
      g_value_set_g_value_set_string(value, priv->name);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_drive_opts_finalize(GObject *object)
{
  GuestfsAddDriveOpts *self = GUESTFS_ADD_DRIVE_OPTS(object);
  GuestfsAddDriveOptsPrivate *priv = self->priv;

  g_free(priv->format);
  g_free(priv->iface);
  g_free(priv->name);

  G_OBJECT_CLASS(guestfs_add_drive_opts_parent_class)->finalize(object);
}

static void
guestfs_add_drive_opts_class_init(GuestfsAddDriveOptsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_add_drive_opts_set_property;
  object_class->get_property = guestfs_add_drive_opts_get_property;

  pspec = g_param_spec_boolean("readonly", "readonly", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DRIVE_OPTS_READONLY, pspec);

  pspec = g_param_spec_string("format", "format", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DRIVE_OPTS_FORMAT, pspec);

  pspec = g_param_spec_string("iface", "iface", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DRIVE_OPTS_IFACE, pspec);

  pspec = g_param_spec_string("name", "name", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DRIVE_OPTS_NAME, pspec);

  object_class->finalize = guestfs_add_drive_opts_finalize;
  g_type_class_add_private(klass, sizeof GuestfsAddDriveOptsPrivate);
}

static void
guestfs_add_drive_opts_init(GuestfsAddDriveOpts *o)
{
  o->priv = GUESTFS_ADD_DRIVE_OPTS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsAddDriveOptsPrivate);
}

/**
 * guestfs_add_drive_opts_new:
 *
 * Create a new GuestfsAddDriveOpts object
 *
 * Returns: (transfer full): a new GuestfsAddDriveOpts object
 */
GuestfsAddDriveOpts *
guestfs_add_drive_opts_new(void)
{
  return GUESTFS_ADD_DRIVE_OPTS(g_object_new(GUESTFS_TYPE_ADD_DRIVE_OPTS, NULL));
}

/* GuestfsAddDomain */
#define GUESTFS_ADD_DOMAIN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_ADD_DOMAIN, GuestfsAddDomainPrivate))

struct _GuestfsAddDomainPrivate {
  gchar *libvirturi;
  GuestfsTristate readonly;
  gchar *iface;
  GuestfsTristate live;
  GuestfsTristate allowuuid;
  gchar *readonlydisk;
};

G_DEFINE_TYPE(GuestfsAddDomain, guestfs_add_domain, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_ADD_DOMAIN_PROP0,
  PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI,
  PROP_GUESTFS_ADD_DOMAIN_READONLY,
  PROP_GUESTFS_ADD_DOMAIN_IFACE,
  PROP_GUESTFS_ADD_DOMAIN_LIVE,
  PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID,
  PROP_GUESTFS_ADD_DOMAIN_READONLYDISK
};

static void
guestfs_add_domain_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsAddDomain *self = GUESTFS_ADD_DOMAIN(object);
  GuestfsAddDomainPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI:
      g_free(priv->libvirturi);
      priv->libvirturi = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLY:
      priv->readonly = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_IFACE:
      g_free(priv->iface);
      priv->iface = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_LIVE:
      priv->live = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID:
      priv->allowuuid = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLYDISK:
      g_free(priv->readonlydisk);
      priv->readonlydisk = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_domain_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsAddDomain *self = GUESTFS_ADD_DOMAIN(object);
  GuestfsAddDomainPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI:
      g_value_set_g_value_set_string(value, priv->libvirturi);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLY:
      g_value_set_g_value_set_enum(value, priv->readonly);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_IFACE:
      g_value_set_g_value_set_string(value, priv->iface);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_LIVE:
      g_value_set_g_value_set_enum(value, priv->live);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID:
      g_value_set_g_value_set_enum(value, priv->allowuuid);
      break;

    case PROP_GUESTFS_ADD_DOMAIN_READONLYDISK:
      g_value_set_g_value_set_string(value, priv->readonlydisk);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_add_domain_finalize(GObject *object)
{
  GuestfsAddDomain *self = GUESTFS_ADD_DOMAIN(object);
  GuestfsAddDomainPrivate *priv = self->priv;

  g_free(priv->libvirturi);
  g_free(priv->iface);
  g_free(priv->readonlydisk);

  G_OBJECT_CLASS(guestfs_add_domain_parent_class)->finalize(object);
}

static void
guestfs_add_domain_class_init(GuestfsAddDomainClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_add_domain_set_property;
  object_class->get_property = guestfs_add_domain_get_property;

  pspec = g_param_spec_string("libvirturi", "libvirturi", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DOMAIN_LIBVIRTURI, pspec);

  pspec = g_param_spec_boolean("readonly", "readonly", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DOMAIN_READONLY, pspec);

  pspec = g_param_spec_string("iface", "iface", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DOMAIN_IFACE, pspec);

  pspec = g_param_spec_boolean("live", "live", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DOMAIN_LIVE, pspec);

  pspec = g_param_spec_boolean("allowuuid", "allowuuid", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DOMAIN_ALLOWUUID, pspec);

  pspec = g_param_spec_string("readonlydisk", "readonlydisk", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_ADD_DOMAIN_READONLYDISK, pspec);

  object_class->finalize = guestfs_add_domain_finalize;
  g_type_class_add_private(klass, sizeof GuestfsAddDomainPrivate);
}

static void
guestfs_add_domain_init(GuestfsAddDomain *o)
{
  o->priv = GUESTFS_ADD_DOMAIN_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsAddDomainPrivate);
}

/**
 * guestfs_add_domain_new:
 *
 * Create a new GuestfsAddDomain object
 *
 * Returns: (transfer full): a new GuestfsAddDomain object
 */
GuestfsAddDomain *
guestfs_add_domain_new(void)
{
  return GUESTFS_ADD_DOMAIN(g_object_new(GUESTFS_TYPE_ADD_DOMAIN, NULL));
}

/* GuestfsInspectGetIcon */
#define GUESTFS_INSPECT_GET_ICON_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_INSPECT_GET_ICON, GuestfsInspectGetIconPrivate))

struct _GuestfsInspectGetIconPrivate {
  GuestfsTristate favicon;
  GuestfsTristate highquality;
};

G_DEFINE_TYPE(GuestfsInspectGetIcon, guestfs_inspect_get_icon, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_INSPECT_GET_ICON_PROP0,
  PROP_GUESTFS_INSPECT_GET_ICON_FAVICON,
  PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY
};

static void
guestfs_inspect_get_icon_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsInspectGetIcon *self = GUESTFS_INSPECT_GET_ICON(object);
  GuestfsInspectGetIconPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INSPECT_GET_ICON_FAVICON:
      priv->favicon = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY:
      priv->highquality = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_inspect_get_icon_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsInspectGetIcon *self = GUESTFS_INSPECT_GET_ICON(object);
  GuestfsInspectGetIconPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_INSPECT_GET_ICON_FAVICON:
      g_value_set_g_value_set_enum(value, priv->favicon);
      break;

    case PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY:
      g_value_set_g_value_set_enum(value, priv->highquality);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_inspect_get_icon_finalize(GObject *object)
{
  GuestfsInspectGetIcon *self = GUESTFS_INSPECT_GET_ICON(object);
  GuestfsInspectGetIconPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_inspect_get_icon_parent_class)->finalize(object);
}

static void
guestfs_inspect_get_icon_class_init(GuestfsInspectGetIconClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_inspect_get_icon_set_property;
  object_class->get_property = guestfs_inspect_get_icon_get_property;

  pspec = g_param_spec_boolean("favicon", "favicon", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_INSPECT_GET_ICON_FAVICON, pspec);

  pspec = g_param_spec_boolean("highquality", "highquality", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_INSPECT_GET_ICON_HIGHQUALITY, pspec);

  object_class->finalize = guestfs_inspect_get_icon_finalize;
  g_type_class_add_private(klass, sizeof GuestfsInspectGetIconPrivate);
}

static void
guestfs_inspect_get_icon_init(GuestfsInspectGetIcon *o)
{
  o->priv = GUESTFS_INSPECT_GET_ICON_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsInspectGetIconPrivate);
}

/**
 * guestfs_inspect_get_icon_new:
 *
 * Create a new GuestfsInspectGetIcon object
 *
 * Returns: (transfer full): a new GuestfsInspectGetIcon object
 */
GuestfsInspectGetIcon *
guestfs_inspect_get_icon_new(void)
{
  return GUESTFS_INSPECT_GET_ICON(g_object_new(GUESTFS_TYPE_INSPECT_GET_ICON, NULL));
}

/* GuestfsMkfsOpts */
#define GUESTFS_MKFS_OPTS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MKFS_OPTS, GuestfsMkfsOptsPrivate))

struct _GuestfsMkfsOptsPrivate {
  gint blocksize;
  gchar *features;
  gint inode;
  gint sectorsize;
};

G_DEFINE_TYPE(GuestfsMkfsOpts, guestfs_mkfs_opts, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_MKFS_OPTS_PROP0,
  PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE,
  PROP_GUESTFS_MKFS_OPTS_FEATURES,
  PROP_GUESTFS_MKFS_OPTS_INODE,
  PROP_GUESTFS_MKFS_OPTS_SECTORSIZE
};

static void
guestfs_mkfs_opts_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMkfsOpts *self = GUESTFS_MKFS_OPTS(object);
  GuestfsMkfsOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE:
      priv->blocksize = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MKFS_OPTS_FEATURES:
      g_free(priv->features);
      priv->features = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_MKFS_OPTS_INODE:
      priv->inode = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MKFS_OPTS_SECTORSIZE:
      priv->sectorsize = g_value_get_int(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mkfs_opts_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMkfsOpts *self = GUESTFS_MKFS_OPTS(object);
  GuestfsMkfsOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE:
      g_value_set_g_value_set_int(value, priv->blocksize);
      break;

    case PROP_GUESTFS_MKFS_OPTS_FEATURES:
      g_value_set_g_value_set_string(value, priv->features);
      break;

    case PROP_GUESTFS_MKFS_OPTS_INODE:
      g_value_set_g_value_set_int(value, priv->inode);
      break;

    case PROP_GUESTFS_MKFS_OPTS_SECTORSIZE:
      g_value_set_g_value_set_int(value, priv->sectorsize);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mkfs_opts_finalize(GObject *object)
{
  GuestfsMkfsOpts *self = GUESTFS_MKFS_OPTS(object);
  GuestfsMkfsOptsPrivate *priv = self->priv;

  g_free(priv->features);

  G_OBJECT_CLASS(guestfs_mkfs_opts_parent_class)->finalize(object);
}

static void
guestfs_mkfs_opts_class_init(GuestfsMkfsOptsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_mkfs_opts_set_property;
  object_class->get_property = guestfs_mkfs_opts_get_property;

  pspec = g_param_spec_int("blocksize", "blocksize", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MKFS_OPTS_BLOCKSIZE, pspec);

  pspec = g_param_spec_string("features", "features", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MKFS_OPTS_FEATURES, pspec);

  pspec = g_param_spec_int("inode", "inode", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MKFS_OPTS_INODE, pspec);

  pspec = g_param_spec_int("sectorsize", "sectorsize", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MKFS_OPTS_SECTORSIZE, pspec);

  object_class->finalize = guestfs_mkfs_opts_finalize;
  g_type_class_add_private(klass, sizeof GuestfsMkfsOptsPrivate);
}

static void
guestfs_mkfs_opts_init(GuestfsMkfsOpts *o)
{
  o->priv = GUESTFS_MKFS_OPTS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsMkfsOptsPrivate);
}

/**
 * guestfs_mkfs_opts_new:
 *
 * Create a new GuestfsMkfsOpts object
 *
 * Returns: (transfer full): a new GuestfsMkfsOpts object
 */
GuestfsMkfsOpts *
guestfs_mkfs_opts_new(void)
{
  return GUESTFS_MKFS_OPTS(g_object_new(GUESTFS_TYPE_MKFS_OPTS, NULL));
}

/* GuestfsMount9P */
#define GUESTFS_MOUNT_9P_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MOUNT_9P, GuestfsMount9PPrivate))

struct _GuestfsMount9PPrivate {
  gchar *options;
};

G_DEFINE_TYPE(GuestfsMount9P, guestfs_mount_9p, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_MOUNT_9P_PROP0,
  PROP_GUESTFS_MOUNT_9P_OPTIONS
};

static void
guestfs_mount_9p_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMount9P *self = GUESTFS_MOUNT_9P(object);
  GuestfsMount9PPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MOUNT_9P_OPTIONS:
      g_free(priv->options);
      priv->options = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mount_9p_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMount9P *self = GUESTFS_MOUNT_9P(object);
  GuestfsMount9PPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MOUNT_9P_OPTIONS:
      g_value_set_g_value_set_string(value, priv->options);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_mount_9p_finalize(GObject *object)
{
  GuestfsMount9P *self = GUESTFS_MOUNT_9P(object);
  GuestfsMount9PPrivate *priv = self->priv;

  g_free(priv->options);

  G_OBJECT_CLASS(guestfs_mount_9p_parent_class)->finalize(object);
}

static void
guestfs_mount_9p_class_init(GuestfsMount9PClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_mount_9p_set_property;
  object_class->get_property = guestfs_mount_9p_get_property;

  pspec = g_param_spec_string("options", "options", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MOUNT_9P_OPTIONS, pspec);

  object_class->finalize = guestfs_mount_9p_finalize;
  g_type_class_add_private(klass, sizeof GuestfsMount9PPrivate);
}

static void
guestfs_mount_9p_init(GuestfsMount9P *o)
{
  o->priv = GUESTFS_MOUNT_9P_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsMount9PPrivate);
}

/**
 * guestfs_mount_9p_new:
 *
 * Create a new GuestfsMount9P object
 *
 * Returns: (transfer full): a new GuestfsMount9P object
 */
GuestfsMount9P *
guestfs_mount_9p_new(void)
{
  return GUESTFS_MOUNT_9P(g_object_new(GUESTFS_TYPE_MOUNT_9P, NULL));
}

/* GuestfsNTFSResizeOpts */
#define GUESTFS_NTFSRESIZE_OPTS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_NTFSRESIZE_OPTS, GuestfsNTFSResizeOptsPrivate))

struct _GuestfsNTFSResizeOptsPrivate {
  gint64 size;
  GuestfsTristate force;
};

G_DEFINE_TYPE(GuestfsNTFSResizeOpts, guestfs_ntfsresize_opts, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_NTFSRESIZE_OPTS_PROP0,
  PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE,
  PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE
};

static void
guestfs_ntfsresize_opts_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsNTFSResizeOpts *self = GUESTFS_NTFSRESIZE_OPTS(object);
  GuestfsNTFSResizeOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE:
      priv->force = g_value_get_enum(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsresize_opts_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsNTFSResizeOpts *self = GUESTFS_NTFSRESIZE_OPTS(object);
  GuestfsNTFSResizeOptsPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE:
      g_value_set_g_value_set_int64(value, priv->size);
      break;

    case PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE:
      g_value_set_g_value_set_enum(value, priv->force);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_ntfsresize_opts_finalize(GObject *object)
{
  GuestfsNTFSResizeOpts *self = GUESTFS_NTFSRESIZE_OPTS(object);
  GuestfsNTFSResizeOptsPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_ntfsresize_opts_parent_class)->finalize(object);
}

static void
guestfs_ntfsresize_opts_class_init(GuestfsNTFSResizeOptsClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_ntfsresize_opts_set_property;
  object_class->get_property = guestfs_ntfsresize_opts_get_property;

  pspec = g_param_spec_int64("size", "size", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_NTFSRESIZE_OPTS_SIZE, pspec);

  pspec = g_param_spec_boolean("force", "force", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_NTFSRESIZE_OPTS_FORCE, pspec);

  object_class->finalize = guestfs_ntfsresize_opts_finalize;
  g_type_class_add_private(klass, sizeof GuestfsNTFSResizeOptsPrivate);
}

static void
guestfs_ntfsresize_opts_init(GuestfsNTFSResizeOpts *o)
{
  o->priv = GUESTFS_NTFSRESIZE_OPTS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsNTFSResizeOptsPrivate);
}

/**
 * guestfs_ntfsresize_opts_new:
 *
 * Create a new GuestfsNTFSResizeOpts object
 *
 * Returns: (transfer full): a new GuestfsNTFSResizeOpts object
 */
GuestfsNTFSResizeOpts *
guestfs_ntfsresize_opts_new(void)
{
  return GUESTFS_NTFSRESIZE_OPTS(g_object_new(GUESTFS_TYPE_NTFSRESIZE_OPTS, NULL));
}

/* GuestfsBTRFSFilesystemResize */
#define GUESTFS_BTRFS_FILESYSTEM_RESIZE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE, GuestfsBTRFSFilesystemResizePrivate))

struct _GuestfsBTRFSFilesystemResizePrivate {
  gint64 size;
};

G_DEFINE_TYPE(GuestfsBTRFSFilesystemResize, guestfs_btrfs_filesystem_resize, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_PROP0,
  PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE
};

static void
guestfs_btrfs_filesystem_resize_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSFilesystemResize *self = GUESTFS_BTRFS_FILESYSTEM_RESIZE(object);
  GuestfsBTRFSFilesystemResizePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_btrfs_filesystem_resize_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsBTRFSFilesystemResize *self = GUESTFS_BTRFS_FILESYSTEM_RESIZE(object);
  GuestfsBTRFSFilesystemResizePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE:
      g_value_set_g_value_set_int64(value, priv->size);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_btrfs_filesystem_resize_finalize(GObject *object)
{
  GuestfsBTRFSFilesystemResize *self = GUESTFS_BTRFS_FILESYSTEM_RESIZE(object);
  GuestfsBTRFSFilesystemResizePrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_btrfs_filesystem_resize_parent_class)->finalize(object);
}

static void
guestfs_btrfs_filesystem_resize_class_init(GuestfsBTRFSFilesystemResizeClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_btrfs_filesystem_resize_set_property;
  object_class->get_property = guestfs_btrfs_filesystem_resize_get_property;

  pspec = g_param_spec_int64("size", "size", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_BTRFS_FILESYSTEM_RESIZE_SIZE, pspec);

  object_class->finalize = guestfs_btrfs_filesystem_resize_finalize;
  g_type_class_add_private(klass, sizeof GuestfsBTRFSFilesystemResizePrivate);
}

static void
guestfs_btrfs_filesystem_resize_init(GuestfsBTRFSFilesystemResize *o)
{
  o->priv = GUESTFS_BTRFS_FILESYSTEM_RESIZE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsBTRFSFilesystemResizePrivate);
}

/**
 * guestfs_btrfs_filesystem_resize_new:
 *
 * Create a new GuestfsBTRFSFilesystemResize object
 *
 * Returns: (transfer full): a new GuestfsBTRFSFilesystemResize object
 */
GuestfsBTRFSFilesystemResize *
guestfs_btrfs_filesystem_resize_new(void)
{
  return GUESTFS_BTRFS_FILESYSTEM_RESIZE(g_object_new(GUESTFS_TYPE_BTRFS_FILESYSTEM_RESIZE, NULL));
}

/* GuestfsCompressOut */
#define GUESTFS_COMPRESS_OUT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COMPRESS_OUT, GuestfsCompressOutPrivate))

struct _GuestfsCompressOutPrivate {
  gint level;
};

G_DEFINE_TYPE(GuestfsCompressOut, guestfs_compress_out, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_COMPRESS_OUT_PROP0,
  PROP_GUESTFS_COMPRESS_OUT_LEVEL
};

static void
guestfs_compress_out_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCompressOut *self = GUESTFS_COMPRESS_OUT(object);
  GuestfsCompressOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COMPRESS_OUT_LEVEL:
      priv->level = g_value_get_int(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_compress_out_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCompressOut *self = GUESTFS_COMPRESS_OUT(object);
  GuestfsCompressOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COMPRESS_OUT_LEVEL:
      g_value_set_g_value_set_int(value, priv->level);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_compress_out_finalize(GObject *object)
{
  GuestfsCompressOut *self = GUESTFS_COMPRESS_OUT(object);
  GuestfsCompressOutPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_compress_out_parent_class)->finalize(object);
}

static void
guestfs_compress_out_class_init(GuestfsCompressOutClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_compress_out_set_property;
  object_class->get_property = guestfs_compress_out_get_property;

  pspec = g_param_spec_int("level", "level", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COMPRESS_OUT_LEVEL, pspec);

  object_class->finalize = guestfs_compress_out_finalize;
  g_type_class_add_private(klass, sizeof GuestfsCompressOutPrivate);
}

static void
guestfs_compress_out_init(GuestfsCompressOut *o)
{
  o->priv = GUESTFS_COMPRESS_OUT_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsCompressOutPrivate);
}

/**
 * guestfs_compress_out_new:
 *
 * Create a new GuestfsCompressOut object
 *
 * Returns: (transfer full): a new GuestfsCompressOut object
 */
GuestfsCompressOut *
guestfs_compress_out_new(void)
{
  return GUESTFS_COMPRESS_OUT(g_object_new(GUESTFS_TYPE_COMPRESS_OUT, NULL));
}

/* GuestfsCompressDeviceOut */
#define GUESTFS_COMPRESS_DEVICE_OUT_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COMPRESS_DEVICE_OUT, GuestfsCompressDeviceOutPrivate))

struct _GuestfsCompressDeviceOutPrivate {
  gint level;
};

G_DEFINE_TYPE(GuestfsCompressDeviceOut, guestfs_compress_device_out, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_COMPRESS_DEVICE_OUT_PROP0,
  PROP_GUESTFS_COMPRESS_DEVICE_OUT_LEVEL
};

static void
guestfs_compress_device_out_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCompressDeviceOut *self = GUESTFS_COMPRESS_DEVICE_OUT(object);
  GuestfsCompressDeviceOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COMPRESS_DEVICE_OUT_LEVEL:
      priv->level = g_value_get_int(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_compress_device_out_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCompressDeviceOut *self = GUESTFS_COMPRESS_DEVICE_OUT(object);
  GuestfsCompressDeviceOutPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COMPRESS_DEVICE_OUT_LEVEL:
      g_value_set_g_value_set_int(value, priv->level);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_compress_device_out_finalize(GObject *object)
{
  GuestfsCompressDeviceOut *self = GUESTFS_COMPRESS_DEVICE_OUT(object);
  GuestfsCompressDeviceOutPrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_compress_device_out_parent_class)->finalize(object);
}

static void
guestfs_compress_device_out_class_init(GuestfsCompressDeviceOutClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_compress_device_out_set_property;
  object_class->get_property = guestfs_compress_device_out_get_property;

  pspec = g_param_spec_int("level", "level", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COMPRESS_DEVICE_OUT_LEVEL, pspec);

  object_class->finalize = guestfs_compress_device_out_finalize;
  g_type_class_add_private(klass, sizeof GuestfsCompressDeviceOutPrivate);
}

static void
guestfs_compress_device_out_init(GuestfsCompressDeviceOut *o)
{
  o->priv = GUESTFS_COMPRESS_DEVICE_OUT_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsCompressDeviceOutPrivate);
}

/**
 * guestfs_compress_device_out_new:
 *
 * Create a new GuestfsCompressDeviceOut object
 *
 * Returns: (transfer full): a new GuestfsCompressDeviceOut object
 */
GuestfsCompressDeviceOut *
guestfs_compress_device_out_new(void)
{
  return GUESTFS_COMPRESS_DEVICE_OUT(g_object_new(GUESTFS_TYPE_COMPRESS_DEVICE_OUT, NULL));
}

/* GuestfsCopyDeviceToDevice */
#define GUESTFS_COPY_DEVICE_TO_DEVICE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, GuestfsCopyDeviceToDevicePrivate))

struct _GuestfsCopyDeviceToDevicePrivate {
  gint64 srcoffset;
  gint64 destoffset;
  gint64 size;
};

G_DEFINE_TYPE(GuestfsCopyDeviceToDevice, guestfs_copy_device_to_device, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_PROP0,
  PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE
};

static void
guestfs_copy_device_to_device_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToDevice *self = GUESTFS_COPY_DEVICE_TO_DEVICE(object);
  GuestfsCopyDeviceToDevicePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET:
      priv->srcoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET:
      priv->destoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_device_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToDevice *self = GUESTFS_COPY_DEVICE_TO_DEVICE(object);
  GuestfsCopyDeviceToDevicePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET:
      g_value_set_g_value_set_int64(value, priv->srcoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET:
      g_value_set_g_value_set_int64(value, priv->destoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE:
      g_value_set_g_value_set_int64(value, priv->size);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_device_finalize(GObject *object)
{
  GuestfsCopyDeviceToDevice *self = GUESTFS_COPY_DEVICE_TO_DEVICE(object);
  GuestfsCopyDeviceToDevicePrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_copy_device_to_device_parent_class)->finalize(object);
}

static void
guestfs_copy_device_to_device_class_init(GuestfsCopyDeviceToDeviceClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_copy_device_to_device_set_property;
  object_class->get_property = guestfs_copy_device_to_device_get_property;

  pspec = g_param_spec_int64("srcoffset", "srcoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SRCOFFSET, pspec);

  pspec = g_param_spec_int64("destoffset", "destoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_DESTOFFSET, pspec);

  pspec = g_param_spec_int64("size", "size", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_DEVICE_TO_DEVICE_SIZE, pspec);

  object_class->finalize = guestfs_copy_device_to_device_finalize;
  g_type_class_add_private(klass, sizeof GuestfsCopyDeviceToDevicePrivate);
}

static void
guestfs_copy_device_to_device_init(GuestfsCopyDeviceToDevice *o)
{
  o->priv = GUESTFS_COPY_DEVICE_TO_DEVICE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsCopyDeviceToDevicePrivate);
}

/**
 * guestfs_copy_device_to_device_new:
 *
 * Create a new GuestfsCopyDeviceToDevice object
 *
 * Returns: (transfer full): a new GuestfsCopyDeviceToDevice object
 */
GuestfsCopyDeviceToDevice *
guestfs_copy_device_to_device_new(void)
{
  return GUESTFS_COPY_DEVICE_TO_DEVICE(g_object_new(GUESTFS_TYPE_COPY_DEVICE_TO_DEVICE, NULL));
}

/* GuestfsCopyDeviceToFile */
#define GUESTFS_COPY_DEVICE_TO_FILE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COPY_DEVICE_TO_FILE, GuestfsCopyDeviceToFilePrivate))

struct _GuestfsCopyDeviceToFilePrivate {
  gint64 srcoffset;
  gint64 destoffset;
  gint64 size;
};

G_DEFINE_TYPE(GuestfsCopyDeviceToFile, guestfs_copy_device_to_file, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_COPY_DEVICE_TO_FILE_PROP0,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET,
  PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE
};

static void
guestfs_copy_device_to_file_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToFile *self = GUESTFS_COPY_DEVICE_TO_FILE(object);
  GuestfsCopyDeviceToFilePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET:
      priv->srcoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET:
      priv->destoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_file_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCopyDeviceToFile *self = GUESTFS_COPY_DEVICE_TO_FILE(object);
  GuestfsCopyDeviceToFilePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET:
      g_value_set_g_value_set_int64(value, priv->srcoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET:
      g_value_set_g_value_set_int64(value, priv->destoffset);
      break;

    case PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE:
      g_value_set_g_value_set_int64(value, priv->size);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_device_to_file_finalize(GObject *object)
{
  GuestfsCopyDeviceToFile *self = GUESTFS_COPY_DEVICE_TO_FILE(object);
  GuestfsCopyDeviceToFilePrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_copy_device_to_file_parent_class)->finalize(object);
}

static void
guestfs_copy_device_to_file_class_init(GuestfsCopyDeviceToFileClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_copy_device_to_file_set_property;
  object_class->get_property = guestfs_copy_device_to_file_get_property;

  pspec = g_param_spec_int64("srcoffset", "srcoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_DEVICE_TO_FILE_SRCOFFSET, pspec);

  pspec = g_param_spec_int64("destoffset", "destoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_DEVICE_TO_FILE_DESTOFFSET, pspec);

  pspec = g_param_spec_int64("size", "size", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_DEVICE_TO_FILE_SIZE, pspec);

  object_class->finalize = guestfs_copy_device_to_file_finalize;
  g_type_class_add_private(klass, sizeof GuestfsCopyDeviceToFilePrivate);
}

static void
guestfs_copy_device_to_file_init(GuestfsCopyDeviceToFile *o)
{
  o->priv = GUESTFS_COPY_DEVICE_TO_FILE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsCopyDeviceToFilePrivate);
}

/**
 * guestfs_copy_device_to_file_new:
 *
 * Create a new GuestfsCopyDeviceToFile object
 *
 * Returns: (transfer full): a new GuestfsCopyDeviceToFile object
 */
GuestfsCopyDeviceToFile *
guestfs_copy_device_to_file_new(void)
{
  return GUESTFS_COPY_DEVICE_TO_FILE(g_object_new(GUESTFS_TYPE_COPY_DEVICE_TO_FILE, NULL));
}

/* GuestfsCopyFileToDevice */
#define GUESTFS_COPY_FILE_TO_DEVICE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COPY_FILE_TO_DEVICE, GuestfsCopyFileToDevicePrivate))

struct _GuestfsCopyFileToDevicePrivate {
  gint64 srcoffset;
  gint64 destoffset;
  gint64 size;
};

G_DEFINE_TYPE(GuestfsCopyFileToDevice, guestfs_copy_file_to_device, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_COPY_FILE_TO_DEVICE_PROP0,
  PROP_GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET,
  PROP_GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET,
  PROP_GUESTFS_COPY_FILE_TO_DEVICE_SIZE
};

static void
guestfs_copy_file_to_device_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCopyFileToDevice *self = GUESTFS_COPY_FILE_TO_DEVICE(object);
  GuestfsCopyFileToDevicePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET:
      priv->srcoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET:
      priv->destoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_DEVICE_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_file_to_device_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCopyFileToDevice *self = GUESTFS_COPY_FILE_TO_DEVICE(object);
  GuestfsCopyFileToDevicePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET:
      g_value_set_g_value_set_int64(value, priv->srcoffset);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET:
      g_value_set_g_value_set_int64(value, priv->destoffset);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_DEVICE_SIZE:
      g_value_set_g_value_set_int64(value, priv->size);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_file_to_device_finalize(GObject *object)
{
  GuestfsCopyFileToDevice *self = GUESTFS_COPY_FILE_TO_DEVICE(object);
  GuestfsCopyFileToDevicePrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_copy_file_to_device_parent_class)->finalize(object);
}

static void
guestfs_copy_file_to_device_class_init(GuestfsCopyFileToDeviceClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_copy_file_to_device_set_property;
  object_class->get_property = guestfs_copy_file_to_device_get_property;

  pspec = g_param_spec_int64("srcoffset", "srcoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_FILE_TO_DEVICE_SRCOFFSET, pspec);

  pspec = g_param_spec_int64("destoffset", "destoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_FILE_TO_DEVICE_DESTOFFSET, pspec);

  pspec = g_param_spec_int64("size", "size", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_FILE_TO_DEVICE_SIZE, pspec);

  object_class->finalize = guestfs_copy_file_to_device_finalize;
  g_type_class_add_private(klass, sizeof GuestfsCopyFileToDevicePrivate);
}

static void
guestfs_copy_file_to_device_init(GuestfsCopyFileToDevice *o)
{
  o->priv = GUESTFS_COPY_FILE_TO_DEVICE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsCopyFileToDevicePrivate);
}

/**
 * guestfs_copy_file_to_device_new:
 *
 * Create a new GuestfsCopyFileToDevice object
 *
 * Returns: (transfer full): a new GuestfsCopyFileToDevice object
 */
GuestfsCopyFileToDevice *
guestfs_copy_file_to_device_new(void)
{
  return GUESTFS_COPY_FILE_TO_DEVICE(g_object_new(GUESTFS_TYPE_COPY_FILE_TO_DEVICE, NULL));
}

/* GuestfsCopyFileToFile */
#define GUESTFS_COPY_FILE_TO_FILE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_COPY_FILE_TO_FILE, GuestfsCopyFileToFilePrivate))

struct _GuestfsCopyFileToFilePrivate {
  gint64 srcoffset;
  gint64 destoffset;
  gint64 size;
};

G_DEFINE_TYPE(GuestfsCopyFileToFile, guestfs_copy_file_to_file, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_COPY_FILE_TO_FILE_PROP0,
  PROP_GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET,
  PROP_GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET,
  PROP_GUESTFS_COPY_FILE_TO_FILE_SIZE
};

static void
guestfs_copy_file_to_file_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsCopyFileToFile *self = GUESTFS_COPY_FILE_TO_FILE(object);
  GuestfsCopyFileToFilePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET:
      priv->srcoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET:
      priv->destoffset = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_FILE_SIZE:
      priv->size = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_file_to_file_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsCopyFileToFile *self = GUESTFS_COPY_FILE_TO_FILE(object);
  GuestfsCopyFileToFilePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET:
      g_value_set_g_value_set_int64(value, priv->srcoffset);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET:
      g_value_set_g_value_set_int64(value, priv->destoffset);
      break;

    case PROP_GUESTFS_COPY_FILE_TO_FILE_SIZE:
      g_value_set_g_value_set_int64(value, priv->size);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_copy_file_to_file_finalize(GObject *object)
{
  GuestfsCopyFileToFile *self = GUESTFS_COPY_FILE_TO_FILE(object);
  GuestfsCopyFileToFilePrivate *priv = self->priv;


  G_OBJECT_CLASS(guestfs_copy_file_to_file_parent_class)->finalize(object);
}

static void
guestfs_copy_file_to_file_class_init(GuestfsCopyFileToFileClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_copy_file_to_file_set_property;
  object_class->get_property = guestfs_copy_file_to_file_get_property;

  pspec = g_param_spec_int64("srcoffset", "srcoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_FILE_TO_FILE_SRCOFFSET, pspec);

  pspec = g_param_spec_int64("destoffset", "destoffset", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_FILE_TO_FILE_DESTOFFSET, pspec);

  pspec = g_param_spec_int64("size", "size", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_COPY_FILE_TO_FILE_SIZE, pspec);

  object_class->finalize = guestfs_copy_file_to_file_finalize;
  g_type_class_add_private(klass, sizeof GuestfsCopyFileToFilePrivate);
}

static void
guestfs_copy_file_to_file_init(GuestfsCopyFileToFile *o)
{
  o->priv = GUESTFS_COPY_FILE_TO_FILE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsCopyFileToFilePrivate);
}

/**
 * guestfs_copy_file_to_file_new:
 *
 * Create a new GuestfsCopyFileToFile object
 *
 * Returns: (transfer full): a new GuestfsCopyFileToFile object
 */
GuestfsCopyFileToFile *
guestfs_copy_file_to_file_new(void)
{
  return GUESTFS_COPY_FILE_TO_FILE(g_object_new(GUESTFS_TYPE_COPY_FILE_TO_FILE, NULL));
}

/* GuestfsTune2FS */
#define GUESTFS_TUNE2FS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_TUNE2FS, GuestfsTune2FSPrivate))

struct _GuestfsTune2FSPrivate {
  GuestfsTristate force;
  gint maxmountcount;
  gint mountcount;
  gchar *errorbehavior;
  gint64 group;
  gint intervalbetweenchecks;
  gint reservedblockspercentage;
  gchar *lastmounteddirectory;
  gint64 reservedblockscount;
  gint64 user;
};

G_DEFINE_TYPE(GuestfsTune2FS, guestfs_tune2fs, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_TUNE2FS_PROP0,
  PROP_GUESTFS_TUNE2FS_FORCE,
  PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT,
  PROP_GUESTFS_TUNE2FS_MOUNTCOUNT,
  PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR,
  PROP_GUESTFS_TUNE2FS_GROUP,
  PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS,
  PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE,
  PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY,
  PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT,
  PROP_GUESTFS_TUNE2FS_USER
};

static void
guestfs_tune2fs_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsTune2FS *self = GUESTFS_TUNE2FS(object);
  GuestfsTune2FSPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TUNE2FS_FORCE:
      priv->force = g_value_get_enum(value);
      break;

    case PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT:
      priv->maxmountcount = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_MOUNTCOUNT:
      priv->mountcount = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR:
      g_free(priv->errorbehavior);
      priv->errorbehavior = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_TUNE2FS_GROUP:
      priv->group = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS:
      priv->intervalbetweenchecks = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE:
      priv->reservedblockspercentage = g_value_get_int(value);
      break;

    case PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY:
      g_free(priv->lastmounteddirectory);
      priv->lastmounteddirectory = g_value_dup_string(value);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT:
      priv->reservedblockscount = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_TUNE2FS_USER:
      priv->user = g_value_get_int64(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_tune2fs_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsTune2FS *self = GUESTFS_TUNE2FS(object);
  GuestfsTune2FSPrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_TUNE2FS_FORCE:
      g_value_set_g_value_set_enum(value, priv->force);
      break;

    case PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT:
      g_value_set_g_value_set_int(value, priv->maxmountcount);
      break;

    case PROP_GUESTFS_TUNE2FS_MOUNTCOUNT:
      g_value_set_g_value_set_int(value, priv->mountcount);
      break;

    case PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR:
      g_value_set_g_value_set_string(value, priv->errorbehavior);
      break;

    case PROP_GUESTFS_TUNE2FS_GROUP:
      g_value_set_g_value_set_int64(value, priv->group);
      break;

    case PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS:
      g_value_set_g_value_set_int(value, priv->intervalbetweenchecks);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE:
      g_value_set_g_value_set_int(value, priv->reservedblockspercentage);
      break;

    case PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY:
      g_value_set_g_value_set_string(value, priv->lastmounteddirectory);
      break;

    case PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT:
      g_value_set_g_value_set_int64(value, priv->reservedblockscount);
      break;

    case PROP_GUESTFS_TUNE2FS_USER:
      g_value_set_g_value_set_int64(value, priv->user);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_tune2fs_finalize(GObject *object)
{
  GuestfsTune2FS *self = GUESTFS_TUNE2FS(object);
  GuestfsTune2FSPrivate *priv = self->priv;

  g_free(priv->errorbehavior);
  g_free(priv->lastmounteddirectory);

  G_OBJECT_CLASS(guestfs_tune2fs_parent_class)->finalize(object);
}

static void
guestfs_tune2fs_class_init(GuestfsTune2FSClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_tune2fs_set_property;
  object_class->get_property = guestfs_tune2fs_get_property;

  pspec = g_param_spec_boolean("force", "force", NULL, GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_FORCE, pspec);

  pspec = g_param_spec_int("maxmountcount", "maxmountcount", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_MAXMOUNTCOUNT, pspec);

  pspec = g_param_spec_int("mountcount", "mountcount", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_MOUNTCOUNT, pspec);

  pspec = g_param_spec_string("errorbehavior", "errorbehavior", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_ERRORBEHAVIOR, pspec);

  pspec = g_param_spec_int64("group", "group", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_GROUP, pspec);

  pspec = g_param_spec_int("intervalbetweenchecks", "intervalbetweenchecks", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_INTERVALBETWEENCHECKS, pspec);

  pspec = g_param_spec_int("reservedblockspercentage", "reservedblockspercentage", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSPERCENTAGE, pspec);

  pspec = g_param_spec_string("lastmounteddirectory", "lastmounteddirectory", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_LASTMOUNTEDDIRECTORY, pspec);

  pspec = g_param_spec_int64("reservedblockscount", "reservedblockscount", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_RESERVEDBLOCKSCOUNT, pspec);

  pspec = g_param_spec_int64("user", "user", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_TUNE2FS_USER, pspec);

  object_class->finalize = guestfs_tune2fs_finalize;
  g_type_class_add_private(klass, sizeof GuestfsTune2FSPrivate);
}

static void
guestfs_tune2fs_init(GuestfsTune2FS *o)
{
  o->priv = GUESTFS_TUNE2FS_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsTune2FSPrivate);
}

/**
 * guestfs_tune2fs_new:
 *
 * Create a new GuestfsTune2FS object
 *
 * Returns: (transfer full): a new GuestfsTune2FS object
 */
GuestfsTune2FS *
guestfs_tune2fs_new(void)
{
  return GUESTFS_TUNE2FS(g_object_new(GUESTFS_TYPE_TUNE2FS, NULL));
}

/* GuestfsMDCreate */
#define GUESTFS_MD_CREATE_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE((obj), GUESTFS_TYPE_MD_CREATE, GuestfsMDCreatePrivate))

struct _GuestfsMDCreatePrivate {
  gint64 missingbitmap;
  gint nrdevices;
  gint spare;
  gint64 chunk;
  gchar *level;
};

G_DEFINE_TYPE(GuestfsMDCreate, guestfs_md_create, G_TYPE_OBJECT);

enum {
PROP_GUESTFS_MD_CREATE_PROP0,
  PROP_GUESTFS_MD_CREATE_MISSINGBITMAP,
  PROP_GUESTFS_MD_CREATE_NRDEVICES,
  PROP_GUESTFS_MD_CREATE_SPARE,
  PROP_GUESTFS_MD_CREATE_CHUNK,
  PROP_GUESTFS_MD_CREATE_LEVEL
};

static void
guestfs_md_create_set_property(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  GuestfsMDCreate *self = GUESTFS_MD_CREATE(object);
  GuestfsMDCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MD_CREATE_MISSINGBITMAP:
      priv->missingbitmap = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_MD_CREATE_NRDEVICES:
      priv->nrdevices = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MD_CREATE_SPARE:
      priv->spare = g_value_get_int(value);
      break;

    case PROP_GUESTFS_MD_CREATE_CHUNK:
      priv->chunk = g_value_get_int64(value);
      break;

    case PROP_GUESTFS_MD_CREATE_LEVEL:
      g_free(priv->level);
      priv->level = g_value_dup_string(value);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_md_create_get_property(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  GuestfsMDCreate *self = GUESTFS_MD_CREATE(object);
  GuestfsMDCreatePrivate *priv = self->priv;

  switch (property_id) {
    case PROP_GUESTFS_MD_CREATE_MISSINGBITMAP:
      g_value_set_g_value_set_int64(value, priv->missingbitmap);
      break;

    case PROP_GUESTFS_MD_CREATE_NRDEVICES:
      g_value_set_g_value_set_int(value, priv->nrdevices);
      break;

    case PROP_GUESTFS_MD_CREATE_SPARE:
      g_value_set_g_value_set_int(value, priv->spare);
      break;

    case PROP_GUESTFS_MD_CREATE_CHUNK:
      g_value_set_g_value_set_int64(value, priv->chunk);
      break;

    case PROP_GUESTFS_MD_CREATE_LEVEL:
      g_value_set_g_value_set_string(value, priv->level);
      break;

    default:
      /* Invalid property */
      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
  }
}

static void
guestfs_md_create_finalize(GObject *object)
{
  GuestfsMDCreate *self = GUESTFS_MD_CREATE(object);
  GuestfsMDCreatePrivate *priv = self->priv;

  g_free(priv->level);

  G_OBJECT_CLASS(guestfs_md_create_parent_class)->finalize(object);
}

static void
guestfs_md_create_class_init(GuestfsMDCreateClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS(klass);
  GParamSpec *pspec;

  object_class->set_property = guestfs_md_create_set_property;
  object_class->get_property = guestfs_md_create_get_property;

  pspec = g_param_spec_int64("missingbitmap", "missingbitmap", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MD_CREATE_MISSINGBITMAP, pspec);

  pspec = g_param_spec_int("nrdevices", "nrdevices", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MD_CREATE_NRDEVICES, pspec);

  pspec = g_param_spec_int("spare", "spare", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MD_CREATE_SPARE, pspec);

  pspec = g_param_spec_int64("chunk", "chunk", NULL, G_MININT32, G_MAXINT32, -1, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MD_CREATE_CHUNK, pspec);

  pspec = g_param_spec_string("level", "level", NULL, NULL, G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);
  g_object_class_install_property(object_class, PROP_GUESTFS_MD_CREATE_LEVEL, pspec);

  object_class->finalize = guestfs_md_create_finalize;
  g_type_class_add_private(klass, sizeof GuestfsMDCreatePrivate);
}

static void
guestfs_md_create_init(GuestfsMDCreate *o)
{
  o->priv = GUESTFS_MD_CREATE_GET_PRIVATE(o);
  /* XXX: Find out if gobject already zeroes private structs */
  memset(o->priv, 0, sizeof GuestfsMDCreatePrivate);
}

/**
 * guestfs_md_create_new:
 *
 * Create a new GuestfsMDCreate object
 *
 * Returns: (transfer full): a new GuestfsMDCreate object
 */
GuestfsMDCreate *
guestfs_md_create_new(void)
{
  return GUESTFS_MD_CREATE(g_object_new(GUESTFS_TYPE_MD_CREATE, NULL));
}

/* Generated methods */

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible parameter type correctly.
 * 
 * It echos the contents of each parameter to stdout.
 * 
 * You probably don't want to call this function.
 * 
 * @str: (transfer none) (type utf8):
 * @optstr: (transfer none) (type utf8) (allow-none):
 * @strlist: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 * @b:
 * @integer:
 * @integer64:
 * @filein: (transfer none) (type filename):
 * @fileout: (transfer none) (type filename):
 * @bufferin: (transfer none) (array length=bufferin_size) (element-type guint8): an array of binary data
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_test0(GuestfsSession *session, const gchar *str, const gchar *optstr, const gchar **strlist, gboolean b, gint32 integer, gint64 integer64, const gchar *filein, const gchar *fileout, const guint8 *bufferin, gsize bufferin_size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_test0(g, str, optstr, strlist, b, integer, integer64, filein, fileout, bufferin, bufferin_size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_test0rint(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_test0rint(g, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_test0rinterr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_test0rinterr(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: the returned value, or -1 on error
 */
gint64 guestfs_session_test0rint64(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  int64_t ret = guestfs_test0rint64(g, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint64 guestfs_session_test0rint64err(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int64_t ret = guestfs_test0rint64err(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_test0rbool(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_test0rbool(g, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_test0rboolerr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_test0rboolerr(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer none): the returned string, or NULL on error
 */
gchar *guestfs_session_test0rconststring(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  const char *ret = guestfs_test0rconststring(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: (transfer none): the returned string, or NULL on error
 */
gchar *guestfs_session_test0rconststringerr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  const char *ret = guestfs_test0rconststringerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer none): the returned string. Note that NULL does not indicate error
 */
gchar *guestfs_session_test0rconstoptstring(GuestfsSession *session, const gchar *val){
  guestfs_h *g = session->priv->g;
  const char *ret = guestfs_test0rconstoptstring(g, val);

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: (transfer none): the returned string. Note that NULL does not indicate error
 */
gchar *guestfs_session_test0rconstoptstringerr(GuestfsSession *session){
  guestfs_h *g = session->priv->g;
  const char *ret = guestfs_test0rconstoptstringerr(g);

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_test0rstring(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_test0rstring(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_test0rstringerr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_test0rstringerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_test0rstringlist(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_test0rstringlist(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_test0rstringlisterr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_test0rstringlisterr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer full): a PV object, or NULL on error
 */
GuestfsPV *guestfs_session_test0rstruct(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_lvm_pv *ret = guestfs_test0rstruct(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsTest0rstruct *s = g_slice_new(GuestfsTest0rstruct);
  s->pv_name = g_strdup(ret->pv_name);
  s->pv_uuid = ret->pv_uuid;
  s->pv_fmt = g_strdup(ret->pv_fmt);
  s->pv_size = ret->pv_size;
  s->dev_size = ret->dev_size;
  s->pv_free = ret->pv_free;
  s->pv_used = ret->pv_used;
  s->pv_attr = g_strdup(ret->pv_attr);
  s->pv_pe_count = ret->pv_pe_count;
  s->pv_pe_alloc_count = ret->pv_pe_alloc_count;
  s->pv_tags = g_strdup(ret->pv_tags);
  s->pe_start = ret->pe_start;
  s->pv_mda_count = ret->pv_mda_count;
  s->pv_mda_free = ret->pv_mda_free;
  guestfs_free_lvm_pv(ret);
  return s;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: (transfer full): a PV object, or NULL on error
 */
GuestfsPV *guestfs_session_test0rstructerr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_lvm_pv *ret = guestfs_test0rstructerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsTest0rstructerr *s = g_slice_new(GuestfsTest0rstructerr);
  s->pv_name = g_strdup(ret->pv_name);
  s->pv_uuid = ret->pv_uuid;
  s->pv_fmt = g_strdup(ret->pv_fmt);
  s->pv_size = ret->pv_size;
  s->dev_size = ret->dev_size;
  s->pv_free = ret->pv_free;
  s->pv_used = ret->pv_used;
  s->pv_attr = g_strdup(ret->pv_attr);
  s->pv_pe_count = ret->pv_pe_count;
  s->pv_pe_alloc_count = ret->pv_pe_alloc_count;
  s->pv_tags = g_strdup(ret->pv_tags);
  s->pe_start = ret->pe_start;
  s->pv_mda_count = ret->pv_mda_count;
  s->pv_mda_free = ret->pv_mda_free;
  guestfs_free_lvm_pv(ret);
  return s;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type PV): an array of PV objects, or NULL on error
 */
GuestfsPV **guestfs_session_test0rstructlist(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_lvm_pv_list *ret = guestfs_test0rstructlist(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsTest0rstructlist **l = g_malloc(sizeof GuestfsTest0rstructlist* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsTest0rstructlist *s = g_slice_new(GuestfsTest0rstructlist);
    s->pv_name = g_strdup(ret->val[i]->pv_name);
    s->pv_uuid = ret->val[i]->pv_uuid;
    s->pv_fmt = g_strdup(ret->val[i]->pv_fmt);
    s->pv_size = ret->val[i]->pv_size;
    s->dev_size = ret->val[i]->dev_size;
    s->pv_free = ret->val[i]->pv_free;
    s->pv_used = ret->val[i]->pv_used;
    s->pv_attr = g_strdup(ret->val[i]->pv_attr);
    s->pv_pe_count = ret->val[i]->pv_pe_count;
    s->pv_pe_alloc_count = ret->val[i]->pv_pe_alloc_count;
    s->pv_tags = g_strdup(ret->val[i]->pv_tags);
    s->pe_start = ret->val[i]->pe_start;
    s->pv_mda_count = ret->val[i]->pv_mda_count;
    s->pv_mda_free = ret->val[i]->pv_mda_free;
  guestfs_free_lvm_pv(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type PV): an array of PV objects, or NULL on error
 */
GuestfsPV **guestfs_session_test0rstructlisterr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_lvm_pv_list *ret = guestfs_test0rstructlisterr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsTest0rstructlisterr **l = g_malloc(sizeof GuestfsTest0rstructlisterr* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsTest0rstructlisterr *s = g_slice_new(GuestfsTest0rstructlisterr);
    s->pv_name = g_strdup(ret->val[i]->pv_name);
    s->pv_uuid = ret->val[i]->pv_uuid;
    s->pv_fmt = g_strdup(ret->val[i]->pv_fmt);
    s->pv_size = ret->val[i]->pv_size;
    s->dev_size = ret->val[i]->dev_size;
    s->pv_free = ret->val[i]->pv_free;
    s->pv_used = ret->val[i]->pv_used;
    s->pv_attr = g_strdup(ret->val[i]->pv_attr);
    s->pv_pe_count = ret->val[i]->pv_pe_count;
    s->pv_pe_alloc_count = ret->val[i]->pv_pe_alloc_count;
    s->pv_tags = g_strdup(ret->val[i]->pv_tags);
    s->pe_start = ret->val[i]->pe_start;
    s->pv_mda_count = ret->val[i]->pv_mda_count;
    s->pv_mda_free = ret->val[i]->pv_mda_free;
  guestfs_free_lvm_pv(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * It converts string "val" to the return type.
 * 
 * You probably don't want to call this function.
 * 
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_test0rhashtable(GuestfsSession *session, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_test0rhashtable(g, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * internal test function - do not use
 *
 * This is an internal test function which is used to test
 * whether the automatically generated bindings can handle
 * every possible return type correctly.
 * 
 * This function always returns an error.
 * 
 * You probably don't want to call this function.
 * 
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_test0rhashtableerr(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_test0rhashtableerr(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * launch the qemu subprocess
 *
 * Internally libguestfs is implemented by running a
 * virtual machine using qemu(1).
 * 
 * You should call this after configuring the handle (eg.
 * adding drives) but before performing any actions.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_launch(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_launch(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * wait until the qemu subprocess launches (no op)
 *
 * This function is a no op.
 * 
 * In versions of the API < 1.0.71 you had to call this
 * function just after calling "guestfs_launch" to wait for
 * the launch to complete. However this is no longer
 * necessary because "guestfs_launch" now does the waiting.
 * 
 * If you see any calls to this function in code then you
 * can just remove them, unless you want to retain
 * compatibility with older versions of the API.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_wait_ready(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_wait_ready(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * kill the qemu subprocess
 *
 * This kills the qemu subprocess. You should never need to
 * call this.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_kill_subprocess(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_kill_subprocess(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add an image to examine or modify
 *
 * This function is the equivalent of calling
 * "guestfs_add_drive_opts" with no optional parameters, so
 * the disk is added writable, with the format being
 * detected automatically.
 * 
 * Automatic detection of the format opens you up to a
 * potential security hole when dealing with untrusted
 * raw-format images. See CVE-2010-3851 and RHBZ#642934.
 * Specifying the format closes this security hole.
 * Therefore you should think about replacing calls to this
 * function with calls to "guestfs_add_drive_opts", and
 * specifying the format.
 * 
 * @filename: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_add_drive(GuestfsSession *session, const gchar *filename, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_add_drive(g, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add a CD-ROM disk image to examine
 *
 * This function adds a virtual CD-ROM disk image to the
 * guest.
 * 
 * This is equivalent to the qemu parameter *-cdrom
 * filename*.
 * 
 * Notes:
 * 
 * *   This call checks for the existence of "filename".
 * This stops you from specifying other types of drive
 * which are supported by qemu such as "nbd:" and
 * "http:" URLs. To specify those, use the general
 * "guestfs_config" call instead.
 * 
 * *   If you just want to add an ISO file (often you use
 * this as an efficient way to transfer large files
 * into the guest), then you should probably use
 * "guestfs_add_drive_ro" instead.
 * 
 * @filename: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_add_cdrom(GuestfsSession *session, const gchar *filename, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_add_cdrom(g, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add a drive in snapshot mode (read-only)
 *
 * This function is the equivalent of calling
 * "guestfs_add_drive_opts" with the optional parameter
 * "GUESTFS_ADD_DRIVE_OPTS_READONLY" set to 1, so the disk
 * is added read-only, with the format being detected
 * automatically.
 * 
 * @filename: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_add_drive_ro(GuestfsSession *session, const gchar *filename, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_add_drive_ro(g, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add qemu parameters
 *
 * This can be used to add arbitrary qemu command line
 * parameters of the form *-param value*. Actually it's not
 * quite arbitrary - we prevent you from setting some
 * parameters which would interfere with parameters that we
 * use.
 * 
 * The first character of "param" string must be a "-"
 * (dash).
 * 
 * "value" can be NULL.
 * 
 * @qemuparam: (transfer none) (type utf8):
 * @qemuvalue: (transfer none) (type utf8) (allow-none):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_config(GuestfsSession *session, const gchar *qemuparam, const gchar *qemuvalue, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_config(g, qemuparam, qemuvalue);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set the qemu binary
 *
 * Set the qemu binary that we will use.
 * 
 * The default is chosen when the library was compiled by
 * the configure script.
 * 
 * You can also override this by setting the
 * "LIBGUESTFS_QEMU" environment variable.
 * 
 * Setting "qemu" to "NULL" restores the default qemu
 * binary.
 * 
 * Note that you should call this function as early as
 * possible after creating the handle. This is because some
 * pre-launch operations depend on testing qemu features
 * (by running "qemu -help"). If the qemu binary changes,
 * we don't retest features, and so you might see
 * inconsistent results. Using the environment variable
 * "LIBGUESTFS_QEMU" is safest of all since that picks the
 * qemu binary at the same time as the handle is created.
 * 
 * @qemu: (transfer none) (type utf8) (allow-none):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_qemu(GuestfsSession *session, const gchar *qemu, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_qemu(g, qemu);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the qemu binary
 *
 * Return the current qemu binary.
 * 
 * This is always non-NULL. If it wasn't set already, then
 * this will return the default qemu binary name.
 * 
 *
 * Returns: (transfer none): the returned string, or NULL on error
 */
gchar *guestfs_session_get_qemu(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  const char *ret = guestfs_get_qemu(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * set the search path
 *
 * Set the path that libguestfs searches for kernel and
 * initrd.img.
 * 
 * The default is "$libdir/guestfs" unless overridden by
 * setting "LIBGUESTFS_PATH" environment variable.
 * 
 * Setting "path" to "NULL" restores the default path.
 * 
 * @searchpath: (transfer none) (type utf8) (allow-none):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_path(GuestfsSession *session, const gchar *searchpath, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_path(g, searchpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the search path
 *
 * Return the current search path.
 * 
 * This is always non-NULL. If it wasn't set already, then
 * this will return the default path.
 * 
 *
 * Returns: (transfer none): the returned string, or NULL on error
 */
gchar *guestfs_session_get_path(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  const char *ret = guestfs_get_path(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * add options to kernel command line
 *
 * This function is used to add additional options to the
 * guest kernel command line.
 * 
 * The default is "NULL" unless overridden by setting
 * "LIBGUESTFS_APPEND" environment variable.
 * 
 * Setting "append" to "NULL" means *no* additional options
 * are passed (libguestfs always adds a few of its own).
 * 
 * @append: (transfer none) (type utf8) (allow-none):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_append(GuestfsSession *session, const gchar *append, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_append(g, append);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the additional kernel options
 *
 * Return the additional kernel options which are added to
 * the guest kernel command line.
 * 
 * If "NULL" then no options are added.
 * 
 *
 * Returns: (transfer none): the returned string. Note that NULL does not indicate error
 */
gchar *guestfs_session_get_append(GuestfsSession *session){
  guestfs_h *g = session->priv->g;
  const char *ret = guestfs_get_append(g);

  return ret;
}

/**
 * set autosync mode
 *
 * If "autosync" is true, this enables autosync. Libguestfs
 * will make a best effort attempt to make filesystems
 * consistent and synchronized when the handle is closed
 * (also if the program exits without closing handles).
 * 
 * This is enabled by default (since libguestfs 1.5.24,
 * previously it was disabled by default).
 * 
 * @autosync:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_autosync(GuestfsSession *session, gboolean autosync, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_autosync(g, autosync);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get autosync mode
 *
 * Get the autosync flag.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_autosync(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_autosync(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * set verbose mode
 *
 * If "verbose" is true, this turns on verbose messages.
 * 
 * Verbose messages are disabled unless the environment
 * variable "LIBGUESTFS_DEBUG" is defined and set to 1.
 * 
 * Verbose messages are normally sent to "stderr", unless
 * you register a callback to send them somewhere else (see
 * "guestfs_set_event_callback").
 * 
 * @verbose:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_verbose(GuestfsSession *session, gboolean verbose, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_verbose(g, verbose);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get verbose mode
 *
 * This returns the verbose messages flag.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_verbose(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_verbose(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * is ready to accept commands
 *
 * This returns true iff this handle is ready to accept
 * commands (in the "READY" state).
 * 
 * For more information on states, see guestfs(3).
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_ready(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_ready(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * is in configuration state
 *
 * This returns true iff this handle is being configured
 * (in the "CONFIG" state).
 * 
 * For more information on states, see guestfs(3).
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_config(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_config(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * is launching subprocess
 *
 * This returns true iff this handle is launching the
 * subprocess (in the "LAUNCHING" state).
 * 
 * For more information on states, see guestfs(3).
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_launching(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_launching(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * is busy processing a command
 *
 * This returns true iff this handle is busy processing a
 * command (in the "BUSY" state).
 * 
 * For more information on states, see guestfs(3).
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_busy(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_busy(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get the current state
 *
 * This returns the current state as an opaque integer.
 * This is only useful for printing debug and internal
 * error messages.
 * 
 * For more information on states, see guestfs(3).
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_get_state(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_state(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * set memory allocated to the qemu subprocess
 *
 * This sets the memory size in megabytes allocated to the
 * qemu subprocess. This only has any effect if called
 * before "guestfs_launch".
 * 
 * You can also change this by setting the environment
 * variable "LIBGUESTFS_MEMSIZE" before the handle is
 * created.
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 * 
 * @memsize:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_memsize(GuestfsSession *session, gint32 memsize, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_memsize(g, memsize);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get memory allocated to the qemu subprocess
 *
 * This gets the memory size in megabytes allocated to the
 * qemu subprocess.
 * 
 * If "guestfs_set_memsize" was not called on this handle,
 * and if "LIBGUESTFS_MEMSIZE" was not set, then this
 * returns the compiled-in default value for memsize.
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_get_memsize(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_memsize(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get PID of qemu subprocess
 *
 * Return the process ID of the qemu subprocess. If there
 * is no qemu subprocess, then this will return an error.
 * 
 * This is an internal call used for debugging and testing.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_get_pid(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_pid(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get the library version number
 *
 * Return the libguestfs version number that the program is
 * linked against.
 * 
 * Note that because of dynamic linking this is not
 * necessarily the version of libguestfs that you compiled
 * against. You can compile the program, and then at
 * runtime dynamically link against a completely different
 * "libguestfs.so" library.
 * 
 * This call was added in version 1.0.58. In previous
 * versions of libguestfs there was no way to get the
 * version number. From C code you can use dynamic linker
 * functions to find out if this symbol exists (if it
 * doesn't, then it's an earlier version).
 * 
 * The call returns a structure with four elements. The
 * first three ("major", "minor" and "release") are numbers
 * and correspond to the usual version triplet. The fourth
 * element ("extra") is a string and is normally empty, but
 * may be used for distro-specific information.
 * 
 * To construct the original version string:
 * "$major.$minor.$release$extra"
 * 
 * See also: "LIBGUESTFS VERSION NUMBERS" in guestfs(3).
 * 
 * *Note:* Don't use this call to test for availability of
 * features. In enterprise distributions we backport
 * features from later versions into earlier versions,
 * making this an unreliable way to test for features. Use
 * "guestfs_available" instead.
 * 
 *
 * Returns: (transfer full): a Version object, or NULL on error
 */
GuestfsVersion *guestfs_session_version(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_version *ret = guestfs_version(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsVersion *s = g_slice_new(GuestfsVersion);
  s->major = ret->major;
  s->minor = ret->minor;
  s->release = ret->release;
  s->extra = g_strdup(ret->extra);
  guestfs_free_version(ret);
  return s;
}

/**
 * set SELinux enabled or disabled at appliance boot
 *
 * This sets the selinux flag that is passed to the
 * appliance at boot time. The default is "selinux=0"
 * (disabled).
 * 
 * Note that if SELinux is enabled, it is always in
 * Permissive mode ("enforcing=0").
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 * 
 * @selinux:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_selinux(GuestfsSession *session, gboolean selinux, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_selinux(g, selinux);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get SELinux enabled flag
 *
 * This returns the current setting of the selinux flag
 * which is passed to the appliance at boot time. See
 * "guestfs_set_selinux".
 * 
 * For more information on the architecture of libguestfs,
 * see guestfs(3).
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_selinux(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_selinux(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * enable or disable command traces
 *
 * If the command trace flag is set to 1, then libguestfs
 * calls, parameters and return values are traced.
 * 
 * If you want to trace C API calls into libguestfs (and
 * other libraries) then possibly a better way is to use
 * the external ltrace(1) command.
 * 
 * Command traces are disabled unless the environment
 * variable "LIBGUESTFS_TRACE" is defined and set to 1.
 * 
 * Trace messages are normally sent to "stderr", unless you
 * register a callback to send them somewhere else (see
 * "guestfs_set_event_callback").
 * 
 * @trace:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_trace(GuestfsSession *session, gboolean trace, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_trace(g, trace);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get command trace enabled flag
 *
 * Return the command trace flag.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_trace(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_trace(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * enable or disable direct appliance mode
 *
 * If the direct appliance mode flag is enabled, then stdin
 * and stdout are passed directly through to the appliance
 * once it is launched.
 * 
 * One consequence of this is that log messages aren't
 * caught by the library and handled by
 * "guestfs_set_log_message_callback", but go straight to
 * stdout.
 * 
 * You probably don't want to use this unless you know what
 * you are doing.
 * 
 * The default is disabled.
 * 
 * @direct:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_direct(GuestfsSession *session, gboolean direct, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_direct(g, direct);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get direct appliance mode flag
 *
 * Return the direct appliance mode flag.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_direct(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_direct(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * enable or disable the recovery process
 *
 * If this is called with the parameter "false" then
 * "guestfs_launch" does not create a recovery process. The
 * purpose of the recovery process is to stop runaway qemu
 * processes in the case where the main program aborts
 * abruptly.
 * 
 * This only has any effect if called before
 * "guestfs_launch", and the default is true.
 * 
 * About the only time when you would want to disable this
 * is if the main process will fork itself into the
 * background ("daemonize" itself). In this case the
 * recovery process thinks that the main program has
 * disappeared and so kills qemu, which is not very
 * helpful.
 * 
 * @recoveryproc:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_recovery_proc(GuestfsSession *session, gboolean recoveryproc, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_recovery_proc(g, recoveryproc);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get recovery process enabled flag
 *
 * Return the recovery process enabled flag.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_recovery_proc(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_recovery_proc(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * add a drive specifying the QEMU block emulation to use
 *
 * This is the same as "guestfs_add_drive" but it allows
 * you to specify the QEMU interface emulation to use at
 * run time.
 * 
 * @filename: (transfer none) (type utf8):
 * @iface: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_add_drive_with_if(GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_add_drive_with_if(g, filename, iface);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add a drive read-only specifying the QEMU block emulation to use
 *
 * This is the same as "guestfs_add_drive_ro" but it allows
 * you to specify the QEMU interface emulation to use at
 * run time.
 * 
 * @filename: (transfer none) (type utf8):
 * @iface: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_add_drive_ro_with_if(GuestfsSession *session, const gchar *filename, const gchar *iface, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_add_drive_ro_with_if(g, filename, iface);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * detect the architecture of a binary file
 *
 * This detects the architecture of the binary "filename",
 * and returns it if known.
 * 
 * Currently defined architectures are:
 * 
 * "i386"
 * This string is returned for all 32 bit i386, i486,
 * i586, i686 binaries irrespective of the precise
 * processor requirements of the binary.
 * 
 * "x86_64"
 * 64 bit x86-64.
 * 
 * "sparc"
 * 32 bit SPARC.
 * 
 * "sparc64"
 * 64 bit SPARC V9 and above.
 * 
 * "ia64"
 * Intel Itanium.
 * 
 * "ppc"
 * 32 bit Power PC.
 * 
 * "ppc64"
 * 64 bit Power PC.
 * 
 * Libguestfs may return other architecture strings in
 * future.
 * 
 * The function works on at least the following types of
 * files:
 * 
 * *   many types of Un*x and Linux binary
 * 
 * *   many types of Un*x and Linux shared library
 * 
 * *   Windows Win32 and Win64 binaries
 * 
 * *   Windows Win32 and Win64 DLLs
 * 
 * Win32 binaries and DLLs return "i386".
 * 
 * Win64 binaries and DLLs return "x86_64".
 * 
 * *   Linux kernel modules
 * 
 * *   Linux new-style initrd images
 * 
 * *   some non-x86 Linux vmlinuz kernels
 * 
 * What it can't do currently:
 * 
 * *   static libraries (libfoo.a)
 * 
 * *   Linux old-style initrd as compressed ext2 filesystem
 * (RHEL 3)
 * 
 * *   x86 Linux vmlinuz kernels
 * 
 * x86 vmlinuz images (bzImage format) consist of a mix
 * of 16-, 32- and compressed code, and are horribly
 * hard to unpack. If you want to find the architecture
 * of a kernel, use the architecture of the associated
 * initrd or kernel module(s) instead.
 * 
 * @filename: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_file_architecture(GuestfsSession *session, const gchar *filename, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_file_architecture(g, filename);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * inspect disk and return list of operating systems found
 *
 * This function uses other libguestfs functions and
 * certain heuristics to inspect the disk(s) (usually disks
 * belonging to a virtual machine), looking for operating
 * systems.
 * 
 * The list returned is empty if no operating systems were
 * found.
 * 
 * If one operating system was found, then this returns a
 * list with a single element, which is the name of the
 * root filesystem of this operating system. It is also
 * possible for this function to return a list containing
 * more than one element, indicating a dual-boot or
 * multi-boot virtual machine, with each element being the
 * root filesystem of one of the operating systems.
 * 
 * You can pass the root string(s) returned to other
 * "guestfs_inspect_get_*" functions in order to query
 * further information about each operating system, such as
 * the name and version.
 * 
 * This function uses other libguestfs features such as
 * "guestfs_mount_ro" and "guestfs_umount_all" in order to
 * mount and unmount filesystems and look at the contents.
 * This should be called with no disks currently mounted.
 * The function may also use Augeas, so any existing Augeas
 * handle will be closed.
 * 
 * This function cannot decrypt encrypted disks. The caller
 * must do that first (supplying the necessary keys) if the
 * disk is encrypted.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * See also "guestfs_list_filesystems".
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_inspect_os(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_inspect_os(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get type of inspected operating system
 *
 * This returns the type of the inspected operating system.
 * Currently defined types are:
 * 
 * "linux"
 * Any Linux-based operating system.
 * 
 * "windows"
 * Any Microsoft Windows operating system.
 * 
 * "freebsd"
 * FreeBSD.
 * 
 * "netbsd"
 * NetBSD.
 * 
 * "hurd"
 * GNU/Hurd.
 * 
 * "unknown"
 * The operating system type could not be determined.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_type(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_type(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get architecture of inspected operating system
 *
 * This returns the architecture of the inspected operating
 * system. The possible return values are listed under
 * "guestfs_file_architecture".
 * 
 * If the architecture could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_arch(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_arch(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get distro of inspected operating system
 *
 * This returns the distro (distribution) of the inspected
 * operating system.
 * 
 * Currently defined distros are:
 * 
 * "archlinux"
 * Arch Linux.
 * 
 * "centos"
 * CentOS.
 * 
 * "debian"
 * Debian.
 * 
 * "fedora"
 * Fedora.
 * 
 * "gentoo"
 * Gentoo.
 * 
 * "linuxmint"
 * Linux Mint.
 * 
 * "mageia"
 * Mageia.
 * 
 * "mandriva"
 * Mandriva.
 * 
 * "meego"
 * MeeGo.
 * 
 * "opensuse"
 * OpenSUSE.
 * 
 * "pardus"
 * Pardus.
 * 
 * "redhat-based"
 * Some Red Hat-derived distro.
 * 
 * "rhel"
 * Red Hat Enterprise Linux.
 * 
 * "scientificlinux"
 * Scientific Linux.
 * 
 * "slackware"
 * Slackware.
 * 
 * "ttylinux"
 * ttylinux.
 * 
 * "ubuntu"
 * Ubuntu.
 * 
 * "unknown"
 * The distro could not be determined.
 * 
 * "windows"
 * Windows does not have distributions. This string is
 * returned if the OS type is Windows.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_distro(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_distro(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get major version of inspected operating system
 *
 * This returns the major version number of the inspected
 * operating system.
 * 
 * Windows uses a consistent versioning scheme which is
 * *not* reflected in the popular public names used by the
 * operating system. Notably the operating system known as
 * "Windows 7" is really version 6.1 (ie. major = 6, minor
 * = 1). You can find out the real versions corresponding
 * to releases of Windows by consulting Wikipedia or MSDN.
 * 
 * If the version could not be determined, then 0 is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_inspect_get_major_version(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inspect_get_major_version(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get minor version of inspected operating system
 *
 * This returns the minor version number of the inspected
 * operating system.
 * 
 * If the version could not be determined, then 0 is
 * returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "guestfs_inspect_get_major_version".
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_inspect_get_minor_version(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inspect_get_minor_version(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get product name of inspected operating system
 *
 * This returns the product name of the inspected operating
 * system. The product name is generally some freeform
 * string which can be displayed to the user, but should
 * not be parsed by programs.
 * 
 * If the product name could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_product_name(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_product_name(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get mountpoints of inspected operating system
 *
 * This returns a hash of where we think the filesystems
 * associated with this operating system should be mounted.
 * Callers should note that this is at best an educated
 * guess made by reading configuration files such as
 * "/etc/fstab". *In particular note* that this may return
 * filesystems which are non-existent or not mountable and
 * callers should be prepared to handle or ignore failures
 * if they try to mount them.
 * 
 * Each element in the returned hashtable has a key which
 * is the path of the mountpoint (eg. "/boot") and a value
 * which is the filesystem that would be mounted there (eg.
 * "/dev/sda1").
 * 
 * Non-mounted devices such as swap devices are *not*
 * returned in this list.
 * 
 * For operating systems like Windows which still use drive
 * letters, this call will only return an entry for the
 * first drive "mounted on" "/". For information about the
 * mapping of drive letters to partitions, see
 * "guestfs_inspect_get_drive_mappings".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "guestfs_inspect_get_filesystems".
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_inspect_get_mountpoints(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_inspect_get_mountpoints(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * get filesystems associated with inspected operating system
 *
 * This returns a list of all the filesystems that we think
 * are associated with this operating system. This includes
 * the root filesystem, other ordinary filesystems, and
 * non-mounted devices like swap partitions.
 * 
 * In the case of a multi-boot virtual machine, it is
 * possible for a filesystem to be shared between operating
 * systems.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "guestfs_inspect_get_mountpoints".
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_inspect_get_filesystems(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_inspect_get_filesystems(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * set enable network flag
 *
 * If "network" is true, then the network is enabled in the
 * libguestfs appliance. The default is false.
 * 
 * This affects whether commands are able to access the
 * network (see "RUNNING COMMANDS" in guestfs(3)).
 * 
 * You must call this before calling "guestfs_launch",
 * otherwise it has no effect.
 * 
 * @network:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_network(GuestfsSession *session, gboolean network, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_network(g, network);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get enable network flag
 *
 * This returns the enable network flag.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_network(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_network(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * list filesystems
 *
 * This inspection command looks for filesystems on
 * partitions, block devices and logical volumes, returning
 * a list of devices containing filesystems and their type.
 * 
 * The return value is a hash, where the keys are the
 * devices containing filesystems, and the values are the
 * filesystem types. For example:
 * 
 * "/dev/sda1" => "ntfs"
 * "/dev/sda2" => "ext2"
 * "/dev/vg_guest/lv_root" => "ext4"
 * "/dev/vg_guest/lv_swap" => "swap"
 * 
 * The value can have the special value "unknown", meaning
 * the content of the device is undetermined or empty.
 * "swap" means a Linux swap partition.
 * 
 * This command runs other libguestfs commands, which might
 * include "guestfs_mount" and "guestfs_umount", and
 * therefore you should use this soon after launch and only
 * when nothing is mounted.
 * 
 * Not all of the filesystems returned will be mountable.
 * In particular, swap partitions are returned in the list.
 * Also this command does not check that each filesystem
 * found is valid and mountable, and some filesystems might
 * be mountable but require special options. Filesystems
 * may not all belong to a single logical operating system
 * (use "guestfs_inspect_os" to look for OSes).
 * 
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_list_filesystems(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_list_filesystems(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * add an image to examine or modify
 *
 * This function adds a virtual machine disk image
 * "filename" to libguestfs. The first time you call this
 * function, the disk appears as "/dev/sda", the second
 * time as "/dev/sdb", and so on.
 * 
 * You don't necessarily need to be root when using
 * libguestfs. However you obviously do need sufficient
 * permissions to access the filename for whatever
 * operations you want to perform (ie. read access if you
 * just want to read the image or write access if you want
 * to modify the image).
 * 
 * This call checks that "filename" exists.
 * 
 * The optional arguments are:
 * 
 * "readonly"
 * If true then the image is treated as read-only.
 * Writes are still allowed, but they are stored in a
 * temporary snapshot overlay which is discarded at the
 * end. The disk that you add is not modified.
 * 
 * "format"
 * This forces the image format. If you omit this (or
 * use "guestfs_add_drive" or "guestfs_add_drive_ro")
 * then the format is automatically detected. Possible
 * formats include "raw" and "qcow2".
 * 
 * Automatic detection of the format opens you up to a
 * potential security hole when dealing with untrusted
 * raw-format images. See CVE-2010-3851 and
 * RHBZ#642934. Specifying the format closes this
 * security hole.
 * 
 * "iface"
 * This rarely-used option lets you emulate the
 * behaviour of the deprecated
 * "guestfs_add_drive_with_if" call (q.v.)
 * 
 * "name"
 * The name the drive had in the original guest, e.g.
 * /dev/sdb. This is used as a hint to the guest
 * inspection process if it is available.
 * 
 * @filename: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsAddDriveOpts containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_add_drive_opts(GuestfsSession *session, const gchar *filename, GuestfsAddDriveOpts *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_add_drive_opts(g, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get Windows systemroot of inspected operating system
 *
 * This returns the Windows systemroot of the inspected
 * guest. The systemroot is a directory path such as
 * "/WINDOWS".
 * 
 * This call assumes that the guest is Windows and that the
 * systemroot could be determined by inspection. If this is
 * not the case then an error is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_windows_systemroot(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_windows_systemroot(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return list of operating systems found by last inspection
 *
 * This function is a convenient way to get the list of
 * root devices, as returned from a previous call to
 * "guestfs_inspect_os", but without redoing the whole
 * inspection process.
 * 
 * This returns an empty list if either no root devices
 * were found or the caller has not called
 * "guestfs_inspect_os".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_inspect_get_roots(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_inspect_get_roots(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * debug the QEMU command line (internal use only)
 *
 * This returns the internal QEMU command line. 'debug'
 * commands are not part of the formal API and can be
 * removed or changed at any time.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_debug_cmdline(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_debug_cmdline(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * debug the drives (internal use only)
 *
 * This returns the internal list of drives. 'debug'
 * commands are not part of the formal API and can be
 * removed or changed at any time.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_debug_drives(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_debug_drives(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * add the disk(s) from a named libvirt domain
 *
 * This function adds the disk(s) attached to the named
 * libvirt domain "dom". It works by connecting to libvirt,
 * requesting the domain and domain XML from libvirt,
 * parsing it for disks, and calling
 * "guestfs_add_drive_opts" on each one.
 * 
 * The number of disks added is returned. This operation is
 * atomic: if an error is returned, then no disks are
 * added.
 * 
 * This function does some minimal checks to make sure the
 * libvirt domain is not running (unless "readonly" is
 * true). In a future version we will try to acquire the
 * libvirt lock on each disk.
 * 
 * Disks must be accessible locally. This often means that
 * adding disks from a remote libvirt connection (see
 * <http://libvirt.org/remote.html>) will fail unless those
 * disks are accessible via the same device path locally
 * too.
 * 
 * The optional "libvirturi" parameter sets the libvirt URI
 * (see <http://libvirt.org/uri.html>). If this is not set
 * then we connect to the default libvirt URI (or one set
 * through an environment variable, see the libvirt
 * documentation for full details).
 * 
 * The optional "live" flag controls whether this call will
 * try to connect to a running virtual machine "guestfsd"
 * process if it sees a suitable <channel> element in the
 * libvirt XML definition. The default (if the flag is
 * omitted) is never to try. See "ATTACHING TO RUNNING
 * DAEMONS" in guestfs(3) for more information.
 * 
 * If the "allowuuid" flag is true (default is false) then
 * a UUID *may* be passed instead of the domain name. The
 * "dom" string is treated as a UUID first and looked up,
 * and if that lookup fails then we treat "dom" as a name
 * as usual.
 * 
 * The optional "readonlydisk" parameter controls what we
 * do for disks which are marked <readonly/> in the libvirt
 * XML. Possible values are:
 * 
 * readonlydisk = "error"
 * If "readonly" is false:
 * 
 * The whole call is aborted with an error if any disk
 * with the <readonly/> flag is found.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "read"
 * If "readonly" is false:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * Other disks are added read/write.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "write" (default)
 * If "readonly" is false:
 * 
 * Disks with the <readonly/> flag are added
 * read/write.
 * 
 * If "readonly" is true:
 * 
 * Disks with the <readonly/> flag are added read-only.
 * 
 * readonlydisk = "ignore"
 * If "readonly" is true or false:
 * 
 * Disks with the <readonly/> flag are skipped.
 * 
 * The other optional parameters are passed directly
 * through to "guestfs_add_drive_opts".
 * 
 * @dom: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsAddDomain containing optional arguments
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_add_domain(GuestfsSession *session, const gchar *dom, GuestfsAddDomain *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_add_domain(g, dom);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get package format used by the operating system
 *
 * This function and
 * "guestfs_inspect_get_package_management" return the
 * package format and package management tool used by the
 * inspected operating system. For example for Fedora these
 * functions would return "rpm" (package format) and "yum"
 * (package management).
 * 
 * This returns the string "unknown" if we could not
 * determine the package format *or* if the operating
 * system does not have a real packaging system (eg.
 * Windows).
 * 
 * Possible strings include: "rpm", "deb", "ebuild",
 * "pisi", "pacman", "pkgsrc". Future versions of
 * libguestfs may return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_package_format(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_package_format(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get package management tool used by the operating system
 *
 * "guestfs_inspect_get_package_format" and this function
 * return the package format and package management tool
 * used by the inspected operating system. For example for
 * Fedora these functions would return "rpm" (package
 * format) and "yum" (package management).
 * 
 * This returns the string "unknown" if we could not
 * determine the package management tool *or* if the
 * operating system does not have a real packaging system
 * (eg. Windows).
 * 
 * Possible strings include: "yum", "up2date", "apt" (for
 * all Debian derivatives), "portage", "pisi", "pacman",
 * "urpmi", "zypper". Future versions of libguestfs may
 * return other strings.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_package_management(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_package_management(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get list of applications installed in the operating system
 *
 * Return the list of applications installed in the
 * operating system.
 * 
 * *Note:* This call works differently from other parts of
 * the inspection API. You have to call
 * "guestfs_inspect_os", then
 * "guestfs_inspect_get_mountpoints", then mount up the
 * disks, before calling this. Listing applications is a
 * significantly more difficult operation which requires
 * access to the full filesystem. Also note that unlike the
 * other "guestfs_inspect_get_*" calls which are just
 * returning data cached in the libguestfs handle, this
 * call actually reads parts of the mounted filesystems
 * during the call.
 * 
 * This returns an empty list if the inspection code was
 * not able to determine the list of applications.
 * 
 * The application structure contains the following fields:
 * 
 * "app_name"
 * The name of the application. For Red Hat-derived and
 * Debian-derived Linux guests, this is the package
 * name.
 * 
 * "app_display_name"
 * The display name of the application, sometimes
 * localized to the install language of the guest
 * operating system.
 * 
 * If unavailable this is returned as an empty string
 * "". Callers needing to display something can use
 * "app_name" instead.
 * 
 * "app_epoch"
 * For package managers which use epochs, this contains
 * the epoch of the package (an integer). If
 * unavailable, this is returned as 0.
 * 
 * "app_version"
 * The version string of the application or package. If
 * unavailable this is returned as an empty string "".
 * 
 * "app_release"
 * The release string of the application or package,
 * for package managers that use this. If unavailable
 * this is returned as an empty string "".
 * 
 * "app_install_path"
 * The installation path of the application (on
 * operating systems such as Windows which use
 * installation paths). This path is in the format used
 * by the guest operating system, it is not a
 * libguestfs path.
 * 
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app_trans_path"
 * The install path translated into a libguestfs path.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * "app_publisher"
 * The name of the publisher of the application, for
 * package managers that use this. If unavailable this
 * is returned as an empty string "".
 * 
 * "app_url"
 * The URL (eg. upstream URL) of the application. If
 * unavailable this is returned as an empty string "".
 * 
 * "app_source_package"
 * For packaging systems which support this, the name
 * of the source package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app_summary"
 * A short (usually one line) description of the
 * application or package. If unavailable this is
 * returned as an empty string "".
 * 
 * "app_description"
 * A longer description of the application or package.
 * If unavailable this is returned as an empty string
 * "".
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type Application): an array of Application objects, or NULL on error
 */
GuestfsApplication **guestfs_session_inspect_list_applications(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_application_list *ret = guestfs_inspect_list_applications(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsInspectListApplications **l = g_malloc(sizeof GuestfsInspectListApplications* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsInspectListApplications *s = g_slice_new(GuestfsInspectListApplications);
    s->app_name = g_strdup(ret->val[i]->app_name);
    s->app_display_name = g_strdup(ret->val[i]->app_display_name);
    s->app_epoch = ret->val[i]->app_epoch;
    s->app_version = g_strdup(ret->val[i]->app_version);
    s->app_release = g_strdup(ret->val[i]->app_release);
    s->app_install_path = g_strdup(ret->val[i]->app_install_path);
    s->app_trans_path = g_strdup(ret->val[i]->app_trans_path);
    s->app_publisher = g_strdup(ret->val[i]->app_publisher);
    s->app_url = g_strdup(ret->val[i]->app_url);
    s->app_source_package = g_strdup(ret->val[i]->app_source_package);
    s->app_summary = g_strdup(ret->val[i]->app_summary);
    s->app_description = g_strdup(ret->val[i]->app_description);
  guestfs_free_application(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * get hostname of the operating system
 *
 * This function returns the hostname of the operating
 * system as found by inspection of the guest's
 * configuration files.
 * 
 * If the hostname could not be determined, then the string
 * "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_hostname(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_hostname(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get format of inspected operating system
 *
 * This returns the format of the inspected operating
 * system. You can use it to detect install images, live
 * CDs and similar.
 * 
 * Currently defined formats are:
 * 
 * "installed"
 * This is an installed operating system.
 * 
 * "installer"
 * The disk image being inspected is not an installed
 * operating system, but a *bootable* install disk,
 * live CD, or similar.
 * 
 * "unknown"
 * The format of this disk image is not known.
 * 
 * Future versions of libguestfs may return other strings
 * here. The caller should be prepared to handle any
 * string.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_format(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_format(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get live flag for install disk
 *
 * If "guestfs_inspect_get_format" returns "installer"
 * (this is an install disk), then this returns true if a
 * live image was detected on the disk.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_inspect_is_live(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inspect_is_live(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get netinst (network installer) flag for install disk
 *
 * If "guestfs_inspect_get_format" returns "installer"
 * (this is an install disk), then this returns true if the
 * disk is a network installer, ie. not a self-contained
 * install CD but one which is likely to require network
 * access to complete the install.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_inspect_is_netinst(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inspect_is_netinst(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get multipart flag for install disk
 *
 * If "guestfs_inspect_get_format" returns "installer"
 * (this is an install disk), then this returns true if the
 * disk is part of a set.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_inspect_is_multipart(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inspect_is_multipart(g, root);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * set the attach method
 *
 * Set the method that libguestfs uses to connect to the
 * back end guestfsd daemon. Possible methods are:
 * 
 * "appliance"
 * Launch an appliance and connect to it. This is the
 * ordinary method and the default.
 * 
 * "unix:*path*"
 * Connect to the Unix domain socket *path*.
 * 
 * This method lets you connect to an existing daemon
 * or (using virtio-serial) to a live guest. For more
 * information, see "ATTACHING TO RUNNING DAEMONS" in
 * guestfs(3).
 * 
 * @attachmethod: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_attach_method(GuestfsSession *session, const gchar *attachmethod, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_attach_method(g, attachmethod);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the attach method
 *
 * Return the current attach method. See
 * "guestfs_set_attach_method".
 * 
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_get_attach_method(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_get_attach_method(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get product variant of inspected operating system
 *
 * This returns the product variant of the inspected
 * operating system.
 * 
 * For Windows guests, this returns the contents of the
 * Registry key "HKLM\Software\Microsoft\Windows
 * NT\CurrentVersion" "InstallationType" which is usually a
 * string such as "Client" or "Server" (other values are
 * possible). This can be used to distinguish consumer and
 * enterprise versions of Windows that have the same
 * version number (for example, Windows 7 and Windows 2008
 * Server are both version 6.1, but the former is "Client"
 * and the latter is "Server").
 * 
 * For enterprise Linux guests, in future we intend this to
 * return the product variant such as "Desktop", "Server"
 * and so on. But this is not implemented at present.
 * 
 * If the product variant could not be determined, then the
 * string "unknown" is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "guestfs_inspect_get_product_name",
 * "guestfs_inspect_get_major_version".
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_product_variant(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_product_variant(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get Windows CurrentControlSet of inspected operating system
 *
 * This returns the Windows CurrentControlSet of the
 * inspected guest. The CurrentControlSet is a registry key
 * name such as "ControlSet001".
 * 
 * This call assumes that the guest is Windows and that the
 * Registry could be examined by inspection. If this is not
 * the case then an error is returned.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_inspect_get_windows_current_control_set(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_windows_current_control_set(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get drive letter mappings
 *
 * This call is useful for Windows which uses a primitive
 * system of assigning drive letters (like "C:") to
 * partitions. This inspection API examines the Windows
 * Registry to find out how disks/partitions are mapped to
 * drive letters, and returns a hash table as in the
 * example below:
 * 
 * C      =>     /dev/vda2
 * E      =>     /dev/vdb1
 * F      =>     /dev/vdc1
 * 
 * Note that keys are drive letters. For Windows, the key
 * is case insensitive and just contains the drive letter,
 * without the customary colon separator character.
 * 
 * In future we may support other operating systems that
 * also used drive letters, but the keys for those might
 * not be case insensitive and might be longer than 1
 * character. For example in OS-9, hard drives were named
 * "h0", "h1" etc.
 * 
 * For Windows guests, currently only hard drive mappings
 * are returned. Removable disks (eg. DVD-ROMs) are
 * ignored.
 * 
 * For guests that do not use drive mappings, or if the
 * drive mappings could not be determined, this returns an
 * empty hash table.
 * 
 * Please read "INSPECTION" in guestfs(3) for more details.
 * See also "guestfs_inspect_get_mountpoints",
 * "guestfs_inspect_get_filesystems".
 * 
 * @root: (transfer none) (type filename):
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_inspect_get_drive_mappings(GuestfsSession *session, const gchar *root, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_inspect_get_drive_mappings(g, root);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * get the icon corresponding to this operating system
 *
 * This function returns an icon corresponding to the
 * inspected operating system. The icon is returned as a
 * buffer containing a PNG image (re-encoded to PNG if
 * necessary).
 * 
 * If it was not possible to get an icon this function
 * returns a zero-length (non-NULL) buffer. *Callers must
 * check for this case*.
 * 
 * Libguestfs will start by looking for a file called
 * "/etc/favicon.png" or "C:\etc\favicon.png" and if it has
 * the correct format, the contents of this file will be
 * returned. You can disable favicons by passing the
 * optional "favicon" boolean as false (default is true).
 * 
 * If finding the favicon fails, then we look in other
 * places in the guest for a suitable icon.
 * 
 * If the optional "highquality" boolean is true then only
 * high quality icons are returned, which means only icons
 * of high resolution with an alpha channel. The default
 * (false) is to return any icon we can, even if it is of
 * substandard quality.
 * 
 * Notes:
 * 
 * *   Unlike most other inspection API calls, the guest's
 * disks must be mounted up before you call this, since
 * it needs to read information from the guest
 * filesystem during the call.
 * 
 * *   Security: The icon data comes from the untrusted
 * guest, and should be treated with caution. PNG files
 * have been known to contain exploits. Ensure that
 * libpng (or other relevant libraries) are fully up to
 * date before trying to process or display the icon.
 * 
 * *   The PNG image returned can be any size. It might not
 * be square. Libguestfs tries to return the largest,
 * highest quality icon available. The application must
 * scale the icon to the required size.
 * 
 * *   Extracting icons from Windows guests requires the
 * external "wrestool" program from the "icoutils"
 * package, and several programs ("bmptopnm",
 * "pnmtopng", "pamcut") from the "netpbm" package.
 * These must be installed separately.
 * 
 * *   Operating system icons are usually trademarks. Seek
 * legal advice before using trademarks in
 * applications.
 * 
 * @root: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsInspectGetIcon containing optional arguments
 *
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint *guestfs_session_inspect_get_icon(GuestfsSession *session, const gchar *root, GuestfsInspectGetIcon *optargs, gsize *size_r, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_inspect_get_icon(g, root, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * set process group flag
 *
 * If "pgroup" is true, child processes are placed into
 * their own process group.
 * 
 * The practical upshot of this is that signals like
 * "SIGINT" (from users pressing "^C") won't be received by
 * the child process.
 * 
 * The default for this flag is false, because usually you
 * want "^C" to kill the subprocess.
 * 
 * @pgroup:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_pgroup(GuestfsSession *session, gboolean pgroup, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_pgroup(g, pgroup);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get process group flag
 *
 * This returns the process group flag.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_get_pgroup(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_pgroup(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * set number of virtual CPUs in appliance
 *
 * Change the number of virtual CPUs assigned to the
 * appliance. The default is 1. Increasing this may improve
 * performance, though often it has no effect.
 * 
 * This function must be called before "guestfs_launch".
 * 
 * @smp:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_smp(GuestfsSession *session, gint32 smp, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_smp(g, smp);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get number of virtual CPUs in appliance
 *
 * This returns the number of virtual CPUs assigned to the
 * appliance.
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_get_smp(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_smp(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * mount a guest disk at a position in the filesystem
 *
 * Mount a guest disk at a position in the filesystem.
 * Block devices are named "/dev/sda", "/dev/sdb" and so
 * on, as they were added to the guest. If those block
 * devices contain partitions, they will have the usual
 * names (eg. "/dev/sda1"). Also LVM "/dev/VG/LV"-style
 * names can be used.
 * 
 * The rules are the same as for mount(2): A filesystem
 * must first be mounted on "/" before others can be
 * mounted. Other filesystems can only be mounted on
 * directories which already exist.
 * 
 * The mounted filesystem is writable, if we have
 * sufficient permissions on the underlying device.
 * 
 * Before libguestfs 1.13.16, this call implicitly added
 * the options "sync" and "noatime". The "sync" option
 * greatly slowed writes and caused many problems for
 * users. If your program might need to work with older
 * versions of libguestfs, use "guestfs_mount_options"
 * instead (using an empty string for the first parameter
 * if you don't want any options).
 * 
 * @device: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mount(GuestfsSession *session, const gchar *device, const gchar *mountpoint, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mount(g, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * sync disks, writes are flushed through to the disk image
 *
 * This syncs the disk, so that any writes are flushed
 * through to the underlying disk image.
 * 
 * You should always call this if you have modified a disk
 * image, before closing the handle.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_sync(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_sync(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * update file timestamps or create a new file
 *
 * Touch acts like the touch(1) command. It can be used to
 * update the timestamps on a file, or, if the file does
 * not exist, to create a new zero-length file.
 * 
 * This command only works on regular files, and will fail
 * on other file types such as directories, symbolic links,
 * block special etc.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_touch(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_touch(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * list the contents of a file
 *
 * Return the contents of the file named "path".
 * 
 * Note that this function cannot correctly handle binary
 * files (specifically, files containing "\0" character
 * which is treated as end of string). For those you need
 * to use the "guestfs_read_file" or "guestfs_download"
 * functions which have a more complex interface.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_cat(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_cat(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the files in a directory (long format)
 *
 * List the files in "directory" (relative to the root
 * directory, there is no cwd) in the format of 'ls -la'.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string.
 * 
 * @directory: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_ll(GuestfsSession *session, const gchar *directory, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_ll(g, directory);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the files in a directory
 *
 * List the files in "directory" (relative to the root
 * directory, there is no cwd). The '.' and '..' entries
 * are not returned, but hidden files are shown.
 * 
 * This command is mostly useful for interactive sessions.
 * Programs should probably use "guestfs_readdir" instead.
 * 
 * @directory: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_ls(GuestfsSession *session, const gchar *directory, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_ls(g, directory);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the block devices
 *
 * List all the block devices.
 * 
 * The full block device names are returned, eg.
 * "/dev/sda".
 * 
 * See also "guestfs_list_filesystems".
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_list_devices(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_list_devices(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the partitions
 *
 * List all the partitions detected on all block devices.
 * 
 * The full partition device names are returned, eg.
 * "/dev/sda1"
 * 
 * This does not return logical volumes. For that you will
 * need to call "guestfs_lvs".
 * 
 * See also "guestfs_list_filesystems".
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_list_partitions(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_list_partitions(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the
 * equivalent of the pvs(8) command.
 * 
 * This returns a list of just the device names that
 * contain PVs (eg. "/dev/sda2").
 * 
 * See also "guestfs_pvs_full".
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_pvs(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_pvs(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the
 * equivalent of the vgs(8) command.
 * 
 * This returns a list of just the volume group names that
 * were detected (eg. "VolGroup00").
 * 
 * See also "guestfs_vgs_full".
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_vgs(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_vgs(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the
 * equivalent of the lvs(8) command.
 * 
 * This returns a list of the logical volume device names
 * (eg. "/dev/VolGroup00/LogVol00").
 * 
 * See also "guestfs_lvs_full", "guestfs_list_filesystems".
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_lvs(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_lvs(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list the LVM physical volumes (PVs)
 *
 * List all the physical volumes detected. This is the
 * equivalent of the pvs(8) command. The "full" version
 * includes all fields.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type PV): an array of PV objects, or NULL on error
 */
GuestfsPV **guestfs_session_pvs_full(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_lvm_pv_list *ret = guestfs_pvs_full(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPvsFull **l = g_malloc(sizeof GuestfsPvsFull* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsPvsFull *s = g_slice_new(GuestfsPvsFull);
    s->pv_name = g_strdup(ret->val[i]->pv_name);
    s->pv_uuid = ret->val[i]->pv_uuid;
    s->pv_fmt = g_strdup(ret->val[i]->pv_fmt);
    s->pv_size = ret->val[i]->pv_size;
    s->dev_size = ret->val[i]->dev_size;
    s->pv_free = ret->val[i]->pv_free;
    s->pv_used = ret->val[i]->pv_used;
    s->pv_attr = g_strdup(ret->val[i]->pv_attr);
    s->pv_pe_count = ret->val[i]->pv_pe_count;
    s->pv_pe_alloc_count = ret->val[i]->pv_pe_alloc_count;
    s->pv_tags = g_strdup(ret->val[i]->pv_tags);
    s->pe_start = ret->val[i]->pe_start;
    s->pv_mda_count = ret->val[i]->pv_mda_count;
    s->pv_mda_free = ret->val[i]->pv_mda_free;
  guestfs_free_lvm_pv(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * list the LVM volume groups (VGs)
 *
 * List all the volumes groups detected. This is the
 * equivalent of the vgs(8) command. The "full" version
 * includes all fields.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type VG): an array of VG objects, or NULL on error
 */
GuestfsVG **guestfs_session_vgs_full(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_lvm_vg_list *ret = guestfs_vgs_full(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsVgsFull **l = g_malloc(sizeof GuestfsVgsFull* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsVgsFull *s = g_slice_new(GuestfsVgsFull);
    s->vg_name = g_strdup(ret->val[i]->vg_name);
    s->vg_uuid = ret->val[i]->vg_uuid;
    s->vg_fmt = g_strdup(ret->val[i]->vg_fmt);
    s->vg_attr = g_strdup(ret->val[i]->vg_attr);
    s->vg_size = ret->val[i]->vg_size;
    s->vg_free = ret->val[i]->vg_free;
    s->vg_sysid = g_strdup(ret->val[i]->vg_sysid);
    s->vg_extent_size = ret->val[i]->vg_extent_size;
    s->vg_extent_count = ret->val[i]->vg_extent_count;
    s->vg_free_count = ret->val[i]->vg_free_count;
    s->max_lv = ret->val[i]->max_lv;
    s->max_pv = ret->val[i]->max_pv;
    s->pv_count = ret->val[i]->pv_count;
    s->lv_count = ret->val[i]->lv_count;
    s->snap_count = ret->val[i]->snap_count;
    s->vg_seqno = ret->val[i]->vg_seqno;
    s->vg_tags = g_strdup(ret->val[i]->vg_tags);
    s->vg_mda_count = ret->val[i]->vg_mda_count;
    s->vg_mda_free = ret->val[i]->vg_mda_free;
  guestfs_free_lvm_vg(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * list the LVM logical volumes (LVs)
 *
 * List all the logical volumes detected. This is the
 * equivalent of the lvs(8) command. The "full" version
 * includes all fields.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type LV): an array of LV objects, or NULL on error
 */
GuestfsLV **guestfs_session_lvs_full(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_lvm_lv_list *ret = guestfs_lvs_full(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsLvsFull **l = g_malloc(sizeof GuestfsLvsFull* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsLvsFull *s = g_slice_new(GuestfsLvsFull);
    s->lv_name = g_strdup(ret->val[i]->lv_name);
    s->lv_uuid = ret->val[i]->lv_uuid;
    s->lv_attr = g_strdup(ret->val[i]->lv_attr);
    s->lv_major = ret->val[i]->lv_major;
    s->lv_minor = ret->val[i]->lv_minor;
    s->lv_kernel_major = ret->val[i]->lv_kernel_major;
    s->lv_kernel_minor = ret->val[i]->lv_kernel_minor;
    s->lv_size = ret->val[i]->lv_size;
    s->seg_count = ret->val[i]->seg_count;
    s->origin = g_strdup(ret->val[i]->origin);
    s->snap_percent = ret->val[i]->snap_percent;
    s->copy_percent = ret->val[i]->copy_percent;
    s->move_pv = g_strdup(ret->val[i]->move_pv);
    s->lv_tags = g_strdup(ret->val[i]->lv_tags);
    s->mirror_log = g_strdup(ret->val[i]->mirror_log);
    s->modules = g_strdup(ret->val[i]->modules);
  guestfs_free_lvm_lv(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * read file as lines
 *
 * Return the contents of the file named "path".
 * 
 * The file contents are returned as a list of lines.
 * Trailing "LF" and "CRLF" character sequences are *not*
 * returned.
 * 
 * Note that this function cannot correctly handle binary
 * files (specifically, files containing "\0" character
 * which is treated as end of line). For those you need to
 * use the "guestfs_read_file" function which has a more
 * complex interface.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_read_lines(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_read_lines(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * create a new Augeas handle
 *
 * Create a new Augeas handle for editing configuration
 * files. If there was any previous Augeas handle
 * associated with this guestfs session, then it is closed.
 * 
 * You must call this before using any other
 * "guestfs_aug_*" commands.
 * 
 * "root" is the filesystem root. "root" must not be NULL,
 * use "/" instead.
 * 
 * The flags are the same as the flags defined in
 * <augeas.h>, the logical *or* of the following integers:
 * 
 * "AUG_SAVE_BACKUP" = 1
 * Keep the original file with a ".augsave" extension.
 * 
 * "AUG_SAVE_NEWFILE" = 2
 * Save changes into a file with extension ".augnew",
 * and do not overwrite original. Overrides
 * "AUG_SAVE_BACKUP".
 * 
 * "AUG_TYPE_CHECK" = 4
 * Typecheck lenses.
 * 
 * This option is only useful when debugging Augeas
 * lenses. Use of this option may require additional
 * memory for the libguestfs appliance. You may need to
 * set the "LIBGUESTFS_MEMSIZE" environment variable or
 * call "guestfs_set_memsize".
 * 
 * "AUG_NO_STDINC" = 8
 * Do not use standard load path for modules.
 * 
 * "AUG_SAVE_NOOP" = 16
 * Make save a no-op, just record what would have been
 * changed.
 * 
 * "AUG_NO_LOAD" = 32
 * Do not load the tree in "guestfs_aug_init".
 * 
 * To close the handle, you can call "guestfs_aug_close".
 * 
 * To find out more about Augeas, see <http://augeas.net/>.
 * 
 * @root: (transfer none) (type filename):
 * @flags:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_init(GuestfsSession *session, const gchar *root, gint32 flags, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_init(g, root, flags);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * close the current Augeas handle
 *
 * Close the current Augeas handle and free up any
 * resources used by it. After calling this, you have to
 * call "guestfs_aug_init" again before you can use any
 * other Augeas functions.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_close(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_close(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * define an Augeas variable
 *
 * Defines an Augeas variable "name" whose value is the
 * result of evaluating "expr". If "expr" is NULL, then
 * "name" is undefined.
 * 
 * On success this returns the number of nodes in "expr",
 * or 0 if "expr" evaluates to something which is not a
 * nodeset.
 * 
 * @name: (transfer none) (type utf8):
 * @expr: (transfer none) (type utf8) (allow-none):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_aug_defvar(GuestfsSession *session, const gchar *name, const gchar *expr, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_defvar(g, name, expr);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * define an Augeas node
 *
 * Defines a variable "name" whose value is the result of
 * evaluating "expr".
 * 
 * If "expr" evaluates to an empty nodeset, a node is
 * created, equivalent to calling "guestfs_aug_set" "expr",
 * "value". "name" will be the nodeset containing that
 * single node.
 * 
 * On success this returns a pair containing the number of
 * nodes in the nodeset, and a boolean flag if a node was
 * created.
 * 
 * @name: (transfer none) (type utf8):
 * @expr: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 *
 * Returns: (transfer full): a IntBool object, or NULL on error
 */
GuestfsIntBool *guestfs_session_aug_defnode(GuestfsSession *session, const gchar *name, const gchar *expr, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_int_bool *ret = guestfs_aug_defnode(g, name, expr, val);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsAugDefnode *s = g_slice_new(GuestfsAugDefnode);
  s->i = ret->i;
  s->b = ret->b;
  guestfs_free_int_bool(ret);
  return s;
}

/**
 * look up the value of an Augeas path
 *
 * Look up the value associated with "path". If "path"
 * matches exactly one node, the "value" is returned.
 * 
 * @augpath: (transfer none) (type utf8):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_aug_get(GuestfsSession *session, const gchar *augpath, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_aug_get(g, augpath);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * set Augeas path to value
 *
 * Set the value associated with "path" to "val".
 * 
 * In the Augeas API, it is possible to clear a node by
 * setting the value to NULL. Due to an oversight in the
 * libguestfs API you cannot do that with this call.
 * Instead you must use the "guestfs_aug_clear" call.
 * 
 * @augpath: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_set(GuestfsSession *session, const gchar *augpath, const gchar *val, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_set(g, augpath, val);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * insert a sibling Augeas node
 *
 * Create a new sibling "label" for "path", inserting it
 * into the tree before or after "path" (depending on the
 * boolean flag "before").
 * 
 * "path" must match exactly one existing node in the tree,
 * and "label" must be a label, ie. not contain "/", "*" or
 * end with a bracketed index "[N]".
 * 
 * @augpath: (transfer none) (type utf8):
 * @label: (transfer none) (type utf8):
 * @before:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_insert(GuestfsSession *session, const gchar *augpath, const gchar *label, gboolean before, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_insert(g, augpath, label, before);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove an Augeas path
 *
 * Remove "path" and all of its children.
 * 
 * On success this returns the number of entries which were
 * removed.
 * 
 * @augpath: (transfer none) (type utf8):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_aug_rm(GuestfsSession *session, const gchar *augpath, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_rm(g, augpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * move Augeas node
 *
 * Move the node "src" to "dest". "src" must match exactly
 * one node. "dest" is overwritten if it exists.
 * 
 * @src: (transfer none) (type utf8):
 * @dest: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_mv(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_mv(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * return Augeas nodes which match augpath
 *
 * Returns a list of paths which match the path expression
 * "path". The returned paths are sufficiently qualified so
 * that they match exactly one node in the current tree.
 * 
 * @augpath: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_aug_match(GuestfsSession *session, const gchar *augpath, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_aug_match(g, augpath);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * write all pending Augeas changes to disk
 *
 * This writes all pending changes to disk.
 * 
 * The flags which were passed to "guestfs_aug_init" affect
 * exactly how files are saved.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_save(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_save(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * load files into the tree
 *
 * Load files into the tree.
 * 
 * See "aug_load" in the Augeas documentation for the full
 * gory details.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_load(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_load(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * list Augeas nodes under augpath
 *
 * This is just a shortcut for listing "guestfs_aug_match"
 * "path/*" and sorting the resulting nodes into
 * alphabetical order.
 * 
 * @augpath: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_aug_ls(GuestfsSession *session, const gchar *augpath, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_aug_ls(g, augpath);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * remove a file
 *
 * Remove the single file "path".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_rm(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_rm(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove a directory
 *
 * Remove the single directory "path".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_rmdir(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_rmdir(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove a file or directory recursively
 *
 * Remove the file or directory "path", recursively
 * removing the contents if its a directory. This is like
 * the "rm -rf" shell command.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_rm_rf(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_rm_rf(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a directory
 *
 * Create a directory named "path".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkdir(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkdir(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a directory and parents
 *
 * Create a directory named "path", creating any parent
 * directories as necessary. This is like the "mkdir -p"
 * shell command.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkdir_p(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkdir_p(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * change file mode
 *
 * Change the mode (permissions) of "path" to "mode". Only
 * numeric modes are supported.
 * 
 * *Note*: When using this command from guestfish, "mode"
 * by default would be decimal, unless you prefix it with 0
 * to get octal, ie. use 0700 not 700.
 * 
 * The mode actually set is affected by the umask.
 * 
 * @mode:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_chmod(GuestfsSession *session, gint32 mode, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_chmod(g, mode, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * change file owner and group
 *
 * Change the file owner to "owner" and group to "group".
 * 
 * Only numeric uid and gid are supported. If you want to
 * use names, you will need to locate and parse the
 * password file yourself (Augeas support makes this
 * relatively easy).
 * 
 * @owner:
 * @group:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_chown(GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_chown(g, owner, group, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * test if file or directory exists
 *
 * This returns "true" if and only if there is a file,
 * directory (or anything) with the given "path" name.
 * 
 * See also "guestfs_is_file", "guestfs_is_dir",
 * "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_exists(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_exists(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * test if a regular file
 *
 * This returns "true" if and only if there is a regular
 * file with the given "path" name. Note that it returns
 * false for other objects like directories.
 * 
 * See also "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_file(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_file(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * test if a directory
 *
 * This returns "true" if and only if there is a directory
 * with the given "path" name. Note that it returns false
 * for other objects like files.
 * 
 * See also "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_dir(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_dir(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * create an LVM physical volume
 *
 * This creates an LVM physical volume on the named
 * "device", where "device" should usually be a partition
 * name such as "/dev/sda1".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_pvcreate(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_pvcreate(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create an LVM volume group
 *
 * This creates an LVM volume group called "volgroup" from
 * the non-empty list of physical volumes "physvols".
 * 
 * @volgroup: (transfer none) (type utf8):
 * @physvols: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_vgcreate(GuestfsSession *session, const gchar *volgroup, const gchar **physvols, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_vgcreate(g, volgroup, physvols);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create an LVM logical volume
 *
 * This creates an LVM logical volume called "logvol" on
 * the volume group "volgroup", with "size" megabytes.
 * 
 * @logvol: (transfer none) (type utf8):
 * @volgroup: (transfer none) (type utf8):
 * @mbytes:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvcreate(GuestfsSession *session, const gchar *logvol, const gchar *volgroup, gint32 mbytes, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvcreate(g, logvol, volgroup, mbytes);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make a filesystem
 *
 * This creates a filesystem on "device" (usually a
 * partition or LVM logical volume). The filesystem type is
 * "fstype", for example "ext3".
 * 
 * @fstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkfs(GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkfs(g, fstype, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create partitions on a block device
 *
 * This is a direct interface to the sfdisk(8) program for
 * creating partitions on block devices.
 * 
 * "device" should be a block device, for example
 * "/dev/sda".
 * 
 * "cyls", "heads" and "sectors" are the number of
 * cylinders, heads and sectors on the device, which are
 * passed directly to sfdisk as the *-C*, *-H* and *-S*
 * parameters. If you pass 0 for any of these, then the
 * corresponding parameter is omitted. Usually for 'large'
 * disks, you can just pass 0 for these, but for small
 * (floppy-sized) disks, sfdisk (or rather, the kernel)
 * cannot work out the right geometry and you will need to
 * tell it.
 * 
 * "lines" is a list of lines that we feed to "sfdisk". For
 * more information refer to the sfdisk(8) manpage.
 * 
 * To create a single partition occupying the whole disk,
 * you would pass "lines" as a single element list, when
 * the single element being the string "," (comma).
 * 
 * See also: "guestfs_sfdisk_l", "guestfs_sfdisk_N",
 * "guestfs_part_init"
 * 
 * @device: (transfer none) (type filename):
 * @cyls:
 * @heads:
 * @sectors:
 * @lines: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_sfdisk(GuestfsSession *session, const gchar *device, gint32 cyls, gint32 heads, gint32 sectors, const gchar **lines, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_sfdisk(g, device, cyls, heads, sectors, lines);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a file
 *
 * This call creates a file called "path". The contents of
 * the file is the string "content" (which can contain any
 * 8 bit data), with length "size".
 * 
 * As a special case, if "size" is 0 then the length is
 * calculated using "strlen" (so in this case the content
 * cannot contain embedded ASCII NULs).
 * 
 * *NB.* Owing to a bug, writing content containing ASCII
 * NUL characters does *not* work, even if the length is
 * specified.
 * 
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (type utf8):
 * @size:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_write_file(GuestfsSession *session, const gchar *path, const gchar *content, gint32 size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_write_file(g, path, content, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * unmount a filesystem
 *
 * This unmounts the given filesystem. The filesystem may
 * be specified either by its mountpoint (path) or the
 * device which contains the filesystem.
 * 
 * @pathordevice: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_umount(GuestfsSession *session, const gchar *pathordevice, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_umount(g, pathordevice);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * show mounted filesystems
 *
 * This returns the list of currently mounted filesystems.
 * It returns the list of devices (eg. "/dev/sda1",
 * "/dev/VG/LV").
 * 
 * Some internal mounts are not shown.
 * 
 * See also: "guestfs_mountpoints"
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_mounts(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_mounts(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * unmount all filesystems
 *
 * This unmounts all mounted filesystems.
 * 
 * Some internal mounts are not unmounted by this call.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_umount_all(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_umount_all(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove all LVM LVs, VGs and PVs
 *
 * This command removes all LVM logical volumes, volume
 * groups and physical volumes.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvm_remove_all(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvm_remove_all(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * determine file type
 *
 * This call uses the standard file(1) command to determine
 * the type or contents of the file.
 * 
 * This call will also transparently look inside various
 * types of compressed file.
 * 
 * The exact command which runs is "file -zb path". Note in
 * particular that the filename is not prepended to the
 * output (the *-b* option).
 * 
 * The output depends on the output of the underlying
 * file(1) command and it can change in future in ways
 * beyond our control. In other words, the output is not
 * guaranteed by the ABI.
 * 
 * See also: file(1), "guestfs_vfs_type", "guestfs_lstat",
 * "guestfs_is_file", "guestfs_is_blockdev" (etc),
 * "guestfs_is_zero".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_file(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_file(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * run a command from the guest filesystem
 *
 * This call runs a command from the guest filesystem. The
 * filesystem must be mounted, and must contain a
 * compatible operating system (ie. something Linux, with
 * the same or compatible processor architecture).
 * 
 * The single parameter is an argv-style list of arguments.
 * The first element is the name of the program to run.
 * Subsequent elements are parameters. The list must be
 * non-empty (ie. must contain a program name). Note that
 * the command runs directly, and is *not* invoked via the
 * shell (see "guestfs_sh").
 * 
 * The return value is anything printed to *stdout* by the
 * command.
 * 
 * If the command returns a non-zero exit status, then this
 * function returns an error message. The error message
 * string is the content of *stderr* from the command.
 * 
 * The $PATH environment variable will contain at least
 * "/usr/bin" and "/bin". If you require a program from
 * another location, you should provide the full path in
 * the first parameter.
 * 
 * Shared libraries and data files required by the program
 * must be available on filesystems which are mounted in
 * the correct places. It is the caller's responsibility to
 * ensure all filesystems that are needed are mounted at
 * the right locations.
 * 
 * @arguments: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_command(GuestfsSession *session, const gchar **arguments, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_command(g, arguments);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * run a command, returning lines
 *
 * This is the same as "guestfs_command", but splits the
 * result into a list of lines.
 * 
 * See also: "guestfs_sh_lines"
 * 
 * @arguments: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_command_lines(GuestfsSession *session, const gchar **arguments, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_command_lines(g, arguments);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get file information
 *
 * Returns file information for the given "path".
 * 
 * This is the same as the stat(2) system call.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): a Stat object, or NULL on error
 */
GuestfsStat *guestfs_session_stat(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_stat *ret = guestfs_stat(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsStat *s = g_slice_new(GuestfsStat);
  s->dev = ret->dev;
  s->ino = ret->ino;
  s->mode = ret->mode;
  s->nlink = ret->nlink;
  s->uid = ret->uid;
  s->gid = ret->gid;
  s->rdev = ret->rdev;
  s->size = ret->size;
  s->blksize = ret->blksize;
  s->blocks = ret->blocks;
  s->atime = ret->atime;
  s->mtime = ret->mtime;
  s->ctime = ret->ctime;
  guestfs_free_stat(ret);
  return s;
}

/**
 * get file information for a symbolic link
 *
 * Returns file information for the given "path".
 * 
 * This is the same as "guestfs_stat" except that if "path"
 * is a symbolic link, then the link is stat-ed, not the
 * file it refers to.
 * 
 * This is the same as the lstat(2) system call.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): a Stat object, or NULL on error
 */
GuestfsStat *guestfs_session_lstat(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_stat *ret = guestfs_lstat(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsLstat *s = g_slice_new(GuestfsLstat);
  s->dev = ret->dev;
  s->ino = ret->ino;
  s->mode = ret->mode;
  s->nlink = ret->nlink;
  s->uid = ret->uid;
  s->gid = ret->gid;
  s->rdev = ret->rdev;
  s->size = ret->size;
  s->blksize = ret->blksize;
  s->blocks = ret->blocks;
  s->atime = ret->atime;
  s->mtime = ret->mtime;
  s->ctime = ret->ctime;
  guestfs_free_stat(ret);
  return s;
}

/**
 * get file system statistics
 *
 * Returns file system statistics for any mounted file
 * system. "path" should be a file or directory in the
 * mounted file system (typically it is the mount point
 * itself, but it doesn't need to be).
 * 
 * This is the same as the statvfs(2) system call.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): a StatVFS object, or NULL on error
 */
GuestfsStatVFS *guestfs_session_statvfs(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_statvfs *ret = guestfs_statvfs(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsStatvfs *s = g_slice_new(GuestfsStatvfs);
  s->bsize = ret->bsize;
  s->frsize = ret->frsize;
  s->blocks = ret->blocks;
  s->bfree = ret->bfree;
  s->bavail = ret->bavail;
  s->files = ret->files;
  s->ffree = ret->ffree;
  s->favail = ret->favail;
  s->fsid = ret->fsid;
  s->flag = ret->flag;
  s->namemax = ret->namemax;
  guestfs_free_statvfs(ret);
  return s;
}

/**
 * get ext2/ext3/ext4 superblock details
 *
 * This returns the contents of the ext2, ext3 or ext4
 * filesystem superblock on "device".
 * 
 * It is the same as running "tune2fs -l device". See
 * tune2fs(8) manpage for more details. The list of fields
 * returned isn't clearly defined, and depends on both the
 * version of "tune2fs" that libguestfs was built against,
 * and the filesystem itself.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_tune2fs_l(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_tune2fs_l(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * set block device to read-only
 *
 * Sets the block device named "device" to read-only.
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_blockdev_setro(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_setro(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set block device to read-write
 *
 * Sets the block device named "device" to read-write.
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_blockdev_setrw(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_setrw(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * is block device set to read-only
 *
 * Returns a boolean indicating if the block device is
 * read-only (true if read-only, false if not).
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_blockdev_getro(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_getro(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get sectorsize of block device
 *
 * This returns the size of sectors on a block device.
 * Usually 512, but can be larger for modern devices.
 * 
 * (Note, this is not the size in sectors, use
 * "guestfs_blockdev_getsz" for that).
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_blockdev_getss(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_getss(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get blocksize of block device
 *
 * This returns the block size of a device.
 * 
 * (Note this is different from both *size in blocks* and
 * *filesystem block size*).
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_blockdev_getbsz(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_getbsz(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * set blocksize of block device
 *
 * This sets the block size of a device.
 * 
 * (Note this is different from both *size in blocks* and
 * *filesystem block size*).
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 * @blocksize:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_blockdev_setbsz(GuestfsSession *session, const gchar *device, gint32 blocksize, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_setbsz(g, device, blocksize);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get total size of device in 512-byte sectors
 *
 * This returns the size of the device in units of 512-byte
 * sectors (even if the sectorsize isn't 512 bytes ...
 * weird).
 * 
 * See also "guestfs_blockdev_getss" for the real sector
 * size of the device, and "guestfs_blockdev_getsize64" for
 * the more useful *size in bytes*.
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint64 guestfs_session_blockdev_getsz(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int64_t ret = guestfs_blockdev_getsz(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get total size of device in bytes
 *
 * This returns the size of the device in bytes.
 * 
 * See also "guestfs_blockdev_getsz".
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint64 guestfs_session_blockdev_getsize64(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int64_t ret = guestfs_blockdev_getsize64(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * flush device buffers
 *
 * This tells the kernel to flush internal buffers
 * associated with "device".
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_blockdev_flushbufs(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_flushbufs(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * reread partition table
 *
 * Reread the partition table on "device".
 * 
 * This uses the blockdev(8) command.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_blockdev_rereadpt(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_blockdev_rereadpt(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * upload a file from the local machine
 *
 * Upload local file "filename" to "remotefilename" on the
 * filesystem.
 * 
 * "filename" can also be a named pipe.
 * 
 * See also "guestfs_download".
 * 
 * @filename: (transfer none) (type filename):
 * @remotefilename: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_upload(GuestfsSession *session, const gchar *filename, const gchar *remotefilename, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_upload(g, filename, remotefilename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * download a file to the local machine
 *
 * Download file "remotefilename" and save it as "filename"
 * on the local machine.
 * 
 * "filename" can also be a named pipe.
 * 
 * See also "guestfs_upload", "guestfs_cat".
 * 
 * @remotefilename: (transfer none) (type filename):
 * @filename: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_download(GuestfsSession *session, const gchar *remotefilename, const gchar *filename, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_download(g, remotefilename, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * compute MD5, SHAx or CRC checksum of file
 *
 * This call computes the MD5, SHAx or CRC checksum of the
 * file named "path".
 * 
 * The type of checksum to compute is given by the
 * "csumtype" parameter which must have one of the
 * following values:
 * 
 * "crc"
 * Compute the cyclic redundancy check (CRC) specified
 * by POSIX for the "cksum" command.
 * 
 * "md5"
 * Compute the MD5 hash (using the "md5sum" program).
 * 
 * "sha1"
 * Compute the SHA1 hash (using the "sha1sum" program).
 * 
 * "sha224"
 * Compute the SHA224 hash (using the "sha224sum"
 * program).
 * 
 * "sha256"
 * Compute the SHA256 hash (using the "sha256sum"
 * program).
 * 
 * "sha384"
 * Compute the SHA384 hash (using the "sha384sum"
 * program).
 * 
 * "sha512"
 * Compute the SHA512 hash (using the "sha512sum"
 * program).
 * 
 * The checksum is returned as a printable string.
 * 
 * To get the checksum for a device, use
 * "guestfs_checksum_device".
 * 
 * To get the checksums for many files, use
 * "guestfs_checksums_out".
 * 
 * @csumtype: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_checksum(GuestfsSession *session, const gchar *csumtype, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_checksum(g, csumtype, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * unpack tarfile to directory
 *
 * This command uploads and unpacks local file "tarfile"
 * (an *uncompressed* tar file) into "directory".
 * 
 * To upload a compressed tarball, use "guestfs_tgz_in" or
 * "guestfs_txz_in".
 * 
 * @tarfile: (transfer none) (type filename):
 * @directory: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_tar_in(GuestfsSession *session, const gchar *tarfile, const gchar *directory, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_tar_in(g, tarfile, directory);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * pack directory into tarfile
 *
 * This command packs the contents of "directory" and
 * downloads it to local file "tarfile".
 * 
 * To download a compressed tarball, use "guestfs_tgz_out"
 * or "guestfs_txz_out".
 * 
 * @directory: (transfer none) (type utf8):
 * @tarfile: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_tar_out(GuestfsSession *session, const gchar *directory, const gchar *tarfile, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_tar_out(g, directory, tarfile);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file "tarball" (a
 * *gzip compressed* tar file) into "directory".
 * 
 * To upload an uncompressed tarball, use "guestfs_tar_in".
 * 
 * @tarball: (transfer none) (type filename):
 * @directory: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_tgz_in(GuestfsSession *session, const gchar *tarball, const gchar *directory, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_tgz_in(g, tarball, directory);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * pack directory into compressed tarball
 *
 * This command packs the contents of "directory" and
 * downloads it to local file "tarball".
 * 
 * To download an uncompressed tarball, use
 * "guestfs_tar_out".
 * 
 * @directory: (transfer none) (type filename):
 * @tarball: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_tgz_out(GuestfsSession *session, const gchar *directory, const gchar *tarball, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_tgz_out(g, directory, tarball);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * mount a guest disk, read-only
 *
 * This is the same as the "guestfs_mount" command, but it
 * mounts the filesystem with the read-only (*-o ro*) flag.
 * 
 * @device: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mount_ro(GuestfsSession *session, const gchar *device, const gchar *mountpoint, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mount_ro(g, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * mount a guest disk with mount options
 *
 * This is the same as the "guestfs_mount" command, but it
 * allows you to set the mount options as for the mount(8)
 * *-o* flag.
 * 
 * If the "options" parameter is an empty string, then no
 * options are passed (all options default to whatever the
 * filesystem uses).
 * 
 * @options: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mount_options(GuestfsSession *session, const gchar *options, const gchar *device, const gchar *mountpoint, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mount_options(g, options, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * mount a guest disk with mount options and vfstype
 *
 * This is the same as the "guestfs_mount" command, but it
 * allows you to set both the mount options and the vfstype
 * as for the mount(8) *-o* and *-t* flags.
 * 
 * @options: (transfer none) (type utf8):
 * @vfstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mount_vfs(GuestfsSession *session, const gchar *options, const gchar *vfstype, const gchar *device, const gchar *mountpoint, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mount_vfs(g, options, vfstype, device, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * debugging and internals
 *
 * The "guestfs_debug" command exposes some internals of
 * "guestfsd" (the guestfs daemon) that runs inside the
 * qemu subprocess.
 * 
 * There is no comprehensive help for this command. You
 * have to look at the file "daemon/debug.c" in the
 * libguestfs source to find out what you can do.
 * 
 * @subcmd: (transfer none) (type utf8):
 * @extraargs: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_debug(GuestfsSession *session, const gchar *subcmd, const gchar **extraargs, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_debug(g, subcmd, extraargs);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * remove an LVM logical volume
 *
 * Remove an LVM logical volume "device", where "device" is
 * the path to the LV, such as "/dev/VG/LV".
 * 
 * You can also remove all LVs in a volume group by
 * specifying the VG name, "/dev/VG".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvremove(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvremove(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove an LVM volume group
 *
 * Remove an LVM volume group "vgname", (for example "VG").
 * 
 * This also forcibly removes all logical volumes in the
 * volume group (if any).
 * 
 * @vgname: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_vgremove(GuestfsSession *session, const gchar *vgname, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_vgremove(g, vgname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove an LVM physical volume
 *
 * This wipes a physical volume "device" so that LVM will
 * no longer recognise it.
 * 
 * The implementation uses the "pvremove" command which
 * refuses to wipe physical volumes that contain any volume
 * groups, so you have to remove those first.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_pvremove(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_pvremove(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set the ext2/3/4 filesystem label
 *
 * This sets the ext2/3/4 filesystem label of the
 * filesystem on "device" to "label". Filesystem labels are
 * limited to 16 characters.
 * 
 * You can use either "guestfs_tune2fs_l" or
 * "guestfs_get_e2label" to return the existing label on a
 * filesystem.
 * 
 * @device: (transfer none) (type filename):
 * @label: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_e2label(GuestfsSession *session, const gchar *device, const gchar *label, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_e2label(g, device, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the ext2/3/4 filesystem label
 *
 * This returns the ext2/3/4 filesystem label of the
 * filesystem on "device".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_get_e2label(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_get_e2label(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * set the ext2/3/4 filesystem UUID
 *
 * This sets the ext2/3/4 filesystem UUID of the filesystem
 * on "device" to "uuid". The format of the UUID and
 * alternatives such as "clear", "random" and "time" are
 * described in the tune2fs(8) manpage.
 * 
 * You can use either "guestfs_tune2fs_l" or
 * "guestfs_get_e2uuid" to return the existing UUID of a
 * filesystem.
 * 
 * @device: (transfer none) (type filename):
 * @uuid: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_set_e2uuid(GuestfsSession *session, const gchar *device, const gchar *uuid, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_set_e2uuid(g, device, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the ext2/3/4 filesystem UUID
 *
 * This returns the ext2/3/4 filesystem UUID of the
 * filesystem on "device".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_get_e2uuid(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_get_e2uuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * run the filesystem checker
 *
 * This runs the filesystem checker (fsck) on "device"
 * which should have filesystem type "fstype".
 * 
 * The returned integer is the status. See fsck(8) for the
 * list of status codes from "fsck".
 * 
 * Notes:
 * 
 * *   Multiple status codes can be summed together.
 * 
 * *   A non-zero return code can mean "success", for
 * example if errors have been corrected on the
 * filesystem.
 * 
 * *   Checking or repairing NTFS volumes is not supported
 * (by linux-ntfs).
 * 
 * This command is entirely equivalent to running "fsck -a
 * -t fstype device".
 * 
 * @fstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_fsck(GuestfsSession *session, const gchar *fstype, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_fsck(g, fstype, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * write zeroes to the device
 *
 * This command writes zeroes over the first few blocks of
 * "device".
 * 
 * How many blocks are zeroed isn't specified (but it's
 * *not* enough to securely wipe the device). It should be
 * sufficient to remove any partition tables, filesystem
 * superblocks and so on.
 * 
 * If blocks are already zero, then this command avoids
 * writing zeroes. This prevents the underlying device from
 * becoming non-sparse or growing unnecessarily.
 * 
 * See also: "guestfs_zero_device", "guestfs_scrub_device",
 * "guestfs_is_zero_device"
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_zero(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_zero(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * install GRUB 1
 *
 * This command installs GRUB 1 (the Grand Unified
 * Bootloader) on "device", with the root directory being
 * "root".
 * 
 * Notes:
 * 
 * *   There is currently no way in the API to install
 * grub2, which is used by most modern Linux guests. It
 * is possible to run the grub2 command from the guest,
 * although see the caveats in "RUNNING COMMANDS" in
 * guestfs(3).
 * 
 * *   This uses "grub-install" from the host.
 * Unfortunately grub is not always compatible with
 * itself, so this only works in rather narrow
 * circumstances. Careful testing with each guest
 * version is advisable.
 * 
 * *   If grub-install reports the error "No suitable drive
 * was found in the generated device map." it may be
 * that you need to create a "/boot/grub/device.map"
 * file first that contains the mapping between grub
 * device names and Linux device names. It is usually
 * sufficient to create a file containing:
 * 
 * (hd0) /dev/vda
 * 
 * replacing "/dev/vda" with the name of the
 * installation device.
 * 
 * @root: (transfer none) (type filename):
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_grub_install(GuestfsSession *session, const gchar *root, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_grub_install(g, root, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * copy a file
 *
 * This copies a file from "src" to "dest" where "dest" is
 * either a destination filename or destination directory.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_cp(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_cp(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * copy a file or directory recursively
 *
 * This copies a file or directory from "src" to "dest"
 * recursively using the "cp -a" command.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_cp_a(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_cp_a(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * move a file
 *
 * This moves a file from "src" to "dest" where "dest" is
 * either a destination filename or destination directory.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mv(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mv(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * drop kernel page cache, dentries and inodes
 *
 * This instructs the guest kernel to drop its page cache,
 * and/or dentries and inode caches. The parameter
 * "whattodrop" tells the kernel what precisely to drop,
 * see <http://linux-mm.org/Drop_Caches>
 * 
 * Setting "whattodrop" to 3 should drop everything.
 * 
 * This automatically calls sync(2) before the operation,
 * so that the maximum guest memory is freed.
 * 
 * @whattodrop:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_drop_caches(GuestfsSession *session, gint32 whattodrop, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_drop_caches(g, whattodrop);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * return kernel messages
 *
 * This returns the kernel messages ("dmesg" output) from
 * the guest kernel. This is sometimes useful for extended
 * debugging of problems.
 * 
 * Another way to get the same information is to enable
 * verbose messages with "guestfs_set_verbose" or by
 * setting the environment variable "LIBGUESTFS_DEBUG=1"
 * before running the program.
 * 
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_dmesg(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_dmesg(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * ping the guest daemon
 *
 * This is a test probe into the guestfs daemon running
 * inside the qemu subprocess. Calling this function checks
 * that the daemon responds to the ping message, without
 * affecting the daemon or attached block device(s) in any
 * other way.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ping_daemon(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ping_daemon(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * test if two files have equal contents
 *
 * This compares the two files "file1" and "file2" and
 * returns true if their content is exactly equal, or false
 * otherwise.
 * 
 * The external cmp(1) program is used for the comparison.
 * 
 * @file1: (transfer none) (type filename):
 * @file2: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_equal(GuestfsSession *session, const gchar *file1, const gchar *file2, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_equal(g, file1, file2);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * print the printable strings in a file
 *
 * This runs the strings(1) command on a file and returns
 * the list of printable strings found.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_strings(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_strings(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * print the printable strings in a file
 *
 * This is like the "guestfs_strings" command, but allows
 * you to specify the encoding of strings that are looked
 * for in the source file "path".
 * 
 * Allowed encodings are:
 * 
 * s   Single 7-bit-byte characters like ASCII and the
 * ASCII-compatible parts of ISO-8859-X (this is what
 * "guestfs_strings" uses).
 * 
 * S   Single 8-bit-byte characters.
 * 
 * b   16-bit big endian strings such as those encoded in
 * UTF-16BE or UCS-2BE.
 * 
 * l (lower case letter L)
 * 16-bit little endian such as UTF-16LE and UCS-2LE.
 * This is useful for examining binaries in Windows
 * guests.
 * 
 * B   32-bit big endian such as UCS-4BE.
 * 
 * L   32-bit little endian such as UCS-4LE.
 * 
 * The returned strings are transcoded to UTF-8.
 * 
 * @encoding: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_strings_e(GuestfsSession *session, const gchar *encoding, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_strings_e(g, encoding, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * dump a file in hexadecimal
 *
 * This runs "hexdump -C" on the given "path". The result
 * is the human-readable, canonical hex dump of the file.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_hexdump(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_hexdump(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * zero unused inodes and disk blocks on ext2/3 filesystem
 *
 * This runs the *zerofree* program on "device". This
 * program claims to zero unused inodes and disk blocks on
 * an ext2/3 filesystem, thus making it possible to
 * compress the filesystem more effectively.
 * 
 * You should not run this program if the filesystem is
 * mounted.
 * 
 * It is possible that using this program can damage the
 * filesystem or data on the filesystem.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_zerofree(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_zerofree(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * resize an LVM physical volume
 *
 * This resizes (expands or shrinks) an existing LVM
 * physical volume to match the new size of the underlying
 * device.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_pvresize(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_pvresize(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * modify a single partition on a block device
 *
 * This runs sfdisk(8) option to modify just the single
 * partition "n" (note: "n" counts from 1).
 * 
 * For other parameters, see "guestfs_sfdisk". You should
 * usually pass 0 for the cyls/heads/sectors parameters.
 * 
 * See also: "guestfs_part_add"
 * 
 * @device: (transfer none) (type filename):
 * @partnum:
 * @cyls:
 * @heads:
 * @sectors:
 * @line: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_sfdisk_N(GuestfsSession *session, const gchar *device, gint32 partnum, gint32 cyls, gint32 heads, gint32 sectors, const gchar *line, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_sfdisk_N(g, device, partnum, cyls, heads, sectors, line);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * display the partition table
 *
 * This displays the partition table on "device", in the
 * human-readable output of the sfdisk(8) command. It is
 * not intended to be parsed.
 * 
 * See also: "guestfs_part_list"
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_sfdisk_l(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_sfdisk_l(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * display the kernel geometry
 *
 * This displays the kernel's idea of the geometry of
 * "device".
 * 
 * The result is in human-readable format, and not designed
 * to be parsed.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_sfdisk_kernel_geometry(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_sfdisk_kernel_geometry(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * display the disk geometry from the partition table
 *
 * This displays the disk geometry of "device" read from
 * the partition table. Especially in the case where the
 * underlying block device has been resized, this can be
 * different from the kernel's idea of the geometry (see
 * "guestfs_sfdisk_kernel_geometry").
 * 
 * The result is in human-readable format, and not designed
 * to be parsed.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_sfdisk_disk_geometry(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_sfdisk_disk_geometry(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * activate or deactivate all volume groups
 *
 * This command activates or (if "activate" is false)
 * deactivates all logical volumes in all volume groups.
 * 
 * This command is the same as running "vgchange -a y|n"
 * 
 * @activate:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_vg_activate_all(GuestfsSession *session, gboolean activate, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_vg_activate_all(g, activate);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * activate or deactivate some volume groups
 *
 * This command activates or (if "activate" is false)
 * deactivates all logical volumes in the listed volume
 * groups "volgroups".
 * 
 * This command is the same as running "vgchange -a y|n
 * volgroups..."
 * 
 * Note that if "volgroups" is an empty list then all
 * volume groups are activated or deactivated.
 * 
 * @activate:
 * @volgroups: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_vg_activate(GuestfsSession *session, gboolean activate, const gchar **volgroups, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_vg_activate(g, activate, volgroups);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * resize an LVM logical volume
 *
 * This resizes (expands or shrinks) an existing LVM
 * logical volume to "mbytes". When reducing, data in the
 * reduced part is lost.
 * 
 * @device: (transfer none) (type filename):
 * @mbytes:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvresize(GuestfsSession *session, const gchar *device, gint32 mbytes, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvresize(g, device, mbytes);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * resize an ext2, ext3 or ext4 filesystem
 *
 * This resizes an ext2, ext3 or ext4 filesystem to match
 * the size of the underlying device.
 * 
 * *Note:* It is sometimes required that you run
 * "guestfs_e2fsck_f" on the "device" before calling this
 * command. For unknown reasons "resize2fs" sometimes gives
 * an error about this and sometimes not. In any case, it
 * is always safe to call "guestfs_e2fsck_f" before calling
 * this function.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_resize2fs(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_resize2fs(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * find all files and directories
 *
 * This command lists out all files and directories,
 * recursively, starting at "directory". It is essentially
 * equivalent to running the shell command "find directory
 * -print" but some post-processing happens on the output,
 * described below.
 * 
 * This returns a list of strings *without any prefix*.
 * Thus if the directory structure was:
 * 
 * /tmp/a
 * /tmp/b
 * /tmp/c/d
 * 
 * then the returned list from "guestfs_find" "/tmp" would
 * be 4 elements:
 * 
 * a
 * b
 * c
 * c/d
 * 
 * If "directory" is not a directory, then this command
 * returns an error.
 * 
 * The returned list is sorted.
 * 
 * See also "guestfs_find0".
 * 
 * @directory: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_find(GuestfsSession *session, const gchar *directory, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_find(g, directory);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * check an ext2/ext3 filesystem
 *
 * This runs "e2fsck -p -f device", ie. runs the ext2/ext3
 * filesystem checker on "device", noninteractively (*-p*),
 * even if the filesystem appears to be clean (*-f*).
 * 
 * This command is only needed because of
 * "guestfs_resize2fs" (q.v.). Normally you should use
 * "guestfs_fsck".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_e2fsck_f(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_e2fsck_f(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * sleep for some seconds
 *
 * Sleep for "secs" seconds.
 * 
 * @secs:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_sleep(GuestfsSession *session, gint32 secs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_sleep(g, secs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * probe NTFS volume
 *
 * This command runs the ntfs-3g.probe(8) command which
 * probes an NTFS "device" for mountability. (Not all NTFS
 * volumes can be mounted read-write, and some cannot be
 * mounted at all).
 * 
 * "rw" is a boolean flag. Set it to true if you want to
 * test if the volume can be mounted read-write. Set it to
 * false if you want to test if the volume can be mounted
 * read-only.
 * 
 * The return value is an integer which 0 if the operation
 * would succeed, or some non-zero value documented in the
 * ntfs-3g.probe(8) manual page.
 * 
 * @rw:
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_ntfs_3g_probe(GuestfsSession *session, gboolean rw, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ntfs_3g_probe(g, rw, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * run a command via the shell
 *
 * This call runs a command from the guest filesystem via
 * the guest's "/bin/sh".
 * 
 * This is like "guestfs_command", but passes the command
 * to:
 * 
 * /bin/sh -c "command"
 * 
 * Depending on the guest's shell, this usually results in
 * wildcards being expanded, shell expressions being
 * interpolated and so on.
 * 
 * All the provisos about "guestfs_command" apply to this
 * call.
 * 
 * @command: (transfer none) (type utf8):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_sh(GuestfsSession *session, const gchar *command, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_sh(g, command);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * run a command via the shell returning lines
 *
 * This is the same as "guestfs_sh", but splits the result
 * into a list of lines.
 * 
 * See also: "guestfs_command_lines"
 * 
 * @command: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_sh_lines(GuestfsSession *session, const gchar *command, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_sh_lines(g, command);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * expand a wildcard path
 *
 * This command searches for all the pathnames matching
 * "pattern" according to the wildcard expansion rules used
 * by the shell.
 * 
 * If no paths match, then this returns an empty list
 * (note: not an error).
 * 
 * It is just a wrapper around the C glob(3) function with
 * flags "GLOB_MARK|GLOB_BRACE". See that manual page for
 * more details.
 * 
 * @pattern: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_glob_expand(GuestfsSession *session, const gchar *pattern, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_glob_expand(g, pattern);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * scrub (securely wipe) a device
 *
 * This command writes patterns over "device" to make data
 * retrieval more difficult.
 * 
 * It is an interface to the scrub(1) program. See that
 * manual page for more details.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_scrub_device(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_scrub_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * scrub (securely wipe) a file
 *
 * This command writes patterns over a file to make data
 * retrieval more difficult.
 * 
 * The file is *removed* after scrubbing.
 * 
 * It is an interface to the scrub(1) program. See that
 * manual page for more details.
 * 
 * @file: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_scrub_file(GuestfsSession *session, const gchar *file, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_scrub_file(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * scrub (securely wipe) free space
 *
 * This command creates the directory "dir" and then fills
 * it with files until the filesystem is full, and scrubs
 * the files as for "guestfs_scrub_file", and deletes them.
 * The intention is to scrub any free space on the
 * partition containing "dir".
 * 
 * It is an interface to the scrub(1) program. See that
 * manual page for more details.
 * 
 * @dir: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_scrub_freespace(GuestfsSession *session, const gchar *dir, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_scrub_freespace(g, dir);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a temporary directory
 *
 * This command creates a temporary directory. The
 * "template" parameter should be a full pathname for the
 * temporary directory name with the final six characters
 * being "XXXXXX".
 * 
 * For example: "/tmp/myprogXXXXXX" or
 * "/Temp/myprogXXXXXX", the second one being suitable for
 * Windows filesystems.
 * 
 * The name of the temporary directory that was created is
 * returned.
 * 
 * The temporary directory is created with mode 0700 and is
 * owned by root.
 * 
 * The caller is responsible for deleting the temporary
 * directory and its contents after use.
 * 
 * See also: mkdtemp(3)
 * 
 * @template: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_mkdtemp(GuestfsSession *session, const gchar *template, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_mkdtemp(g, template);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * count lines in a file
 *
 * This command counts the lines in a file, using the "wc
 * -l" external command.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_wc_l(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_wc_l(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * count words in a file
 *
 * This command counts the words in a file, using the "wc
 * -w" external command.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_wc_w(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_wc_w(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * count characters in a file
 *
 * This command counts the characters in a file, using the
 * "wc -c" external command.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_wc_c(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_wc_c(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * return first 10 lines of a file
 *
 * This command returns up to the first 10 lines of a file
 * as a list of strings.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_head(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_head(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return first N lines of a file
 *
 * If the parameter "nrlines" is a positive number, this
 * returns the first "nrlines" lines of the file "path".
 * 
 * If the parameter "nrlines" is a negative number, this
 * returns lines from the file "path", excluding the last
 * "nrlines" lines.
 * 
 * If the parameter "nrlines" is zero, this returns an
 * empty list.
 * 
 * @nrlines:
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_head_n(GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_head_n(g, nrlines, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return last 10 lines of a file
 *
 * This command returns up to the last 10 lines of a file
 * as a list of strings.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_tail(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_tail(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return last N lines of a file
 *
 * If the parameter "nrlines" is a positive number, this
 * returns the last "nrlines" lines of the file "path".
 * 
 * If the parameter "nrlines" is a negative number, this
 * returns lines from the file "path", starting with the
 * "-nrlines"th line.
 * 
 * If the parameter "nrlines" is zero, this returns an
 * empty list.
 * 
 * @nrlines:
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_tail_n(GuestfsSession *session, gint32 nrlines, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_tail_n(g, nrlines, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * report file system disk space usage
 *
 * This command runs the "df" command to report disk space
 * used.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string. Use "guestfs_statvfs" from programs.
 * 
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_df(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_df(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * report file system disk space usage (human readable)
 *
 * This command runs the "df -h" command to report disk
 * space used in human-readable format.
 * 
 * This command is mostly useful for interactive sessions.
 * It is *not* intended that you try to parse the output
 * string. Use "guestfs_statvfs" from programs.
 * 
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_df_h(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_df_h(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * estimate file space usage
 *
 * This command runs the "du -s" command to estimate file
 * space usage for "path".
 * 
 * "path" can be a file or a directory. If "path" is a
 * directory then the estimate includes the contents of the
 * directory and all subdirectories (recursively).
 * 
 * The result is the estimated size in *kilobytes* (ie.
 * units of 1024 bytes).
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint64 guestfs_session_du(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int64_t ret = guestfs_du(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * list files in an initrd
 *
 * This command lists out files contained in an initrd.
 * 
 * The files are listed without any initial "/" character.
 * The files are listed in the order they appear (not
 * necessarily alphabetical). Directory names are listed as
 * separate items.
 * 
 * Old Linux kernels (2.4 and earlier) used a compressed
 * ext2 filesystem as initrd. We *only* support the newer
 * initramfs format (compressed cpio files).
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_initrd_list(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_initrd_list(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * mount a file using the loop device
 *
 * This command lets you mount "file" (a filesystem image
 * in a file) on a mount point. It is entirely equivalent
 * to the command "mount -o loop file mountpoint".
 * 
 * @file: (transfer none) (type filename):
 * @mountpoint: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mount_loop(GuestfsSession *session, const gchar *file, const gchar *mountpoint, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mount_loop(g, file, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a swap partition
 *
 * Create a swap partition on "device".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkswap(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkswap(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a swap partition with a label
 *
 * Create a swap partition on "device" with label "label".
 * 
 * Note that you cannot attach a swap label to a block
 * device (eg. "/dev/sda"), just to a partition. This
 * appears to be a limitation of the kernel or swap tools.
 * 
 * @label: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkswap_L(GuestfsSession *session, const gchar *label, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkswap_L(g, label, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a swap partition with an explicit UUID
 *
 * Create a swap partition on "device" with UUID "uuid".
 * 
 * @uuid: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkswap_U(GuestfsSession *session, const gchar *uuid, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkswap_U(g, uuid, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make block, character or FIFO devices
 *
 * This call creates block or character special devices, or
 * named pipes (FIFOs).
 * 
 * The "mode" parameter should be the mode, using the
 * standard constants. "devmajor" and "devminor" are the
 * device major and minor numbers, only used when creating
 * block and character special devices.
 * 
 * Note that, just like mknod(2), the mode must be bitwise
 * OR'd with S_IFBLK, S_IFCHR, S_IFIFO or S_IFSOCK
 * (otherwise this call just creates a regular file). These
 * constants are available in the standard Linux header
 * files, or you can use "guestfs_mknod_b",
 * "guestfs_mknod_c" or "guestfs_mkfifo" which are wrappers
 * around this command which bitwise OR in the appropriate
 * constant for you.
 * 
 * The mode actually set is affected by the umask.
 * 
 * @mode:
 * @devmajor:
 * @devminor:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mknod(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mknod(g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make FIFO (named pipe)
 *
 * This call creates a FIFO (named pipe) called "path" with
 * mode "mode". It is just a convenient wrapper around
 * "guestfs_mknod".
 * 
 * The mode actually set is affected by the umask.
 * 
 * @mode:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkfifo(GuestfsSession *session, gint32 mode, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkfifo(g, mode, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make block device node
 *
 * This call creates a block device node called "path" with
 * mode "mode" and device major/minor "devmajor" and
 * "devminor". It is just a convenient wrapper around
 * "guestfs_mknod".
 * 
 * The mode actually set is affected by the umask.
 * 
 * @mode:
 * @devmajor:
 * @devminor:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mknod_b(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mknod_b(g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make char device node
 *
 * This call creates a char device node called "path" with
 * mode "mode" and device major/minor "devmajor" and
 * "devminor". It is just a convenient wrapper around
 * "guestfs_mknod".
 * 
 * The mode actually set is affected by the umask.
 * 
 * @mode:
 * @devmajor:
 * @devminor:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mknod_c(GuestfsSession *session, gint32 mode, gint32 devmajor, gint32 devminor, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mknod_c(g, mode, devmajor, devminor, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set file mode creation mask (umask)
 *
 * This function sets the mask used for creating new files
 * and device nodes to "mask & 0777".
 * 
 * Typical umask values would be 022 which creates new
 * files with permissions like "-rw-r--r--" or
 * "-rwxr-xr-x", and 002 which creates new files with
 * permissions like "-rw-rw-r--" or "-rwxrwxr-x".
 * 
 * The default umask is 022. This is important because it
 * means that directories and device nodes will be created
 * with 0644 or 0755 mode even if you specify 0777.
 * 
 * See also "guestfs_get_umask", umask(2), "guestfs_mknod",
 * "guestfs_mkdir".
 * 
 * This call returns the previous umask.
 * 
 * @mask:
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_umask(GuestfsSession *session, gint32 mask, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_umask(g, mask);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * read directories entries
 *
 * This returns the list of directory entries in directory
 * "dir".
 * 
 * All entries in the directory are returned, including "."
 * and "..". The entries are *not* sorted, but returned in
 * the same order as the underlying filesystem.
 * 
 * Also this call returns basic file type information about
 * each file. The "ftyp" field will contain one of the
 * following characters:
 * 
 * 'b' Block special
 * 
 * 'c' Char special
 * 
 * 'd' Directory
 * 
 * 'f' FIFO (named pipe)
 * 
 * 'l' Symbolic link
 * 
 * 'r' Regular file
 * 
 * 's' Socket
 * 
 * 'u' Unknown file type
 * 
 * '?' The readdir(3) call returned a "d_type" field with
 * an unexpected value
 * 
 * This function is primarily intended for use by programs.
 * To get a simple list of names, use "guestfs_ls". To get
 * a printable directory for human consumption, use
 * "guestfs_ll".
 * 
 * @dir: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type Dirent): an array of Dirent objects, or NULL on error
 */
GuestfsDirent **guestfs_session_readdir(GuestfsSession *session, const gchar *dir, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_dirent_list *ret = guestfs_readdir(g, dir);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsReaddir **l = g_malloc(sizeof GuestfsReaddir* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsReaddir *s = g_slice_new(GuestfsReaddir);
    s->ino = ret->val[i]->ino;
    s->ftyp = ret->val[i]->ftyp;
    s->name = g_strdup(ret->val[i]->name);
  guestfs_free_dirent(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * create partitions on a block device
 *
 * This is a simplified interface to the "guestfs_sfdisk"
 * command, where partition sizes are specified in
 * megabytes only (rounded to the nearest cylinder) and you
 * don't need to specify the cyls, heads and sectors
 * parameters which were rarely if ever used anyway.
 * 
 * See also: "guestfs_sfdisk", the sfdisk(8) manpage and
 * "guestfs_part_disk"
 * 
 * @device: (transfer none) (type filename):
 * @lines: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_sfdiskM(GuestfsSession *session, const gchar *device, const gchar **lines, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_sfdiskM(g, device, lines);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * determine file type inside a compressed file
 *
 * This command runs "file" after first decompressing
 * "path" using "method".
 * 
 * "method" must be one of "gzip", "compress" or "bzip2".
 * 
 * Since 1.0.63, use "guestfs_file" instead which can now
 * process compressed files.
 * 
 * @meth: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_zfile(GuestfsSession *session, const gchar *meth, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_zfile(g, meth, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * list extended attributes of a file or directory
 *
 * This call lists the extended attributes of the file or
 * directory "path".
 * 
 * At the system call level, this is a combination of the
 * listxattr(2) and getxattr(2) calls.
 * 
 * See also: "guestfs_lgetxattrs", attr(5).
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type XAttr): an array of XAttr objects, or NULL on error
 */
GuestfsXAttr **guestfs_session_getxattrs(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_xattr_list *ret = guestfs_getxattrs(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsGetxattrs **l = g_malloc(sizeof GuestfsGetxattrs* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsGetxattrs *s = g_slice_new(GuestfsGetxattrs);
    s->attrname = g_strdup(ret->val[i]->attrname);
    s->attrval = ret->val[i]->attrval
;    s->attrval_size = ret->val[i]->attrval_size
;  guestfs_free_xattr(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * list extended attributes of a file or directory
 *
 * This is the same as "guestfs_getxattrs", but if "path"
 * is a symbolic link, then it returns the extended
 * attributes of the link itself.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type XAttr): an array of XAttr objects, or NULL on error
 */
GuestfsXAttr **guestfs_session_lgetxattrs(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_xattr_list *ret = guestfs_lgetxattrs(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsLgetxattrs **l = g_malloc(sizeof GuestfsLgetxattrs* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsLgetxattrs *s = g_slice_new(GuestfsLgetxattrs);
    s->attrname = g_strdup(ret->val[i]->attrname);
    s->attrval = ret->val[i]->attrval
;    s->attrval_size = ret->val[i]->attrval_size
;  guestfs_free_xattr(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * set extended attribute of a file or directory
 *
 * This call sets the extended attribute named "xattr" of
 * the file "path" to the value "val" (of length "vallen").
 * The value is arbitrary 8 bit data.
 * 
 * See also: "guestfs_lsetxattr", attr(5).
 * 
 * @xattr: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 * @vallen:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_setxattr(GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_setxattr(g, xattr, val, vallen, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set extended attribute of a file or directory
 *
 * This is the same as "guestfs_setxattr", but if "path" is
 * a symbolic link, then it sets an extended attribute of
 * the link itself.
 * 
 * @xattr: (transfer none) (type utf8):
 * @val: (transfer none) (type utf8):
 * @vallen:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lsetxattr(GuestfsSession *session, const gchar *xattr, const gchar *val, gint32 vallen, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lsetxattr(g, xattr, val, vallen, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove extended attribute of a file or directory
 *
 * This call removes the extended attribute named "xattr"
 * of the file "path".
 * 
 * See also: "guestfs_lremovexattr", attr(5).
 * 
 * @xattr: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_removexattr(GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_removexattr(g, xattr, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove extended attribute of a file or directory
 *
 * This is the same as "guestfs_removexattr", but if "path"
 * is a symbolic link, then it removes an extended
 * attribute of the link itself.
 * 
 * @xattr: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lremovexattr(GuestfsSession *session, const gchar *xattr, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lremovexattr(g, xattr, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * show mountpoints
 *
 * This call is similar to "guestfs_mounts". That call
 * returns a list of devices. This one returns a hash table
 * (map) of device name to directory where the device is
 * mounted.
 * 
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_mountpoints(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_mountpoints(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * create a mountpoint
 *
 * "guestfs_mkmountpoint" and "guestfs_rmmountpoint" are
 * specialized calls that can be used to create extra
 * mountpoints before mounting the first filesystem.
 * 
 * These calls are *only* necessary in some very limited
 * circumstances, mainly the case where you want to mount a
 * mix of unrelated and/or read-only filesystems together.
 * 
 * For example, live CDs often contain a "Russian doll"
 * nest of filesystems, an ISO outer layer, with a squashfs
 * image inside, with an ext2/3 image inside that. You can
 * unpack this as follows in guestfish:
 * 
 * add-ro Fedora-11-i686-Live.iso
 * run
 * mkmountpoint /cd
 * mkmountpoint /sqsh
 * mkmountpoint /ext3fs
 * mount /dev/sda /cd
 * mount-loop /cd/LiveOS/squashfs.img /sqsh
 * mount-loop /sqsh/LiveOS/ext3fs.img /ext3fs
 * 
 * The inner filesystem is now unpacked under the /ext3fs
 * mountpoint.
 * 
 * "guestfs_mkmountpoint" is not compatible with
 * "guestfs_umount_all". You may get unexpected errors if
 * you try to mix these calls. It is safest to manually
 * unmount filesystems and remove mountpoints after use.
 * 
 * "guestfs_umount_all" unmounts filesystems by sorting the
 * paths longest first, so for this to work for manual
 * mountpoints, you must ensure that the innermost
 * mountpoints have the longest pathnames, as in the
 * example code above.
 * 
 * For more details see
 * <https://bugzilla.redhat.com/show_bug.cgi?id=599503>
 * 
 * Autosync [see "guestfs_set_autosync", this is set by
 * default on handles] can cause "guestfs_umount_all" to be
 * called when the handle is closed which can also trigger
 * these issues.
 * 
 * @exemptpath: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkmountpoint(GuestfsSession *session, const gchar *exemptpath, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkmountpoint(g, exemptpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove a mountpoint
 *
 * This calls removes a mountpoint that was previously
 * created with "guestfs_mkmountpoint". See
 * "guestfs_mkmountpoint" for full details.
 * 
 * @exemptpath: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_rmmountpoint(GuestfsSession *session, const gchar *exemptpath, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_rmmountpoint(g, exemptpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * read a file
 *
 * This calls returns the contents of the file "path" as a
 * buffer.
 * 
 * Unlike "guestfs_cat", this function can correctly handle
 * files that contain embedded ASCII NUL characters.
 * However unlike "guestfs_download", this function is
 * limited in the total size of file that can be handled.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint *guestfs_session_read_file(GuestfsSession *session, const gchar *path, gsize *size_r, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_read_file(g, path, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "grep" program and returns the
 * matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_grep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_grep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "egrep" program and returns the
 * matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_egrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_egrep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "fgrep" program and returns the
 * matching lines.
 * 
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_fgrep(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_fgrep(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "grep -i" program and returns
 * the matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_grepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_grepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "egrep -i" program and returns
 * the matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_egrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_egrepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "fgrep -i" program and returns
 * the matching lines.
 * 
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_fgrepi(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_fgrepi(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "zgrep" program and returns the
 * matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_zgrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_zgrep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "zegrep" program and returns the
 * matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_zegrep(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_zegrep(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "zfgrep" program and returns the
 * matching lines.
 * 
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_zfgrep(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_zfgrep(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "zgrep -i" program and returns
 * the matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_zgrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_zgrepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "zegrep -i" program and returns
 * the matching lines.
 * 
 * @regex: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_zegrepi(GuestfsSession *session, const gchar *regex, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_zegrepi(g, regex, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * return lines matching a pattern
 *
 * This calls the external "zfgrep -i" program and returns
 * the matching lines.
 * 
 * @pattern: (transfer none) (type utf8):
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_zfgrepi(GuestfsSession *session, const gchar *pattern, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_zfgrepi(g, pattern, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * canonicalized absolute pathname
 *
 * Return the canonicalized absolute pathname of "path".
 * The returned path has no ".", ".." or symbolic link path
 * elements.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_realpath(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_realpath(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * create a hard link
 *
 * This command creates a hard link using the "ln" command.
 * 
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ln(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ln(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a hard link
 *
 * This command creates a hard link using the "ln -f"
 * command. The *-f* option removes the link ("linkname")
 * if it exists already.
 * 
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ln_f(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ln_f(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -s"
 * command.
 * 
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ln_s(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ln_s(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a symbolic link
 *
 * This command creates a symbolic link using the "ln -sf"
 * command, The *-f* option removes the link ("linkname")
 * if it exists already.
 * 
 * @target: (transfer none) (type utf8):
 * @linkname: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ln_sf(GuestfsSession *session, const gchar *target, const gchar *linkname, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ln_sf(g, target, linkname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * read the target of a symbolic link
 *
 * This command reads the target of a symbolic link.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_readlink(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_readlink(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes)
 * named "path" of size "len" bytes. If the file exists
 * already, it is overwritten.
 * 
 * Do not confuse this with the guestfish-specific "alloc"
 * command which allocates a file in the host and attaches
 * it as a device.
 * 
 * @path: (transfer none) (type filename):
 * @len:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_fallocate(GuestfsSession *session, const gchar *path, gint32 len, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_fallocate(g, path, len);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * enable swap on device
 *
 * This command enables the libguestfs appliance to use the
 * swap device or partition named "device". The increased
 * memory is made available for all commands, for example
 * those run using "guestfs_command" or "guestfs_sh".
 * 
 * Note that you should not swap to existing guest swap
 * partitions unless you know what you are doing. They may
 * contain hibernation information, or other information
 * that the guest doesn't want you to trash. You also risk
 * leaking information about the host to the guest this
 * way. Instead, attach a new host device to the guest and
 * swap on that.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapon_device(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapon_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * disable swap on device
 *
 * This command disables the libguestfs appliance swap
 * device or partition named "device". See
 * "guestfs_swapon_device".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapoff_device(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapoff_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * enable swap on file
 *
 * This command enables swap to a file. See
 * "guestfs_swapon_device" for other notes.
 * 
 * @file: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapon_file(GuestfsSession *session, const gchar *file, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapon_file(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * disable swap on file
 *
 * This command disables the libguestfs appliance swap on
 * file.
 * 
 * @file: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapoff_file(GuestfsSession *session, const gchar *file, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapoff_file(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * enable swap on labeled swap partition
 *
 * This command enables swap to a labeled swap partition.
 * See "guestfs_swapon_device" for other notes.
 * 
 * @label: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapon_label(GuestfsSession *session, const gchar *label, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapon_label(g, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * disable swap on labeled swap partition
 *
 * This command disables the libguestfs appliance swap on
 * labeled swap partition.
 * 
 * @label: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapoff_label(GuestfsSession *session, const gchar *label, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapoff_label(g, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * enable swap on swap partition by UUID
 *
 * This command enables swap to a swap partition with the
 * given UUID. See "guestfs_swapon_device" for other notes.
 * 
 * @uuid: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapon_uuid(GuestfsSession *session, const gchar *uuid, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapon_uuid(g, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * disable swap on swap partition by UUID
 *
 * This command disables the libguestfs appliance swap
 * partition with the given UUID.
 * 
 * @uuid: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_swapoff_uuid(GuestfsSession *session, const gchar *uuid, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_swapoff_uuid(g, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a swap file
 *
 * Create a swap file.
 * 
 * This command just writes a swap file signature to an
 * existing file. To create the file itself, use something
 * like "guestfs_fallocate".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkswap_file(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkswap_file(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create an inotify handle
 *
 * This command creates a new inotify handle. The inotify
 * subsystem can be used to notify events which happen to
 * objects in the guest filesystem.
 * 
 * "maxevents" is the maximum number of events which will
 * be queued up between calls to "guestfs_inotify_read" or
 * "guestfs_inotify_files". If this is passed as 0, then
 * the kernel (or previously set) default is used. For
 * Linux 2.6.29 the default was 16384 events. Beyond this
 * limit, the kernel throws away events, but records the
 * fact that it threw them away by setting a flag
 * "IN_Q_OVERFLOW" in the returned structure list (see
 * "guestfs_inotify_read").
 * 
 * Before any events are generated, you have to add some
 * watches to the internal watch list. See:
 * "guestfs_inotify_add_watch", "guestfs_inotify_rm_watch"
 * and "guestfs_inotify_watch_all".
 * 
 * Queued up events should be read periodically by calling
 * "guestfs_inotify_read" (or "guestfs_inotify_files" which
 * is just a helpful wrapper around
 * "guestfs_inotify_read"). If you don't read the events
 * out often enough then you risk the internal queue
 * overflowing.
 * 
 * The handle should be closed after use by calling
 * "guestfs_inotify_close". This also removes any watches
 * automatically.
 * 
 * See also inotify(7) for an overview of the inotify
 * interface as exposed by the Linux kernel, which is
 * roughly what we expose via libguestfs. Note that there
 * is one global inotify handle per libguestfs instance.
 * 
 * @maxevents:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_inotify_init(GuestfsSession *session, gint32 maxevents, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inotify_init(g, maxevents);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add an inotify watch
 *
 * Watch "path" for the events listed in "mask".
 * 
 * Note that if "path" is a directory then events within
 * that directory are watched, but this does *not* happen
 * recursively (in subdirectories).
 * 
 * Note for non-C or non-Linux callers: the inotify events
 * are defined by the Linux kernel ABI and are listed in
 * "/usr/include/sys/inotify.h".
 * 
 * @path: (transfer none) (type filename):
 * @mask:
 *
 * Returns: the returned value, or -1 on error
 */
gint64 guestfs_session_inotify_add_watch(GuestfsSession *session, const gchar *path, gint32 mask, GError **err){
  guestfs_h *g = session->priv->g;
  int64_t ret = guestfs_inotify_add_watch(g, path, mask);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * remove an inotify watch
 *
 * Remove a previously defined inotify watch. See
 * "guestfs_inotify_add_watch".
 * 
 * @wd:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_inotify_rm_watch(GuestfsSession *session, gint32 wd, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inotify_rm_watch(g, wd);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * return list of inotify events
 *
 * Return the complete queue of events that have happened
 * since the previous read call.
 * 
 * If no events have happened, this returns an empty list.
 * 
 * *Note*: In order to make sure that all events have been
 * read, you must call this function repeatedly until it
 * returns an empty list. The reason is that the call will
 * read events up to the maximum appliance-to-host message
 * size and leave remaining events in the queue.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type INotifyEvent): an array of INotifyEvent objects, or NULL on error
 */
GuestfsINotifyEvent **guestfs_session_inotify_read(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_inotify_event_list *ret = guestfs_inotify_read(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsInotifyRead **l = g_malloc(sizeof GuestfsInotifyRead* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsInotifyRead *s = g_slice_new(GuestfsInotifyRead);
    s->in_wd = ret->val[i]->in_wd;
    s->in_mask = ret->val[i]->in_mask;
    s->in_cookie = ret->val[i]->in_cookie;
    s->in_name = g_strdup(ret->val[i]->in_name);
  guestfs_free_inotify_event(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * return list of watched files that had events
 *
 * This function is a helpful wrapper around
 * "guestfs_inotify_read" which just returns a list of
 * pathnames of objects that were touched. The returned
 * pathnames are sorted and deduplicated.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_inotify_files(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_inotify_files(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * close the inotify handle
 *
 * This closes the inotify handle which was previously
 * opened by inotify_init. It removes all watches, throws
 * away any pending events, and deallocates all resources.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_inotify_close(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_inotify_close(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set SELinux security context
 *
 * This sets the SELinux security context of the daemon to
 * the string "context".
 * 
 * See the documentation about SELINUX in guestfs(3).
 * 
 * @context: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_setcon(GuestfsSession *session, const gchar *context, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_setcon(g, context);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get SELinux security context
 *
 * This gets the SELinux security context of the daemon.
 * 
 * See the documentation about SELINUX in guestfs(3), and
 * "guestfs_setcon"
 * 
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_getcon(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_getcon(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * make a filesystem with block size
 *
 * This call is similar to "guestfs_mkfs", but it allows
 * you to control the block size of the resulting
 * filesystem. Supported block sizes depend on the
 * filesystem type, but typically they are 1024, 2048 or
 * 4096 only.
 * 
 * For VFAT and NTFS the "blocksize" parameter is treated
 * as the requested cluster size.
 * 
 * @fstype: (transfer none) (type utf8):
 * @blocksize:
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkfs_b(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkfs_b(g, fstype, blocksize, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make ext2/3/4 external journal
 *
 * This creates an ext2 external journal on "device". It is
 * equivalent to the command:
 * 
 * mke2fs -O journal_dev -b blocksize device
 * 
 * @blocksize:
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mke2journal(GuestfsSession *session, gint32 blocksize, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mke2journal(g, blocksize, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make ext2/3/4 external journal with label
 *
 * This creates an ext2 external journal on "device" with
 * label "label".
 * 
 * @blocksize:
 * @label: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mke2journal_L(GuestfsSession *session, gint32 blocksize, const gchar *label, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mke2journal_L(g, blocksize, label, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make ext2/3/4 external journal with UUID
 *
 * This creates an ext2 external journal on "device" with
 * UUID "uuid".
 * 
 * @blocksize:
 * @uuid: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mke2journal_U(GuestfsSession *session, gint32 blocksize, const gchar *uuid, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mke2journal_U(g, blocksize, uuid, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on "journal". It is equivalent to the
 * command:
 * 
 * mke2fs -t fstype -b blocksize -J device=<journal> <device>
 * 
 * See also "guestfs_mke2journal".
 * 
 * @fstype: (transfer none) (type utf8):
 * @blocksize:
 * @device: (transfer none) (type filename):
 * @journal: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mke2fs_J(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *journal, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mke2fs_J(g, fstype, blocksize, device, journal);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on the journal labeled "label".
 * 
 * See also "guestfs_mke2journal_L".
 * 
 * @fstype: (transfer none) (type utf8):
 * @blocksize:
 * @device: (transfer none) (type filename):
 * @label: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mke2fs_JL(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *label, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mke2fs_JL(g, fstype, blocksize, device, label);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make ext2/3/4 filesystem with external journal
 *
 * This creates an ext2/3/4 filesystem on "device" with an
 * external journal on the journal with UUID "uuid".
 * 
 * See also "guestfs_mke2journal_U".
 * 
 * @fstype: (transfer none) (type utf8):
 * @blocksize:
 * @device: (transfer none) (type filename):
 * @uuid: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mke2fs_JU(GuestfsSession *session, const gchar *fstype, gint32 blocksize, const gchar *device, const gchar *uuid, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mke2fs_JU(g, fstype, blocksize, device, uuid);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * load a kernel module
 *
 * This loads a kernel module in the appliance.
 * 
 * The kernel module must have been whitelisted when
 * libguestfs was built (see "appliance/kmod.whitelist.in"
 * in the source).
 * 
 * @modulename: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_modprobe(GuestfsSession *session, const gchar *modulename, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_modprobe(g, modulename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * echo arguments back to the client
 *
 * This command concatenates the list of "words" passed
 * with single spaces between them and returns the
 * resulting string.
 * 
 * You can use this command to test the connection through
 * to the daemon.
 * 
 * See also "guestfs_ping_daemon".
 * 
 * @words: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_echo_daemon(GuestfsSession *session, const gchar **words, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_echo_daemon(g, words);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * find all files and directories, returning NUL-separated list
 *
 * This command lists out all files and directories,
 * recursively, starting at "directory", placing the
 * resulting list in the external file called "files".
 * 
 * This command works the same way as "guestfs_find" with
 * the following exceptions:
 * 
 * *   The resulting list is written to an external file.
 * 
 * *   Items (filenames) in the result are separated by
 * "\0" characters. See find(1) option *-print0*.
 * 
 * *   This command is not limited in the number of names
 * that it can return.
 * 
 * *   The result list is not sorted.
 * 
 * @directory: (transfer none) (type filename):
 * @files: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_find0(GuestfsSession *session, const gchar *directory, const gchar *files, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_find0(g, directory, files);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * return true path on case-insensitive filesystem
 *
 * This can be used to resolve case insensitive paths on a
 * filesystem which is case sensitive. The use case is to
 * resolve paths which you have read from Windows
 * configuration files or the Windows Registry, to the true
 * path.
 * 
 * The command handles a peculiarity of the Linux ntfs-3g
 * filesystem driver (and probably others), which is that
 * although the underlying filesystem is case-insensitive,
 * the driver exports the filesystem to Linux as
 * case-sensitive.
 * 
 * One consequence of this is that special directories such
 * as "c:\windows" may appear as "/WINDOWS" or "/windows"
 * (or other things) depending on the precise details of
 * how they were created. In Windows itself this would not
 * be a problem.
 * 
 * Bug or feature? You decide:
 * <http://www.tuxera.com/community/ntfs-3g-faq/#posixfilen
 * ames1>
 * 
 * This function resolves the true case of each element in
 * the path and returns the case-sensitive path.
 * 
 * Thus "guestfs_case_sensitive_path" ("/Windows/System32")
 * might return "/WINDOWS/system32" (the exact return value
 * would depend on details of how the directories were
 * originally created under Windows).
 * 
 * *Note*: This function does not handle drive names,
 * backslashes etc.
 * 
 * See also "guestfs_realpath".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_case_sensitive_path(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_case_sensitive_path(g, path);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get the Linux VFS type corresponding to a mounted device
 *
 * This command gets the filesystem type corresponding to
 * the filesystem on "device".
 * 
 * For most filesystems, the result is the name of the
 * Linux VFS module which would be used to mount this
 * filesystem if you mounted it without specifying the
 * filesystem type. For example a string such as "ext3" or
 * "ntfs".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_vfs_type(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_vfs_type(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * truncate a file to zero size
 *
 * This command truncates "path" to a zero-length file. The
 * file must exist already.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_truncate(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_truncate(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * truncate a file to a particular size
 *
 * This command truncates "path" to size "size" bytes. The
 * file must exist already.
 * 
 * If the current file size is less than "size" then the
 * file is extended to the required size with zero bytes.
 * This creates a sparse file (ie. disk blocks are not
 * allocated for the file until you write to it). To create
 * a non-sparse file of zeroes, use "guestfs_fallocate64"
 * instead.
 * 
 * @path: (transfer none) (type filename):
 * @size:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_truncate_size(GuestfsSession *session, const gchar *path, gint64 size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_truncate_size(g, path, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set timestamp of a file with nanosecond precision
 *
 * This command sets the timestamps of a file with
 * nanosecond precision.
 * 
 * "atsecs, atnsecs" are the last access time (atime) in
 * secs and nanoseconds from the epoch.
 * 
 * "mtsecs, mtnsecs" are the last modification time (mtime)
 * in secs and nanoseconds from the epoch.
 * 
 * If the *nsecs field contains the special value -1 then
 * the corresponding timestamp is set to the current time.
 * (The *secs field is ignored in this case).
 * 
 * If the *nsecs field contains the special value -2 then
 * the corresponding timestamp is left unchanged. (The
 * *secs field is ignored in this case).
 * 
 * @path: (transfer none) (type filename):
 * @atsecs:
 * @atnsecs:
 * @mtsecs:
 * @mtnsecs:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_utimens(GuestfsSession *session, const gchar *path, gint64 atsecs, gint64 atnsecs, gint64 mtsecs, gint64 mtnsecs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_utimens(g, path, atsecs, atnsecs, mtsecs, mtnsecs);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a directory with a particular mode
 *
 * This command creates a directory, setting the initial
 * permissions of the directory to "mode".
 * 
 * For common Linux filesystems, the actual mode which is
 * set will be "mode & ~umask & 01777". Non-native-Linux
 * filesystems may interpret the mode in other ways.
 * 
 * See also "guestfs_mkdir", "guestfs_umask"
 * 
 * @path: (transfer none) (type filename):
 * @mode:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkdir_mode(GuestfsSession *session, const gchar *path, gint32 mode, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkdir_mode(g, path, mode);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * change file owner and group
 *
 * Change the file owner to "owner" and group to "group".
 * This is like "guestfs_chown" but if "path" is a symlink
 * then the link itself is changed, not the target.
 * 
 * Only numeric uid and gid are supported. If you want to
 * use names, you will need to locate and parse the
 * password file yourself (Augeas support makes this
 * relatively easy).
 * 
 * @owner:
 * @group:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lchown(GuestfsSession *session, gint32 owner, gint32 group, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lchown(g, owner, group, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * lstat on multiple files
 *
 * This call allows you to perform the "guestfs_lstat"
 * operation on multiple files, where all files are in the
 * directory "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a list of stat structs, with a
 * one-to-one correspondence to the "names" list. If any
 * name did not exist or could not be lstat'd, then the
 * "ino" field of that structure is set to -1.
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. See also "guestfs_lxattrlist" for a
 * similarly efficient call for getting extended
 * attributes. Very long directory listings might cause the
 * protocol message size to be exceeded, causing this call
 * to fail. The caller must split up such requests into
 * smaller groups of names.
 * 
 * @path: (transfer none) (type filename):
 * @names: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type Stat): an array of Stat objects, or NULL on error
 */
GuestfsStat **guestfs_session_lstatlist(GuestfsSession *session, const gchar *path, const gchar **names, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_stat_list *ret = guestfs_lstatlist(g, path, names);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsLstatlist **l = g_malloc(sizeof GuestfsLstatlist* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsLstatlist *s = g_slice_new(GuestfsLstatlist);
    s->dev = ret->val[i]->dev;
    s->ino = ret->val[i]->ino;
    s->mode = ret->val[i]->mode;
    s->nlink = ret->val[i]->nlink;
    s->uid = ret->val[i]->uid;
    s->gid = ret->val[i]->gid;
    s->rdev = ret->val[i]->rdev;
    s->size = ret->val[i]->size;
    s->blksize = ret->val[i]->blksize;
    s->blocks = ret->val[i]->blocks;
    s->atime = ret->val[i]->atime;
    s->mtime = ret->val[i]->mtime;
    s->ctime = ret->val[i]->ctime;
  guestfs_free_stat(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * lgetxattr on multiple files
 *
 * This call allows you to get the extended attributes of
 * multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a flat list of xattr structs which
 * must be interpreted sequentially. The first xattr struct
 * always has a zero-length "attrname". "attrval" in this
 * struct is zero-length to indicate there was an error
 * doing "lgetxattr" for this file, *or* is a C string
 * which is a decimal number (the number of following
 * attributes for this file, which could be "0"). Then
 * after the first xattr struct are the zero or more
 * attributes for the first named file. This repeats for
 * the second and subsequent files.
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. See also "guestfs_lstatlist" for a
 * similarly efficient call for getting standard stats.
 * Very long directory listings might cause the protocol
 * message size to be exceeded, causing this call to fail.
 * The caller must split up such requests into smaller
 * groups of names.
 * 
 * @path: (transfer none) (type filename):
 * @names: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type XAttr): an array of XAttr objects, or NULL on error
 */
GuestfsXAttr **guestfs_session_lxattrlist(GuestfsSession *session, const gchar *path, const gchar **names, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_xattr_list *ret = guestfs_lxattrlist(g, path, names);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsLxattrlist **l = g_malloc(sizeof GuestfsLxattrlist* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsLxattrlist *s = g_slice_new(GuestfsLxattrlist);
    s->attrname = g_strdup(ret->val[i]->attrname);
    s->attrval = ret->val[i]->attrval
;    s->attrval_size = ret->val[i]->attrval_size
;  guestfs_free_xattr(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * readlink on multiple files
 *
 * This call allows you to do a "readlink" operation on
 * multiple files, where all files are in the directory
 * "path". "names" is the list of files from this
 * directory.
 * 
 * On return you get a list of strings, with a one-to-one
 * correspondence to the "names" list. Each string is the
 * value of the symbolic link.
 * 
 * If the readlink(2) operation fails on any name, then the
 * corresponding result string is the empty string "".
 * However the whole operation is completed even if there
 * were readlink(2) errors, and so you can call this
 * function with names where you don't know if they are
 * symbolic links already (albeit slightly less efficient).
 * 
 * This call is intended for programs that want to
 * efficiently list a directory contents without making
 * many round-trips. Very long directory listings might
 * cause the protocol message size to be exceeded, causing
 * this call to fail. The caller must split up such
 * requests into smaller groups of names.
 * 
 * @path: (transfer none) (type filename):
 * @names: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_readlinklist(GuestfsSession *session, const gchar *path, const gchar **names, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_readlinklist(g, path, names);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * read part of a file
 *
 * This command lets you read part of a file. It reads
 * "count" bytes of the file, starting at "offset", from
 * file "path".
 * 
 * This may read fewer bytes than requested. For further
 * details see the pread(2) system call.
 * 
 * See also "guestfs_pwrite", "guestfs_pread_device".
 * 
 * @path: (transfer none) (type filename):
 * @count:
 * @offset:
 *
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint *guestfs_session_pread(GuestfsSession *session, const gchar *path, gint32 count, gint64 offset, gsize *size_r, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_pread(g, path, count, offset, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * create an empty partition table
 *
 * This creates an empty partition table on "device" of one
 * of the partition types listed below. Usually "parttype"
 * should be either "msdos" or "gpt" (for large disks).
 * 
 * Initially there are no partitions. Following this, you
 * should call "guestfs_part_add" for each partition
 * required.
 * 
 * Possible values for "parttype" are:
 * 
 * efi
 * gpt Intel EFI / GPT partition table.
 * 
 * This is recommended for >= 2 TB partitions that will
 * be accessed from Linux and Intel-based Mac OS X. It
 * also has limited backwards compatibility with the
 * "mbr" format.
 * 
 * mbr
 * msdos
 * The standard PC "Master Boot Record" (MBR) format
 * used by MS-DOS and Windows. This partition type will
 * only work for device sizes up to 2 TB. For large
 * disks we recommend using "gpt".
 * 
 * Other partition table types that may work but are not
 * supported include:
 * 
 * aix AIX disk labels.
 * 
 * amiga
 * rdb Amiga "Rigid Disk Block" format.
 * 
 * bsd BSD disk labels.
 * 
 * dasd
 * DASD, used on IBM mainframes.
 * 
 * dvh MIPS/SGI volumes.
 * 
 * mac Old Mac partition format. Modern Macs use "gpt".
 * 
 * pc98
 * NEC PC-98 format, common in Japan apparently.
 * 
 * sun Sun disk labels.
 * 
 * @device: (transfer none) (type filename):
 * @parttype: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_part_init(GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_init(g, device, parttype);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add a partition to the device
 *
 * This command adds a partition to "device". If there is
 * no partition table on the device, call
 * "guestfs_part_init" first.
 * 
 * The "prlogex" parameter is the type of partition.
 * Normally you should pass "p" or "primary" here, but MBR
 * partition tables also support "l" (or "logical") and "e"
 * (or "extended") partition types.
 * 
 * "startsect" and "endsect" are the start and end of the
 * partition in *sectors*. "endsect" may be negative, which
 * means it counts backwards from the end of the disk (-1
 * is the last sector).
 * 
 * Creating a partition which covers the whole disk is not
 * so easy. Use "guestfs_part_disk" to do that.
 * 
 * @device: (transfer none) (type filename):
 * @prlogex: (transfer none) (type utf8):
 * @startsect:
 * @endsect:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_part_add(GuestfsSession *session, const gchar *device, const gchar *prlogex, gint64 startsect, gint64 endsect, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_add(g, device, prlogex, startsect, endsect);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * partition whole disk with a single primary partition
 *
 * This command is simply a combination of
 * "guestfs_part_init" followed by "guestfs_part_add" to
 * create a single primary partition covering the whole
 * disk.
 * 
 * "parttype" is the partition table type, usually "mbr" or
 * "gpt", but other possible values are described in
 * "guestfs_part_init".
 * 
 * @device: (transfer none) (type filename):
 * @parttype: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_part_disk(GuestfsSession *session, const gchar *device, const gchar *parttype, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_disk(g, device, parttype);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * make a partition bootable
 *
 * This sets the bootable flag on partition numbered
 * "partnum" on device "device". Note that partitions are
 * numbered from 1.
 * 
 * The bootable flag is used by some operating systems
 * (notably Windows) to determine which partition to boot
 * from. It is by no means universally recognized.
 * 
 * @device: (transfer none) (type filename):
 * @partnum:
 * @bootable:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_part_set_bootable(GuestfsSession *session, const gchar *device, gint32 partnum, gboolean bootable, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_set_bootable(g, device, partnum, bootable);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * set partition name
 *
 * This sets the partition name on partition numbered
 * "partnum" on device "device". Note that partitions are
 * numbered from 1.
 * 
 * The partition name can only be set on certain types of
 * partition table. This works on "gpt" but not on "mbr"
 * partitions.
 * 
 * @device: (transfer none) (type filename):
 * @partnum:
 * @name: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_part_set_name(GuestfsSession *session, const gchar *device, gint32 partnum, const gchar *name, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_set_name(g, device, partnum, name);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * list partitions on a device
 *
 * This command parses the partition table on "device" and
 * returns the list of partitions found.
 * 
 * The fields in the returned structure are:
 * 
 * part_num
 * Partition number, counting from 1.
 * 
 * part_start
 * Start of the partition *in bytes*. To get sectors
 * you have to divide by the device's sector size, see
 * "guestfs_blockdev_getss".
 * 
 * part_end
 * End of the partition in bytes.
 * 
 * part_size
 * Size of the partition in bytes.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type Partition): an array of Partition objects, or NULL on error
 */
GuestfsPartition **guestfs_session_part_list(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  struct guestfs_partition_list *ret = guestfs_part_list(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GuestfsPartList **l = g_malloc(sizeof GuestfsPartList* * (ret->len + 1));
  gsize_t i;
  for(i = 0; i < ret->len; i++) {
    GuestfsPartList *s = g_slice_new(GuestfsPartList);
    s->part_num = ret->val[i]->part_num;
    s->part_start = ret->val[i]->part_start;
    s->part_end = ret->val[i]->part_end;
    s->part_size = ret->val[i]->part_size;
  guestfs_free_partition(ret);
    l[i] = s;
  }
  l[i] = NULL;
  return l;
}

/**
 * get the partition table type
 *
 * This command examines the partition table on "device"
 * and returns the partition table type (format) being
 * used.
 * 
 * Common return values include: "msdos" (a DOS/Windows
 * style MBR partition table), "gpt" (a GPT/EFI-style
 * partition table). Other values are possible, although
 * unusual. See "guestfs_part_init" for a full list.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_part_get_parttype(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_part_get_parttype(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * fill a file with octets
 *
 * This command creates a new file called "path". The
 * initial content of the file is "len" octets of "c",
 * where "c" must be a number in the range "[0..255]".
 * 
 * To fill a file with zero bytes (sparsely), it is much
 * more efficient to use "guestfs_truncate_size". To create
 * a file with a pattern of repeating bytes use
 * "guestfs_fill_pattern".
 * 
 * @c:
 * @len:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_fill(GuestfsSession *session, gint32 c, gint32 len, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_fill(g, c, len, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * test availability of some parts of the API
 *
 * This command is used to check the availability of some
 * groups of functionality in the appliance, which not all
 * builds of the libguestfs appliance will be able to
 * provide.
 * 
 * The libguestfs groups, and the functions that those
 * groups correspond to, are listed in "AVAILABILITY" in
 * guestfs(3). You can also fetch this list at runtime by
 * calling "guestfs_available_all_groups".
 * 
 * The argument "groups" is a list of group names, eg:
 * "["inotify", "augeas"]" would check for the availability
 * of the Linux inotify functions and Augeas (configuration
 * file editing) functions.
 * 
 * The command returns no error if *all* requested groups
 * are available.
 * 
 * It fails with an error if one or more of the requested
 * groups is unavailable in the appliance.
 * 
 * If an unknown group name is included in the list of
 * groups then an error is always returned.
 * 
 * *Notes:*
 * 
 * *   You must call "guestfs_launch" before calling this
 * function.
 * 
 * The reason is because we don't know what groups are
 * supported by the appliance/daemon until it is
 * running and can be queried.
 * 
 * *   If a group of functions is available, this does not
 * necessarily mean that they will work. You still have
 * to check for errors when calling individual API
 * functions even if they are available.
 * 
 * *   It is usually the job of distro packagers to build
 * complete functionality into the libguestfs
 * appliance. Upstream libguestfs, if built from source
 * with all requirements satisfied, will support
 * everything.
 * 
 * *   This call was added in version 1.0.80. In previous
 * versions of libguestfs all you could do would be to
 * speculatively execute a command to find out if the
 * daemon implemented it. See also "guestfs_version".
 * 
 * @groups: (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_available(GuestfsSession *session, const gchar **groups, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_available(g, groups);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * copy from source to destination using dd
 *
 * This command copies from one source device or file "src"
 * to another destination device or file "dest". Normally
 * you would use this to copy to or from a device or
 * partition, for example to duplicate a filesystem.
 * 
 * If the destination is a device, it must be as large or
 * larger than the source file or device, otherwise the
 * copy will fail. This command cannot do partial copies
 * (see "guestfs_copy_device_to_device").
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_dd(GuestfsSession *session, const gchar *src, const gchar *dest, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_dd(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * return the size of the file in bytes
 *
 * This command returns the size of "file" in bytes.
 * 
 * To get other stats about a file, use "guestfs_stat",
 * "guestfs_lstat", "guestfs_is_dir", "guestfs_is_file"
 * etc. To get the size of block devices, use
 * "guestfs_blockdev_getsize64".
 * 
 * @file: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint64 guestfs_session_filesize(GuestfsSession *session, const gchar *file, GError **err){
  guestfs_h *g = session->priv->g;
  int64_t ret = guestfs_filesize(g, file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * rename an LVM logical volume
 *
 * Rename a logical volume "logvol" with the new name
 * "newlogvol".
 * 
 * @logvol: (transfer none) (type utf8):
 * @newlogvol: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvrename(GuestfsSession *session, const gchar *logvol, const gchar *newlogvol, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvrename(g, logvol, newlogvol);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * rename an LVM volume group
 *
 * Rename a volume group "volgroup" with the new name
 * "newvolgroup".
 * 
 * @volgroup: (transfer none) (type utf8):
 * @newvolgroup: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_vgrename(GuestfsSession *session, const gchar *volgroup, const gchar *newvolgroup, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_vgrename(g, volgroup, newvolgroup);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * list the contents of a single file in an initrd
 *
 * This command unpacks the file "filename" from the initrd
 * file called "initrdpath". The filename must be given
 * *without* the initial "/" character.
 * 
 * For example, in guestfish you could use the following
 * command to examine the boot script (usually called
 * "/init") contained in a Linux initrd or initramfs image:
 * 
 * initrd-cat /boot/initrd-<version>.img init
 * 
 * See also "guestfs_initrd_list".
 * 
 * @initrdpath: (transfer none) (type filename):
 * @filename: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint *guestfs_session_initrd_cat(GuestfsSession *session, const gchar *initrdpath, const gchar *filename, gsize *size_r, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_initrd_cat(g, initrdpath, filename, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get the UUID of a physical volume
 *
 * This command returns the UUID of the LVM PV "device".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_pvuuid(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_pvuuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get the UUID of a volume group
 *
 * This command returns the UUID of the LVM VG named
 * "vgname".
 * 
 * @vgname: (transfer none) (type utf8):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_vguuid(GuestfsSession *session, const gchar *vgname, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_vguuid(g, vgname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get the UUID of a logical volume
 *
 * This command returns the UUID of the LVM LV "device".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_lvuuid(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_lvuuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get the PV UUIDs containing the volume group
 *
 * Given a VG called "vgname", this returns the UUIDs of
 * all the physical volumes that this volume group resides
 * on.
 * 
 * You can use this along with "guestfs_pvs" and
 * "guestfs_pvuuid" calls to associate physical volumes and
 * volume groups.
 * 
 * See also "guestfs_vglvuuids".
 * 
 * @vgname: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_vgpvuuids(GuestfsSession *session, const gchar *vgname, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_vgpvuuids(g, vgname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get the LV UUIDs of all LVs in the volume group
 *
 * Given a VG called "vgname", this returns the UUIDs of
 * all the logical volumes created in this volume group.
 * 
 * You can use this along with "guestfs_lvs" and
 * "guestfs_lvuuid" calls to associate logical volumes and
 * volume groups.
 * 
 * See also "guestfs_vgpvuuids".
 * 
 * @vgname: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_vglvuuids(GuestfsSession *session, const gchar *vgname, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_vglvuuids(g, vgname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * copy size bytes from source to destination using dd
 *
 * This command copies exactly "size" bytes from one source
 * device or file "src" to another destination device or
 * file "dest".
 * 
 * Note this will fail if the source is too short or if the
 * destination is not large enough.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @size:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_copy_size(GuestfsSession *session, const gchar *src, const gchar *dest, gint64 size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_copy_size(g, src, dest, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * write zeroes to an entire device
 *
 * This command writes zeroes over the entire "device".
 * Compare with "guestfs_zero" which just zeroes the first
 * few blocks of a device.
 * 
 * If blocks are already zero, then this command avoids
 * writing zeroes. This prevents the underlying device from
 * becoming non-sparse or growing unnecessarily.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_zero_device(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_zero_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * unpack compressed tarball to directory
 *
 * This command uploads and unpacks local file "tarball"
 * (an *xz compressed* tar file) into "directory".
 * 
 * @tarball: (transfer none) (type filename):
 * @directory: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_txz_in(GuestfsSession *session, const gchar *tarball, const gchar *directory, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_txz_in(g, tarball, directory);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * pack directory into compressed tarball
 *
 * This command packs the contents of "directory" and
 * downloads it to local file "tarball" (as an xz
 * compressed tar archive).
 * 
 * @directory: (transfer none) (type filename):
 * @tarball: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_txz_out(GuestfsSession *session, const gchar *directory, const gchar *tarball, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_txz_out(g, directory, tarball);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * resize an NTFS filesystem
 *
 * This command resizes an NTFS filesystem, expanding or
 * shrinking it to the size of the underlying device.
 * 
 * *Note:* After the resize operation, the filesystem is
 * marked as requiring a consistency check (for safety).
 * You have to boot into Windows to perform this check and
 * clear this condition. Furthermore, ntfsresize refuses to
 * resize filesystems which have been marked in this way.
 * So in effect it is not possible to call ntfsresize
 * multiple times on a single filesystem without booting
 * into Windows between each resize.
 * 
 * See also ntfsresize(8).
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ntfsresize(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ntfsresize(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * rescan for LVM physical volumes, volume groups and logical volumes
 *
 * This rescans all block devices and rebuilds the list of
 * LVM physical volumes, volume groups and logical volumes.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_vgscan(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_vgscan(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * delete a partition
 *
 * This command deletes the partition numbered "partnum" on
 * "device".
 * 
 * Note that in the case of MBR partitioning, deleting an
 * extended partition also deletes any logical partitions
 * it contains.
 * 
 * @device: (transfer none) (type filename):
 * @partnum:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_part_del(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_del(g, device, partnum);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * return true if a partition is bootable
 *
 * This command returns true if the partition "partnum" on
 * "device" has the bootable flag set.
 * 
 * See also "guestfs_part_set_bootable".
 * 
 * @device: (transfer none) (type filename):
 * @partnum:
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_part_get_bootable(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_get_bootable(g, device, partnum);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * get the MBR type byte (ID byte) from a partition
 *
 * Returns the MBR type byte (also known as the ID byte)
 * from the numbered partition "partnum".
 * 
 * Note that only MBR (old DOS-style) partitions have type
 * bytes. You will get undefined results for other
 * partition table types (see "guestfs_part_get_parttype").
 * 
 * @device: (transfer none) (type filename):
 * @partnum:
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_part_get_mbr_id(GuestfsSession *session, const gchar *device, gint32 partnum, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_get_mbr_id(g, device, partnum);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * set the MBR type byte (ID byte) of a partition
 *
 * Sets the MBR type byte (also known as the ID byte) of
 * the numbered partition "partnum" to "idbyte". Note that
 * the type bytes quoted in most documentation are in fact
 * hexadecimal numbers, but usually documented without any
 * leading "0x" which might be confusing.
 * 
 * Note that only MBR (old DOS-style) partitions have type
 * bytes. You will get undefined results for other
 * partition table types (see "guestfs_part_get_parttype").
 * 
 * @device: (transfer none) (type filename):
 * @partnum:
 * @idbyte:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_part_set_mbr_id(GuestfsSession *session, const gchar *device, gint32 partnum, gint32 idbyte, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_set_mbr_id(g, device, partnum, idbyte);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * compute MD5, SHAx or CRC checksum of the contents of a device
 *
 * This call computes the MD5, SHAx or CRC checksum of the
 * contents of the device named "device". For the types of
 * checksums supported see the "guestfs_checksum" command.
 * 
 * @csumtype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_checksum_device(GuestfsSession *session, const gchar *csumtype, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_checksum_device(g, csumtype, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * expand an LV to fill free space
 *
 * This expands an existing logical volume "lv" so that it
 * fills "pc"% of the remaining free space in the volume
 * group. Commonly you would call this with pc = 100 which
 * expands the logical volume as much as possible, using
 * all remaining free space in the volume group.
 * 
 * @lv: (transfer none) (type filename):
 * @percent:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvresize_free(GuestfsSession *session, const gchar *lv, gint32 percent, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvresize_free(g, lv, percent);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * clear Augeas path
 *
 * Set the value associated with "path" to "NULL". This is
 * the same as the augtool(1) "clear" command.
 * 
 * @augpath: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_aug_clear(GuestfsSession *session, const gchar *augpath, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_aug_clear(g, augpath);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the current umask
 *
 * Return the current umask. By default the umask is 022
 * unless it has been set by calling "guestfs_umask".
 * 
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_get_umask(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_get_umask(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * upload a file to the appliance (internal use only)
 *
 * The "guestfs_debug_upload" command uploads a file to the
 * libguestfs appliance.
 * 
 * There is no comprehensive help for this command. You
 * have to look at the file "daemon/debug.c" in the
 * libguestfs source to find out what it is for.
 * 
 * @filename: (transfer none) (type filename):
 * @tmpname: (transfer none) (type utf8):
 * @mode:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_debug_upload(GuestfsSession *session, const gchar *filename, const gchar *tmpname, gint32 mode, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_debug_upload(g, filename, tmpname, mode);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * upload base64-encoded data to file
 *
 * This command uploads base64-encoded data from
 * "base64file" to "filename".
 * 
 * @base64file: (transfer none) (type filename):
 * @filename: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_base64_in(GuestfsSession *session, const gchar *base64file, const gchar *filename, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_base64_in(g, base64file, filename);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * download file and encode as base64
 *
 * This command downloads the contents of "filename",
 * writing it out to local file "base64file" encoded as
 * base64.
 * 
 * @filename: (transfer none) (type filename):
 * @base64file: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_base64_out(GuestfsSession *session, const gchar *filename, const gchar *base64file, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_base64_out(g, filename, base64file);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * compute MD5, SHAx or CRC checksum of files in a directory
 *
 * This command computes the checksums of all regular files
 * in "directory" and then emits a list of those checksums
 * to the local output file "sumsfile".
 * 
 * This can be used for verifying the integrity of a
 * virtual machine. However to be properly secure you
 * should pay attention to the output of the checksum
 * command (it uses the ones from GNU coreutils). In
 * particular when the filename is not printable, coreutils
 * uses a special backslash syntax. For more information,
 * see the GNU coreutils info file.
 * 
 * @csumtype: (transfer none) (type utf8):
 * @directory: (transfer none) (type filename):
 * @sumsfile: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_checksums_out(GuestfsSession *session, const gchar *csumtype, const gchar *directory, const gchar *sumsfile, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_checksums_out(g, csumtype, directory, sumsfile);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * fill a file with a repeating pattern of bytes
 *
 * This function is like "guestfs_fill" except that it
 * creates a new file of length "len" containing the
 * repeating pattern of bytes in "pattern". The pattern is
 * truncated if necessary to ensure the length of the file
 * is exactly "len" bytes.
 * 
 * @pattern: (transfer none) (type utf8):
 * @len:
 * @path: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_fill_pattern(GuestfsSession *session, const gchar *pattern, gint32 len, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_fill_pattern(g, pattern, len, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a new file
 *
 * This call creates a file called "path". The content of
 * the file is the string "content" (which can contain any
 * 8 bit data).
 * 
 * See also "guestfs_write_append".
 * 
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_write(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_write(g, path, content, content_size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * write to part of a file
 *
 * This command writes to part of a file. It writes the
 * data buffer "content" to the file "path" starting at
 * offset "offset".
 * 
 * This command implements the pwrite(2) system call, and
 * like that system call it may not write the full data
 * requested. The return value is the number of bytes that
 * were actually written to the file. This could even be 0,
 * although short writes are unlikely for regular files in
 * ordinary circumstances.
 * 
 * See also "guestfs_pread", "guestfs_pwrite_device".
 * 
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 * @offset:
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_pwrite(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, gint64 offset, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_pwrite(g, path, content, content_size, offset);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * resize an ext2, ext3 or ext4 filesystem (with size)
 *
 * This command is the same as "guestfs_resize2fs" except
 * that it allows you to specify the new size (in bytes)
 * explicitly.
 * 
 * @device: (transfer none) (type filename):
 * @size:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_resize2fs_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_resize2fs_size(g, device, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * resize an LVM physical volume (with size)
 *
 * This command is the same as "guestfs_pvresize" except
 * that it allows you to specify the new size (in bytes)
 * explicitly.
 * 
 * @device: (transfer none) (type filename):
 * @size:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_pvresize_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_pvresize_size(g, device, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * resize an NTFS filesystem (with size)
 *
 * This command is the same as "guestfs_ntfsresize" except
 * that it allows you to specify the new size (in bytes)
 * explicitly.
 * 
 * @device: (transfer none) (type filename):
 * @size:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ntfsresize_size(GuestfsSession *session, const gchar *device, gint64 size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ntfsresize_size(g, device, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * return a list of all optional groups
 *
 * This command returns a list of all optional groups that
 * this daemon knows about. Note this returns both
 * supported and unsupported groups. To find out which ones
 * the daemon can actually support you have to call
 * "guestfs_available" on each member of the returned list.
 * 
 * See also "guestfs_available" and "AVAILABILITY" in
 * guestfs(3).
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_available_all_groups(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_available_all_groups(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * preallocate a file in the guest filesystem
 *
 * This command preallocates a file (containing zero bytes)
 * named "path" of size "len" bytes. If the file exists
 * already, it is overwritten.
 * 
 * Note that this call allocates disk blocks for the file.
 * To create a sparse file use "guestfs_truncate_size"
 * instead.
 * 
 * The deprecated call "guestfs_fallocate" does the same,
 * but owing to an oversight it only allowed 30 bit lengths
 * to be specified, effectively limiting the maximum size
 * of files created through that call to 1GB.
 * 
 * Do not confuse this with the guestfish-specific "alloc"
 * and "sparse" commands which create a file in the host
 * and attach it as a device.
 * 
 * @path: (transfer none) (type filename):
 * @len:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_fallocate64(GuestfsSession *session, const gchar *path, gint64 len, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_fallocate64(g, path, len);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get the filesystem label
 *
 * This returns the filesystem label of the filesystem on
 * "device".
 * 
 * If the filesystem is unlabeled, this returns the empty
 * string.
 * 
 * To find a filesystem from the label, use
 * "guestfs_findfs_label".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_vfs_label(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_vfs_label(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get the filesystem UUID
 *
 * This returns the filesystem UUID of the filesystem on
 * "device".
 * 
 * If the filesystem does not have a UUID, this returns the
 * empty string.
 * 
 * To find a filesystem from the UUID, use
 * "guestfs_findfs_uuid".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_vfs_uuid(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_vfs_uuid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * set LVM device filter
 *
 * This sets the LVM device filter so that LVM will only be
 * able to "see" the block devices in the list "devices",
 * and will ignore all other attached block devices.
 * 
 * Where disk image(s) contain duplicate PVs or VGs, this
 * command is useful to get LVM to ignore the duplicates,
 * otherwise LVM can get confused. Note also there are two
 * types of duplication possible: either cloned PVs/VGs
 * which have identical UUIDs; or VGs that are not cloned
 * but just happen to have the same name. In normal
 * operation you cannot create this situation, but you can
 * do it outside LVM, eg. by cloning disk images or by bit
 * twiddling inside the LVM metadata.
 * 
 * This command also clears the LVM cache and performs a
 * volume group scan.
 * 
 * You can filter whole block devices or individual
 * partitions.
 * 
 * You cannot use this if any VG is currently in use (eg.
 * contains a mounted filesystem), even if you are not
 * filtering out that VG.
 * 
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvm_set_filter(GuestfsSession *session, const gchar **devices, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvm_set_filter(g, devices);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * clear LVM device filter
 *
 * This undoes the effect of "guestfs_lvm_set_filter". LVM
 * will be able to see every block device.
 * 
 * This command also clears the LVM cache and performs a
 * volume group scan.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_lvm_clear_filter(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_lvm_clear_filter(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * open a LUKS-encrypted block device
 *
 * This command opens a block device which has been
 * encrypted according to the Linux Unified Key Setup
 * (LUKS) standard.
 * 
 * "device" is the encrypted block device or partition.
 * 
 * The caller must supply one of the keys associated with
 * the LUKS block device, in the "key" parameter.
 * 
 * This creates a new block device called
 * "/dev/mapper/mapname". Reads and writes to this block
 * device are decrypted from and encrypted to the
 * underlying "device" respectively.
 * 
 * If this block device contains LVM volume groups, then
 * calling "guestfs_vgscan" followed by
 * "guestfs_vg_activate_all" will make them visible.
 * 
 * Use "guestfs_list_dm_devices" to list all device mapper
 * devices.
 * 
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @mapname: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_luks_open(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_luks_open(g, device, key, mapname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * open a LUKS-encrypted block device read-only
 *
 * This is the same as "guestfs_luks_open" except that a
 * read-only mapping is created.
 * 
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @mapname: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_luks_open_ro(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *mapname, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_luks_open_ro(g, device, key, mapname);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * close a LUKS device
 *
 * This closes a LUKS device that was created earlier by
 * "guestfs_luks_open" or "guestfs_luks_open_ro". The
 * "device" parameter must be the name of the LUKS mapping
 * device (ie. "/dev/mapper/mapname") and *not* the name of
 * the underlying block device.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_luks_close(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_luks_close(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * format a block device as a LUKS encrypted device
 *
 * This command erases existing data on "device" and
 * formats the device as a LUKS encrypted device. "key" is
 * the initial key, which is added to key slot "slot".
 * (LUKS supports 8 key slots, numbered 0-7).
 * 
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @keyslot:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_luks_format(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_luks_format(g, device, key, keyslot);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * format a block device as a LUKS encrypted device
 *
 * This command is the same as "guestfs_luks_format" but it
 * also allows you to set the "cipher" used.
 * 
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @keyslot:
 * @cipher: (transfer none) (type utf8):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_luks_format_cipher(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, const gchar *cipher, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_luks_format_cipher(g, device, key, keyslot, cipher);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * add a key on a LUKS encrypted device
 *
 * This command adds a new key on LUKS device "device".
 * "key" is any existing key, and is used to access the
 * device. "newkey" is the new key to add. "keyslot" is the
 * key slot that will be replaced.
 * 
 * Note that if "keyslot" already contains a key, then this
 * command will fail. You have to use
 * "guestfs_luks_kill_slot" first to remove that key.
 * 
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @newkey: (transfer none) (type utf8):
 * @keyslot:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_luks_add_key(GuestfsSession *session, const gchar *device, const gchar *key, const gchar *newkey, gint32 keyslot, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_luks_add_key(g, device, key, newkey, keyslot);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * remove a key from a LUKS encrypted device
 *
 * This command deletes the key in key slot "keyslot" from
 * the encrypted LUKS device "device". "key" must be one of
 * the *other* keys.
 * 
 * @device: (transfer none) (type filename):
 * @key: (transfer none) (type utf8):
 * @keyslot:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_luks_kill_slot(GuestfsSession *session, const gchar *device, const gchar *key, gint32 keyslot, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_luks_kill_slot(g, device, key, keyslot);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * test if device is a logical volume
 *
 * This command tests whether "device" is a logical volume,
 * and returns true iff this is the case.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_lv(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_lv(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * find a filesystem by UUID
 *
 * This command searches the filesystems and returns the
 * one which has the given UUID. An error is returned if no
 * such filesystem can be found.
 * 
 * To find the UUID of a filesystem, use
 * "guestfs_vfs_uuid".
 * 
 * @uuid: (transfer none) (type utf8):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_findfs_uuid(GuestfsSession *session, const gchar *uuid, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_findfs_uuid(g, uuid);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * find a filesystem by label
 *
 * This command searches the filesystems and returns the
 * one which has the given label. An error is returned if
 * no such filesystem can be found.
 * 
 * To find the label of a filesystem, use
 * "guestfs_vfs_label".
 * 
 * @label: (transfer none) (type utf8):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_findfs_label(GuestfsSession *session, const gchar *label, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_findfs_label(g, label);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * test if character device
 *
 * This returns "true" if and only if there is a character
 * device with the given "path" name.
 * 
 * See also "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_chardev(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_chardev(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * test if block device
 *
 * This returns "true" if and only if there is a block
 * device with the given "path" name.
 * 
 * See also "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_blockdev(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_blockdev(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * test if FIFO (named pipe)
 *
 * This returns "true" if and only if there is a FIFO
 * (named pipe) with the given "path" name.
 * 
 * See also "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_fifo(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_fifo(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * test if symbolic link
 *
 * This returns "true" if and only if there is a symbolic
 * link with the given "path" name.
 * 
 * See also "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_symlink(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_symlink(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * test if socket
 *
 * This returns "true" if and only if there is a Unix
 * domain socket with the given "path" name.
 * 
 * See also "guestfs_stat".
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_socket(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_socket(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * convert partition name to device name
 *
 * This function takes a partition name (eg. "/dev/sdb1")
 * and removes the partition number, returning the device
 * name (eg. "/dev/sdb").
 * 
 * The named partition must exist, for example as a string
 * returned from "guestfs_list_partitions".
 * 
 * See also "guestfs_part_to_partnum".
 * 
 * @partition: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_part_to_dev(GuestfsSession *session, const gchar *partition, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_part_to_dev(g, partition);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * upload a file from the local machine with offset
 *
 * Upload local file "filename" to "remotefilename" on the
 * filesystem.
 * 
 * "remotefilename" is overwritten starting at the byte
 * "offset" specified. The intention is to overwrite parts
 * of existing files or devices, although if a non-existant
 * file is specified then it is created with a "hole"
 * before "offset". The size of the data written is
 * implicit in the size of the source "filename".
 * 
 * Note that there is no limit on the amount of data that
 * can be uploaded with this call, unlike with
 * "guestfs_pwrite", and this call always writes the full
 * amount unless an error occurs.
 * 
 * See also "guestfs_upload", "guestfs_pwrite".
 * 
 * @filename: (transfer none) (type filename):
 * @remotefilename: (transfer none) (type filename):
 * @offset:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_upload_offset(GuestfsSession *session, const gchar *filename, const gchar *remotefilename, gint64 offset, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_upload_offset(g, filename, remotefilename, offset);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * download a file to the local machine with offset and size
 *
 * Download file "remotefilename" and save it as "filename"
 * on the local machine.
 * 
 * "remotefilename" is read for "size" bytes starting at
 * "offset" (this region must be within the file or
 * device).
 * 
 * Note that there is no limit on the amount of data that
 * can be downloaded with this call, unlike with
 * "guestfs_pread", and this call always reads the full
 * amount unless an error occurs.
 * 
 * See also "guestfs_download", "guestfs_pread".
 * 
 * @remotefilename: (transfer none) (type filename):
 * @filename: (transfer none) (type filename):
 * @offset:
 * @size:
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_download_offset(GuestfsSession *session, const gchar *remotefilename, const gchar *filename, gint64 offset, gint64 size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_download_offset(g, remotefilename, filename, offset, size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * write to part of a device
 *
 * This command writes to part of a device. It writes the
 * data buffer "content" to "device" starting at offset
 * "offset".
 * 
 * This command implements the pwrite(2) system call, and
 * like that system call it may not write the full data
 * requested (although short writes to disk devices and
 * partitions are probably impossible with standard Linux
 * kernels).
 * 
 * See also "guestfs_pwrite".
 * 
 * @device: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 * @offset:
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_pwrite_device(GuestfsSession *session, const gchar *device, const guint8 *content, gsize content_size, gint64 offset, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_pwrite_device(g, device, content, content_size, offset);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * read part of a device
 *
 * This command lets you read part of a file. It reads
 * "count" bytes of "device", starting at "offset".
 * 
 * This may read fewer bytes than requested. For further
 * details see the pread(2) system call.
 * 
 * See also "guestfs_pread".
 * 
 * @device: (transfer none) (type filename):
 * @count:
 * @offset:
 *
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint *guestfs_session_pread_device(GuestfsSession *session, const gchar *device, gint32 count, gint64 offset, gsize *size_r, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_pread_device(g, device, count, offset, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get canonical name of an LV
 *
 * This converts alternative naming schemes for LVs that
 * you might find to the canonical name. For example,
 * "/dev/mapper/VG-LV" is converted to "/dev/VG/LV".
 * 
 * This command returns an error if the "lvname" parameter
 * does not refer to a logical volume.
 * 
 * See also "guestfs_is_lv".
 * 
 * @lvname: (transfer none) (type filename):
 *
 * Returns: (transfer full): the returned string, or NULL on error
 */
gchar *guestfs_session_lvm_canonical_lv_name(GuestfsSession *session, const gchar *lvname, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_lvm_canonical_lv_name(g, lvname);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * make a filesystem
 *
 * This function creates a filesystem on "device". The
 * filesystem type is "fstype", for example "ext3".
 * 
 * The optional arguments are:
 * 
 * "blocksize"
 * The filesystem block size. Supported block sizes
 * depend on the filesystem type, but typically they
 * are 1024, 2048 or 4096 for Linux ext2/3 filesystems.
 * 
 * For VFAT and NTFS the "blocksize" parameter is
 * treated as the requested cluster size.
 * 
 * For UFS block sizes, please see mkfs.ufs(8).
 * 
 * "features"
 * This passes the *-O* parameter to the external mkfs
 * program.
 * 
 * For certain filesystem types, this allows extra
 * filesystem features to be selected. See mke2fs(8)
 * and mkfs.ufs(8) for more details.
 * 
 * You cannot use this optional parameter with the
 * "gfs" or "gfs2" filesystem type.
 * 
 * "inode"
 * This passes the *-I* parameter to the external
 * mke2fs(8) program which sets the inode size (only
 * for ext2/3/4 filesystems at present).
 * 
 * "sectorsize"
 * This passes the *-S* parameter to external
 * mkfs.ufs(8) program, which sets sector size for ufs
 * filesystem.
 * 
 * @fstype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsMkfsOpts containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mkfs_opts(GuestfsSession *session, const gchar *fstype, const gchar *device, GuestfsMkfsOpts *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mkfs_opts(g, fstype, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * get a single extended attribute
 *
 * Get a single extended attribute from file "path" named
 * "name". This call follows symlinks. If you want to
 * lookup an extended attribute for the symlink itself, use
 * "guestfs_lgetxattr".
 * 
 * Normally it is better to get all extended attributes
 * from a file in one go by calling "guestfs_getxattrs".
 * However some Linux filesystem implementations are buggy
 * and do not provide a way to list out attributes. For
 * these filesystems (notably ntfs-3g) you have to know the
 * names of the extended attributes you want in advance and
 * call this function.
 * 
 * Extended attribute values are blobs of binary data. If
 * there is no extended attribute named "name", this
 * returns an error.
 * 
 * See also: "guestfs_getxattrs", "guestfs_lgetxattr",
 * attr(5).
 * 
 * @path: (transfer none) (type filename):
 * @name: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint *guestfs_session_getxattr(GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_getxattr(g, path, name, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * get a single extended attribute
 *
 * Get a single extended attribute from file "path" named
 * "name". If "path" is a symlink, then this call returns
 * an extended attribute from the symlink.
 * 
 * Normally it is better to get all extended attributes
 * from a file in one go by calling "guestfs_getxattrs".
 * However some Linux filesystem implementations are buggy
 * and do not provide a way to list out attributes. For
 * these filesystems (notably ntfs-3g) you have to know the
 * names of the extended attributes you want in advance and
 * call this function.
 * 
 * Extended attribute values are blobs of binary data. If
 * there is no extended attribute named "name", this
 * returns an error.
 * 
 * See also: "guestfs_lgetxattrs", "guestfs_getxattr",
 * attr(5).
 * 
 * @path: (transfer none) (type filename):
 * @name: (transfer none) (type utf8):
 *
 * Returns: (transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error
 */
guint *guestfs_session_lgetxattr(GuestfsSession *session, const gchar *path, const gchar *name, gsize *size_r, GError **err){
  guestfs_h *g = session->priv->g;
  char *ret = guestfs_lgetxattr(g, path, name, size_r);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * resize an ext2, ext3 or ext4 filesystem to the minimum size
 *
 * This command is the same as "guestfs_resize2fs", but the
 * filesystem is resized to its minimum size. This works
 * like the *-M* option to the "resize2fs" command.
 * 
 * To get the resulting size of the filesystem you should
 * call "guestfs_tune2fs_l" and read the "Block size" and
 * "Block count" values. These two numbers, multiplied
 * together, give the resulting size of the minimal
 * filesystem in bytes.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_resize2fs_M(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_resize2fs_M(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * internal autosync operation
 *
 * This command performs the autosync operation just before
 * the handle is closed. You should not call this command
 * directly. Instead, use the autosync flag
 * ("guestfs_set_autosync") to control whether or not this
 * operation is performed when the handle is closed.
 * 
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_internal_autosync(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_internal_autosync(g);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * test if a file contains all zero bytes
 *
 * This returns true iff the file exists and the file is
 * empty or it contains all zero bytes.
 * 
 * @path: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_zero(GuestfsSession *session, const gchar *path, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_zero(g, path);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * test if a device contains all zero bytes
 *
 * This returns true iff the device exists and contains all
 * zero bytes.
 * 
 * Note that for large devices this can take a long time to
 * run.
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint8 guestfs_session_is_zero_device(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_is_zero_device(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * list 9p filesystems
 *
 * List all 9p filesystems attached to the guest. A list of
 * mount tags is returned.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_list_9p(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_list_9p(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * mount 9p filesystem
 *
 * Mount the virtio-9p filesystem with the tag "mounttag"
 * on the directory "mountpoint".
 * 
 * If required, "trans=virtio" will be automatically added
 * to the options. Any other options required can be passed
 * in the optional "options" parameter.
 * 
 * @mounttag: (transfer none) (type utf8):
 * @mountpoint: (transfer none) (type utf8):
 * @optargs: (transfer none) (allow-none): a GuestfsMount9P containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_mount_9p(GuestfsSession *session, const gchar *mounttag, const gchar *mountpoint, GuestfsMount9P *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_mount_9p(g, mounttag, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * list device mapper devices
 *
 * List all device mapper devices.
 * 
 * The returned list contains "/dev/mapper/*" devices, eg.
 * ones created by a previous call to "guestfs_luks_open".
 * 
 * Device mapper devices which correspond to logical
 * volumes are *not* returned in this list. Call
 * "guestfs_lvs" if you want to list logical volumes.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_list_dm_devices(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_list_dm_devices(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * resize an NTFS filesystem
 *
 * This command resizes an NTFS filesystem, expanding or
 * shrinking it to the size of the underlying device.
 * 
 * The optional parameters are:
 * 
 * "size"
 * The new size (in bytes) of the filesystem. If
 * omitted, the filesystem is resized to fit the
 * container (eg. partition).
 * 
 * "force"
 * If this option is true, then force the resize of the
 * filesystem even if the filesystem is marked as
 * requiring a consistency check.
 * 
 * After the resize operation, the filesystem is always
 * marked as requiring a consistency check (for
 * safety). You have to boot into Windows to perform
 * this check and clear this condition. If you *don't*
 * set the "force" option then it is not possible to
 * call "guestfs_ntfsresize_opts" multiple times on a
 * single filesystem without booting into Windows
 * between each resize.
 * 
 * See also ntfsresize(8).
 * 
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsNTFSResizeOpts containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_ntfsresize_opts(GuestfsSession *session, const gchar *device, GuestfsNTFSResizeOpts *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_ntfsresize_opts(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * resize a btrfs filesystem
 *
 * This command resizes a btrfs filesystem.
 * 
 * Note that unlike other resize calls, the filesystem has
 * to be mounted and the parameter is the mountpoint not
 * the device (this is a requirement of btrfs itself).
 * 
 * The optional parameters are:
 * 
 * "size"
 * The new size (in bytes) of the filesystem. If
 * omitted, the filesystem is resized to the maximum
 * size.
 * 
 * See also btrfs(8).
 * 
 * @mountpoint: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsBTRFSFilesystemResize containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_btrfs_filesystem_resize(GuestfsSession *session, const gchar *mountpoint, GuestfsBTRFSFilesystemResize *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_btrfs_filesystem_resize(g, mountpoint);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * append content to end of file
 *
 * This call appends "content" to the end of file "path".
 * If "path" does not exist, then a new file is created.
 * 
 * See also "guestfs_write".
 * 
 * @path: (transfer none) (type filename):
 * @content: (transfer none) (array length=content_size) (element-type guint8): an array of binary data
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_write_append(GuestfsSession *session, const gchar *path, const guint8 *content, gsize content_size, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_write_append(g, path, content, content_size);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * output compressed file
 *
 * This command compresses "file" and writes it out to the
 * local file "zfile".
 * 
 * The compression program used is controlled by the
 * "ctype" parameter. Currently this includes: "compress",
 * "gzip", "bzip2", "xz" or "lzop". Some compression types
 * may not be supported by particular builds of libguestfs,
 * in which case you will get an error containing the
 * substring "not supported".
 * 
 * The optional "level" parameter controls compression
 * level. The meaning and default for this parameter
 * depends on the compression program being used.
 * 
 * @ctype: (transfer none) (type utf8):
 * @file: (transfer none) (type filename):
 * @zfile: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCompressOut containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_compress_out(GuestfsSession *session, const gchar *ctype, const gchar *file, const gchar *zfile, GuestfsCompressOut *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_compress_out(g, ctype, file, zfile);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * output compressed device
 *
 * This command compresses "device" and writes it out to
 * the local file "zdevice".
 * 
 * The "ctype" and optional "level" parameters have the
 * same meaning as in "guestfs_compress_out".
 * 
 * @ctype: (transfer none) (type utf8):
 * @device: (transfer none) (type filename):
 * @zdevice: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCompressDeviceOut containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_compress_device_out(GuestfsSession *session, const gchar *ctype, const gchar *device, const gchar *zdevice, GuestfsCompressDeviceOut *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_compress_device_out(g, ctype, device, zdevice);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * convert partition name to partition number
 *
 * This function takes a partition name (eg. "/dev/sdb1")
 * and returns the partition number (eg. 1).
 * 
 * The named partition must exist, for example as a string
 * returned from "guestfs_list_partitions".
 * 
 * See also "guestfs_part_to_dev".
 * 
 * @partition: (transfer none) (type filename):
 *
 * Returns: the returned value, or -1 on error
 */
gint32 guestfs_session_part_to_partnum(GuestfsSession *session, const gchar *partition, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_part_to_partnum(g, partition);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return -1;
  }

  return ret;
}

/**
 * copy from source device to destination device
 *
 * The four calls "guestfs_copy_device_to_device",
 * "guestfs_copy_device_to_file",
 * "guestfs_copy_file_to_device", and
 * "guestfs_copy_file_to_file" let you copy from a source
 * (device|file) to a destination (device|file).
 * 
 * Partial copies can be made since you can specify
 * optionally the source offset, destination offset and
 * size to copy. These values are all specified in bytes.
 * If not given, the offsets both default to zero, and the
 * size defaults to copying as much as possible until we
 * hit the end of the source.
 * 
 * The source and destination may be the same object.
 * However overlapping regions may not be copied correctly.
 * 
 * If the destination is a file, it is created if required.
 * If the destination file is not large enough, it is
 * extended.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyDeviceToDevice containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_copy_device_to_device(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToDevice *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_copy_device_to_device(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * copy from source device to destination file
 *
 * See "guestfs_copy_device_to_device" for a general
 * overview of this call.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyDeviceToFile containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_copy_device_to_file(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyDeviceToFile *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_copy_device_to_file(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * copy from source file to destination device
 *
 * See "guestfs_copy_device_to_device" for a general
 * overview of this call.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyFileToDevice containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_copy_file_to_device(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToDevice *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_copy_file_to_device(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * copy from source file to destination file
 *
 * See "guestfs_copy_device_to_device" for a general
 * overview of this call.
 * 
 * This is not the function you want for copying files.
 * This is for copying blocks within existing files. See
 * "guestfs_cp", "guestfs_cp_a" and "guestfs_mv" for
 * general file copying and moving functions.
 * 
 * @src: (transfer none) (type filename):
 * @dest: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsCopyFileToFile containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_copy_file_to_file(GuestfsSession *session, const gchar *src, const gchar *dest, GuestfsCopyFileToFile *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_copy_file_to_file(g, src, dest);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * adjust ext2/ext3/ext4 filesystem parameters
 *
 * This call allows you to adjust various filesystem
 * parameters of an ext2/ext3/ext4 filesystem called
 * "device".
 * 
 * The optional parameters are:
 * 
 * "force"
 * Force tune2fs to complete the operation even in the
 * face of errors. This is the same as the tune2fs "-f"
 * option.
 * 
 * "maxmountcount"
 * Set the number of mounts after which the filesystem
 * is checked by e2fsck(8). If this is 0 then the
 * number of mounts is disregarded. This is the same as
 * the tune2fs "-c" option.
 * 
 * "mountcount"
 * Set the number of times the filesystem has been
 * mounted. This is the same as the tune2fs "-C"
 * option.
 * 
 * "errorbehavior"
 * Change the behavior of the kernel code when errors
 * are detected. Possible values currently are:
 * "continue", "remount-ro", "panic". In practice these
 * options don't really make any difference,
 * particularly for write errors.
 * 
 * This is the same as the tune2fs "-e" option.
 * 
 * "group"
 * Set the group which can use reserved filesystem
 * blocks. This is the same as the tune2fs "-g" option
 * except that it can only be specified as a number.
 * 
 * "intervalbetweenchecks"
 * Adjust the maximal time between two filesystem
 * checks (in seconds). If the option is passed as 0
 * then time-dependent checking is disabled.
 * 
 * This is the same as the tune2fs "-i" option.
 * 
 * "reservedblockspercentage"
 * Set the percentage of the filesystem which may only
 * be allocated by privileged processes. This is the
 * same as the tune2fs "-m" option.
 * 
 * "lastmounteddirectory"
 * Set the last mounted directory. This is the same as
 * the tune2fs "-M" option.
 * 
 * "reservedblockscount" Set the number of reserved
 * filesystem blocks. This is the same as the tune2fs "-r"
 * option.
 * "user"
 * Set the user who can use the reserved filesystem
 * blocks. This is the same as the tune2fs "-u" option
 * except that it can only be specified as a number.
 * 
 * To get the current values of filesystem parameters, see
 * "guestfs_tune2fs_l". For precise details of how tune2fs
 * works, see the tune2fs(8) man page.
 * 
 * @device: (transfer none) (type filename):
 * @optargs: (transfer none) (allow-none): a GuestfsTune2FS containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_tune2fs(GuestfsSession *session, const gchar *device, GuestfsTune2FS *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_tune2fs(g, device);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * create a Linux md (RAID) device
 *
 * Create a Linux md (RAID) device named "name" on the
 * devices in the list "devices".
 * 
 * The optional parameters are:
 * 
 * "missingbitmap"
 * A bitmap of missing devices. If a bit is set it
 * means that a missing device is added to the array.
 * The least significant bit corresponds to the first
 * device in the array.
 * 
 * As examples:
 * 
 * If "devices = ["/dev/sda"]" and "missingbitmap =
 * 0x1" then the resulting array would be "[<missing>,
 * "/dev/sda"]".
 * 
 * If "devices = ["/dev/sda"]" and "missingbitmap =
 * 0x2" then the resulting array would be "["/dev/sda",
 * <missing>]".
 * 
 * This defaults to 0 (no missing devices).
 * 
 * The length of "devices" + the number of bits set in
 * "missingbitmap" must equal "nrdevices" + "spare".
 * 
 * "nrdevices"
 * The number of active RAID devices.
 * 
 * If not set, this defaults to the length of "devices"
 * plus the number of bits set in "missingbitmap".
 * 
 * "spare"
 * The number of spare devices.
 * 
 * If not set, this defaults to 0.
 * 
 * "chunk"
 * The chunk size in bytes.
 * 
 * "level"
 * The RAID level, which can be one of: *linear*,
 * *raid0*, *0*, *stripe*, *raid1*, *1*, *mirror*,
 * *raid4*, *4*, *raid5*, *5*, *raid6*, *6*, *raid10*,
 * *10*. Some of these are synonymous, and more levels
 * may be added in future.
 * 
 * If not set, this defaults to "raid1".
 * 
 * @name: (transfer none) (type utf8):
 * @devices: (transfer none) (array zero-terminated=1) (element-type filename): an array of strings
 * @optargs: (transfer none) (allow-none): a GuestfsMDCreate containing optional arguments
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_md_create(GuestfsSession *session, const gchar *name, const gchar **devices, GuestfsMDCreate *optargs, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_md_create(g, name, devices);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * list Linux md (RAID) devices
 *
 * List all Linux md devices.
 * 
 *
 * Returns: (transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error
 */
gchar **guestfs_session_list_md_devices(GuestfsSession *session, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_list_md_devices(g);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  return ret;
}

/**
 * obtain metadata for an MD device
 *
 * This command exposes the output of 'mdadm -DY <md>'. The
 * following fields are usually present in the returned
 * hash. Other fields may also be present.
 * 
 * "level"
 * The raid level of the MD device.
 * 
 * "devices"
 * The number of underlying devices in the MD device.
 * 
 * "metadata"
 * The metadata version used.
 * 
 * "uuid"
 * The UUID of the MD device.
 * 
 * "name"
 * The name of the MD device.
 * 
 * @md: (transfer none) (type filename):
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_md_detail(GuestfsSession *session, const gchar *md, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_md_detail(g, md);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

/**
 * stop a Linux md (RAID) device
 *
 * This command deactivates the MD array named "md". The
 * device is stopped, but it is not destroyed or zeroed.
 * 
 * @md: (transfer none) (type filename):
 *
 * Returns: true on success, false on error
 */
gboolean guestfs_session_md_stop(GuestfsSession *session, const gchar *md, GError **err){
  guestfs_h *g = session->priv->g;
  int ret = guestfs_md_stop(g, md);
  if (ret == -1) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return FALSE;
  }

  return TRUE;
}

/**
 * print block device attributes
 *
 * This command returns block device attributes for
 * "device". The following fields are usually present in
 * the returned hash. Other fields may also be present.
 * 
 * "UUID"
 * The uuid of this device.
 * 
 * "LABEL"
 * The label of this device.
 * 
 * "VERSION"
 * The version of blkid command.
 * 
 * "TYPE"
 * The filesystem type or RAID of this device.
 * 
 * "USAGE"
 * The usage of this device, for example "filesystem"
 * or "raid".
 * 
 * @device: (transfer none) (type filename):
 *
 * Returns: (transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error
 */
GHashTable *guestfs_session_blkid(GuestfsSession *session, const gchar *device, GError **err){
  guestfs_h *g = session->priv->g;
  char **ret = guestfs_blkid(g, device);
  if (ret == NULL) {
    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));
    return NULL;
  }

  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);
  char **i = ret;
  while (*i) {
    char *key = *i; i++;
    char *value = *i; i++;
    g_hash_table_insert(h, key, value);
  }
;  free (ret);
  return h;
}

