(* libguestfs
 * Copyright (C) 2012 Red Hat Inc.
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *)

(* Please read generator/README first. *)

open Str

open Generator_actions
open Generator_docstrings
open Generator_pr
open Generator_structs
open Generator_types
open Generator_utils

let rec camel_of_name flags name =
  "Guestfs" ^
  try
    find_map (function CamelName n -> Some n | _ -> None) flags
  with Not_found ->
    List.fold_left (
      fun a b ->
        a ^ String.uppercase (Str.first_chars b 1) ^ Str.string_after b 1
    ) "" (Str.split (regexp "_") name)

and returns_error (ret:Generator_types.ret) = match ret with
  | RConstOptString _ -> false
  | _ -> true

and generate_gobject_proto name (ret, args, optargs) flags =
  (match ret with
   | RErr ->
      pr "gboolean "
   | RInt _ ->
      pr "gint32 "
   | RInt64 _ ->
      pr "gint64 "
   | RBool _ ->
      pr "gint8 "
   | RConstString _
   | RConstOptString _
   | RString _ ->
      pr "gchar *"
   | RStringList _ ->
      pr "gchar **"
   | RStruct (_, typ) ->
      let name = camel_name_of_struct typ in
      pr "Guestfs%s *" name
   | RStructList (_, typ) ->
      let name = camel_name_of_struct typ in
      pr "Guestfs%s **" name
   | RHashtable _ ->
      pr "GHashTable *"
   | RBufferOut _ ->
      pr "guint *"
  );
  pr "guestfs_session_%s(GuestfsSession *session" name;
  List.iter (
    fun arg ->
      pr ", ";
      match arg with
      | Bool n ->
        pr "gboolean %s" n
      | Int n ->
        pr "gint32 %s" n
      | Int64 n->
        pr "gint64 %s" n
      | String n
      | Device n
      | Pathname n
      | Dev_or_Path n
      | OptString n
      | Key n
      | FileIn n
      | FileOut n ->
        pr "const gchar *%s" n
      | StringList n
      | DeviceList n ->
        pr "const gchar **%s" n
      | BufferIn n ->
        pr "const guint8 *%s, gsize %s_size" n n
      | Pointer _ ->
        failwith "gobject bindings do not support Pointer arguments"
  ) args;
  if optargs <> [] then (
    pr ", %s *optargs" (camel_of_name flags name)
  );
  (match ret with
  | RBufferOut _ ->
    pr ", gsize *size_r"
  | _ -> ());
  if returns_error ret then pr ", GError **err";
  pr ")";

and generate_gobject_header_static () =
  pr "
#ifndef GUESTFS_GOBJECT_H__
#define GUESTFS_GOBJECT_H__

#include <glib-object.h>

G_BEGIN_DECLS

/* Guestfs::Session object definition */
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

"

and generate_gobject_header_structs () =
  pr "/* Structs */\n";
  List.iter (
    fun (typ, cols) ->
      let camel = camel_name_of_struct typ in
      pr "typedef struct _Guestfs%s Guestfs%s;\n" camel camel;
      pr "struct _Guestfs%s {\n" camel;
      List.iter (
        function
        | n, FChar ->
          pr "  gchar %s;\n" n
        | n, FUInt32 ->
          pr "  guint32 %s;\n" n
        | n, FInt32 ->
          pr "  gint32 %s;\n" n
        | n, (FUInt64|FBytes) ->
          pr "  guint64 %s;\n" n
        | n, FInt64 ->
          pr "  gint64 %s;\n" n
        | n, FString ->
          pr "  gchar *%s;\n" n
        | n, FBuffer ->
          pr "  guint8 *%s;\n" n;
          pr "  guint32 %s_size;\n" n
        | n, FUUID ->
          pr "  /* The next field is NOT nul-terminated, be careful when printing it: */\n";
          pr "  gchar %s[32];\n" n
        | n, FOptPercent ->
          pr "  /* The next field is [0..100] or -1 meaning 'not present': */\n";
          pr "  gfloat %s;\n" n
      ) cols;
      pr "};\n";
      pr "GType guestfs_%s_get_type(void);\n\n" typ;
  ) structs;

and iter_optargs f =
  List.iter (
    function
    | name, (_, _, (_::_ as optargs)), _, flags,_, _, _ ->
      f name optargs flags
    | _ -> ()
  )

and generate_gobject_header_optarg name optargs flags =
  let uc_name = String.uppercase name in
  let camel_name = camel_of_name flags name in
  let type_define = "GUESTFS_TYPE_" ^ uc_name in

  pr "/* %s */\n" camel_name;

  pr "#define %s " type_define;
  pr "(guestfs_%s_get_type())\n" name;

  pr "#define GUESTFS_%s(obj) " uc_name;
  pr "(G_TYPE_CHECK_INSTANCE_CAST((obj), %s, %s))\n" type_define camel_name;

  pr "#define GUESTFS_%s_CLASS(klass) " uc_name;
  pr "(G_TYPE_CHECK_CLASS_CAST((klass), %s, %sClass))\n" type_define camel_name;

  pr "#define GUESTFS_IS_%s(obj) " uc_name;
  pr "(G_TYPE_CHECK_INSTANCE_TYPE((klass), %s))\n" type_define;

  pr "#define GUESTFS_IS_%s_CLASS(klass) " uc_name;
  pr "(G_TYPE_CHECK_CLASS_TYPE((klass), %s))\n" type_define;

  pr "#define GUESTFS_%s_GET_CLASS(obj) " uc_name;
  pr "(G_TYPE_INSTANCE_GET_CLASS((obj), %s, %sClass))\n" type_define camel_name;

  pr "\n";

  List.iter (
    fun suffix ->
      let name = camel_name ^ suffix in
      pr "typedef struct _%s %s;\n" name name;
  ) [ ""; "Private"; "Class" ];

  pr "\n";

  pr "struct _%s {\n" camel_name;
  pr "  GObject parent;\n";
  pr "  %sPrivate *priv;\n" camel_name;
  pr "};\n\n";

  pr "struct _%sClass {\n" camel_name;
  pr "  GObjectClass parent_class;\n";
  pr "};\n\n";

  pr "GType guestfs_%s_get_type(void);\n" name;
  pr "%s *guestfs_%s_new(void);\n" camel_name name;

  pr "\n";

and generate_gobject_header_optargs () =
  pr "/* Optional arguments */\n\n";
  iter_optargs (
    fun name optargs flags ->
      generate_gobject_header_optarg name optargs flags
  ) all_functions;

and generate_gobject_header_methods () =
  pr "/* Generated methods */\n";
  List.iter (
    fun (name, style, _, flags, _, _, _) ->
      generate_gobject_proto name style flags;
      pr ";\n";
  ) all_functions;

and generate_gobject_c_static () =
  pr "
#include <glib.h>
#include <glib-object.h>
#include <guestfs.h>
#include <string.h>

#include <stdio.h>

#include \"guestfs-gobject.h\"

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
      { GUESTFS_TRISTATE_FALSE, \"GUESTFS_TRISTATE_FALSE\", \"false\" },
      { GUESTFS_TRISTATE_TRUE,  \"GUESTFS_TRISTATE_TRUE\",  \"true\" },
      { GUESTFS_TRISTATE_NONE,  \"GUESTFS_TRISTATE_NONE\",  \"none\" },
      { 0, NULL, NULL }
    };
    etype = g_enum_register_static(\"GuestfsTristate\", values);
  }
  return etype;
}

/* Error quark */

#define GUESTFS_ERROR guestfs_error_quark()

static GQuark
guestfs_error_quark(void)
{
  return g_quark_from_static_string(\"guestfs\");
}

"

and generate_gobject_c_structs () =
  pr "/* Structs */\n\n";
  List.iter (
    fun (typ, cols) ->
      let name = "guestfs_" ^ typ in
      let camel_name = "Guestfs" ^ camel_name_of_struct typ in
      pr "/* %s */\n" camel_name;

      pr "static %s *\n" camel_name;
      pr "%s_copy(%s *src)\n" name camel_name;
      pr "{\n";
      pr "  return g_slice_dup(%s, src);\n" camel_name;
      pr "}\n\n";

      pr "static void\n";
      pr "%s_free(%s *src)\n" name camel_name;
      pr "{\n";
      pr "  g_slice_free(%s, src);\n" camel_name;
      pr "}\n\n";

      pr "G_DEFINE_BOXED_TYPE(%s, %s, %s_copy, %s_free)\n\n"
         camel_name name name name;
  ) structs

and generate_gobject_c_optarg name optargs flags =
  let uc_name = String.uppercase name in
  let camel_name = camel_of_name flags name in
  let type_define = "GUESTFS_TYPE_" ^ uc_name in

  pr "/* %s */\n" camel_name;
  pr "#define GUESTFS_%s_GET_PRIVATE(obj) " uc_name;
  pr "(G_TYPE_INSTANCE_GET_PRIVATE((obj), %s, %sPrivate))\n\n"
    type_define camel_name;

  pr "struct _%sPrivate {\n" camel_name;
  List.iter (
    fun optargt ->
      let name = name_of_optargt optargt in
      let typ = match optargt with
      | OBool n   -> "GuestfsTristate "
      | OInt n    -> "gint "
      | OInt64 n  -> "gint64 "
      | OString n -> "gchar *" in
      pr "  %s%s;\n" typ name;
  ) optargs;
  pr "};\n\n";

  pr "G_DEFINE_TYPE(%s, guestfs_%s, G_TYPE_OBJECT);\n\n" camel_name name;

  pr "enum {\n";
  pr "PROP_GUESTFS_%s_PROP0" uc_name;
  List.iter (
    fun optargt ->
      let uc_optname = String.uppercase (name_of_optargt optargt) in
      pr ",\n  PROP_GUESTFS_%s_%s" uc_name uc_optname;
  ) optargs;
  pr "\n};\n\n";

  pr "static void\nguestfs_%s_set_property" name;
  pr "(GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)\n";
  pr "{\n";
  pr "  %s *self = GUESTFS_%s(object);\n" camel_name uc_name;
  pr "  %sPrivate *priv = self->priv;\n\n" camel_name;

  pr "  switch (property_id) {\n";
  List.iter (
    fun optargt ->
      let optname = name_of_optargt optargt in
      let uc_optname = String.uppercase optname in
      pr "    case PROP_GUESTFS_%s_%s:\n" uc_name uc_optname;
      (match optargt with
      | OString n ->
        pr "      g_free(priv->%s);\n" n;
      | OBool _ | OInt _ | OInt64 _ -> ());
      let set_value_func = match optargt with
      | OBool _   -> "g_value_get_enum"
      | OInt _    -> "g_value_get_int"
      | OInt64 _  -> "g_value_get_int64"
      | OString _ -> "g_value_dup_string"
      in
      pr "      priv->%s = %s(value);\n" optname set_value_func;
      pr "      break;\n\n";
  ) optargs;
  pr "    default:\n";
  pr "      /* Invalid property */\n";
  pr "      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);\n";
  pr "  }\n";
  pr "}\n\n";

  pr "static void\nguestfs_%s_get_property" name;
  pr "(GObject *object, guint property_id, GValue *value, GParamSpec *pspec)\n";
  pr "{\n";
  pr "  %s *self = GUESTFS_%s(object);\n" camel_name uc_name;
  pr "  %sPrivate *priv = self->priv;\n\n" camel_name;

  pr "  switch (property_id) {\n";
  List.iter (
    fun optargt ->
      let optname = name_of_optargt optargt in
      let uc_optname = String.uppercase optname in
      pr "    case PROP_GUESTFS_%s_%s:\n" uc_name uc_optname;
      let set_value_func = match optargt with
      | OBool _   -> "g_value_set_enum"
      | OInt _    -> "g_value_set_int"
      | OInt64 _  -> "g_value_set_int64"
      | OString _ -> "g_value_set_string"
      in
      pr "      g_value_set_%s(value, priv->%s);\n" set_value_func optname;
      pr "      break;\n\n";
  ) optargs;
  pr "    default:\n";
  pr "      /* Invalid property */\n";
  pr "      G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);\n";
  pr "  }\n";
  pr "}\n\n";

  pr "static void\nguestfs_%s_finalize(GObject *object)\n" name;
  pr "{\n";
  pr "  %s *self = GUESTFS_%s(object);\n" camel_name uc_name;
  pr "  %sPrivate *priv = self->priv;\n\n" camel_name;

  List.iter (
    function
    | OString n ->
      pr "  g_free(priv->%s);\n" n
    | OBool _ | OInt _ | OInt64 _ -> ()
  ) optargs;
  pr "\n";

  pr "  G_OBJECT_CLASS(guestfs_%s_parent_class)->finalize(object);\n" name;
  pr "}\n\n";

  pr "static void\nguestfs_%s_class_init(%sClass *klass)\n" name camel_name;
  pr "{\n";
  pr "  GObjectClass *object_class = G_OBJECT_CLASS(klass);\n";
  pr "  GParamSpec *pspec;\n\n";

  pr "  object_class->set_property = guestfs_%s_set_property;\n" name;
  pr "  object_class->get_property = guestfs_%s_get_property;\n\n" name;

  List.iter (
    fun optargt ->
      let optname = name_of_optargt optargt in
      let uc_optname = String.uppercase optname in
      pr "  pspec = ";
      (match optargt with
      | OBool n ->
        pr "g_param_spec_boolean(\"%s\", \"%s\", NULL, " optname optname;
        pr "GUESTFS_TYPE_TRISTATE, GUESTFS_TRISTATE_NONE, ";
      | OInt n ->
        pr "g_param_spec_int(\"%s\", \"%s\", NULL, " optname optname;
        pr "G_MININT32, G_MAXINT32, -1, ";
      | OInt64 n ->
        pr "g_param_spec_int64(\"%s\", \"%s\", NULL, " optname optname;
        pr "G_MININT32, G_MAXINT32, -1, ";
      | OString n ->
        pr "g_param_spec_string(\"%s\", \"%s\", NULL, " optname optname;
        pr "NULL, ");
      pr "G_PARAM_CONSTRUCT | G_PARAM_READWRITE | G_PARAM_STATIC_STRINGS);\n";
      pr "  g_object_class_install_property(object_class, ";
      pr "PROP_GUESTFS_%s_%s, pspec);\n\n" uc_name uc_optname;
  ) optargs;

  pr "  object_class->finalize = guestfs_%s_finalize;\n" name;
  pr "  g_type_class_add_private(klass, sizeof %sPrivate);\n" camel_name;
  pr "}\n\n";

  pr "static void\nguestfs_%s_init(%s *o)\n" name camel_name;
  pr "{\n";
  pr "  o->priv = GUESTFS_%s_GET_PRIVATE(o);\n" uc_name;
  pr "  /* XXX: Find out if gobject already zeroes private structs */\n";
  pr "  memset(o->priv, 0, sizeof %sPrivate);\n" camel_name;
  pr "}\n\n";

  pr "/**\n";
  pr " * guestfs_%s_new:\n" name;
  pr " *\n";
  pr " * Create a new %s object\n" camel_name;
  pr " *\n";
  pr " * Returns: (transfer full): a new %s object\n" camel_name;
  pr " */\n";
  pr "%s *\n" camel_name;
  pr "guestfs_%s_new(void)\n" name;
  pr "{\n";
  pr "  return GUESTFS_%s(g_object_new(%s, NULL));\n" uc_name type_define;
  pr "}\n\n";

and generate_gobject_c_optargs () =
  pr "/* Optarg objects */\n\n";

  iter_optargs (
    fun name optargs flags ->
      generate_gobject_c_optarg name optargs flags
  ) all_functions;

and generate_gobject_c_methods () =
  pr "/* Generated methods */\n\n";

  List.iter (
    fun (name, (ret, args, optargs as style), _, flags, _, shortdesc, longdesc) ->
      let doc = pod2text ~width:60 name longdesc in
      let doc = String.concat "\n * " doc in
      let camel_name = camel_of_name flags name in
      let is_RBufferOut = match ret with RBufferOut _ -> true | _ -> false in

      pr "/**\n";
      pr " * %s\n" shortdesc;
      pr " *\n";
      pr " * %s\n" doc;

      List.iter (
        fun argt ->
          pr " * @%s:" (name_of_argt argt);
          (match argt with
          | Bool _ | Int _ | Int64 _ -> ()
          | String _ | Key _ ->
            pr " (transfer none) (type utf8):"
          | OptString _ ->
            pr " (transfer none) (type utf8) (allow-none):"
          | Device _ | Pathname _ | Dev_or_Path _ | FileIn _ | FileOut _ ->
            pr " (transfer none) (type filename):"
          | StringList _ ->
            pr " (transfer none) (array zero-terminated=1) (element-type utf8): an array of strings"
          | DeviceList _ ->
            pr " (transfer none) (array zero-terminated=1) (element-type filename): an array of strings"
          | BufferIn n ->
            pr " (transfer none) (array length=%s_size) (element-type guint8): an array of binary data" n
          | Pointer _ ->
            failwith "gobject bindings do not support Pointer arguments"
          );
          pr "\n";
      ) args;
      if optargs <> [] then
        pr " * @optargs: (transfer none) (allow-none): a %s containing optional arguments\n" camel_name;
      pr " *\n";

      pr " * Returns: ";
      (match ret with
      | RErr ->
        pr "true on success, false on error"
      | RInt _ | RInt64 _ | RBool _ ->
        pr "the returned value, or -1 on error"
      | RConstString _ ->
        pr "(transfer none): the returned string, or NULL on error"
      | RConstOptString _ ->
        pr "(transfer none): the returned string. Note that NULL does not indicate error"
      | RString _ ->
        pr "(transfer full): the returned string, or NULL on error"
      | RStringList _ ->
        pr "(transfer full) (array zero-terminated=1) (element-type utf8): an array of returned strings, or NULL on error"
      | RHashtable _ ->
        pr "(transfer full) (element-type utf8 utf8): a GHashTable of results, or NULL on error"
      | RBufferOut _ ->
        pr "(transfer full) (array length=size_r) (element-type guint8): an array of binary data, or NULL on error"
      | RStruct (_, typ) ->
         let name = camel_name_of_struct typ in
         pr "(transfer full): a %s object, or NULL on error" name
      | RStructList (_, typ) ->
         let name = camel_name_of_struct typ in
         pr "(transfer full) (array zero-terminated=1) (element-type %s): an array of %s objects, or NULL on error" name name
      );
      pr "\n";
      pr " */\n";

      generate_gobject_proto name style flags;
      pr "{\n";
      pr "  guestfs_h *g = session->priv->g;\n";

      let gen_copy_struct indent src dst typ =
        pr "%s%s *%s = g_slice_new(%s);\n" indent camel_name dst camel_name;
        List.iter (
          function
          | n, (FChar|FUInt32|FInt32|FUInt64|FBytes|FInt64
                |FUUID|FOptPercent) ->
            pr "%s%s->%s = %s->%s;\n" indent dst n src n 
          | n, FString ->
            pr "%s%s->%s = g_strdup(%s->%s);\n" indent dst n src n
          | n, FBuffer ->
            pr "%s%s->%s = %s->%s\n;" indent dst n src n;
            pr "%s%s->%s_size = %s->%s_size\n;" indent dst n src n
        ) (cols_of_struct typ);
        pr "  guestfs_free_%s(ret);\n" typ in

      pr "  ";
      (match ret with
      | RErr | RInt _ | RBool _ ->
        pr "int "
      | RInt64 _ ->
        pr "int64_t "
      | RConstString _ | RConstOptString _ ->
        pr "const char *"
      | RString _ | RBufferOut _ ->
        pr "char *"
      | RStringList _ | RHashtable _ ->
        pr "char **"
      | RStruct (_, typ) ->
        pr "struct guestfs_%s *" typ
      | RStructList (_, typ) ->
        pr "struct guestfs_%s_list *" typ
      );
      pr "ret = guestfs_%s(g" name;
      List.iter (
        fun argt ->
          pr ", ";
          match argt with
          | BufferIn n ->
            pr "%s, %s_size" n n
          | Bool n | Int n | Int64 n | String n | Device n | Pathname n
          | Dev_or_Path n | OptString n | StringList n | DeviceList n
          | Key n | FileIn n | FileOut n ->
            pr "%s" n
          | Pointer _ ->
            failwith "gobject bindings do not support Pointer arguments"
      ) args;
      if is_RBufferOut then pr ", size_r";
      pr ");\n";

      if returns_error ret then (
        pr "  if (ret == %s) {\n"
          (match ret with
          | RErr | RInt _ | RInt64 _ | RBool _ ->
            "-1"
          | RConstString _ | RString _ | RStringList _ | RHashtable _
          | RBufferOut _ | RStruct _ | RStructList _ ->
            "NULL"
          | RConstOptString _ ->
            assert false;
          );
        pr "    g_set_error_literal(err, GUESTFS_ERROR, 0, guestfs_last_error(g));\n";
        pr "    return %s;\n"
          (match ret with
          | RErr ->
            "FALSE"
          | RInt _ | RInt64 _ | RBool _ ->
            "-1"
          | RConstString _ | RString _ | RStringList _ | RHashtable _
          | RBufferOut _ | RStruct _ | RStructList _ ->
            "NULL"
          | RConstOptString _ ->
            assert false;
          );
        pr "  }\n";
      );
      pr "\n";

      (match ret with
      | RErr ->
        pr "  return TRUE;\n"

      | RInt _ | RInt64 _ | RBool _
      | RConstString _ | RConstOptString _
      | RString _ | RStringList _
      | RBufferOut _ ->
        pr "  return ret;\n"

      | RHashtable _ ->
        pr "  GHashTable *h = g_hash_table_new_full(g_str_equal, g_str_equal, g_free, g_free);\n";
        pr "  char **i = ret;\n";
        pr "  while (*i) {\n";
        pr "    char *key = *i; i++;\n";
        pr "    char *value = *i; i++;\n";
        pr "    g_hash_table_insert(h, key, value);\n";
        pr "  }\n;";
        pr "  free (ret);\n";
        pr "  return h;\n"

      | RStruct (_, typ) ->
        gen_copy_struct "  " "ret" "s" typ;
        pr "  return s;\n";

      | RStructList (_, typ) ->
        pr "  %s **l = g_malloc(sizeof %s* * (ret->len + 1));\n" camel_name camel_name;
        pr "  gsize_t i;\n";
        pr "  for(i = 0; i < ret->len; i++) {\n";
        gen_copy_struct "    " "ret->val[i]" "s" typ;
        pr "    l[i] = s;\n";
        pr "  }\n";
        pr "  l[i] = NULL;\n";
        pr "  return l;\n";
      );

      pr "}\n\n";
  ) all_functions;

and generate_gobject_header () =
  generate_header CStyle GPLv2plus;
  generate_gobject_header_static ();
  generate_gobject_header_structs ();
  generate_gobject_header_optargs ();
  generate_gobject_header_methods ();

and generate_gobject_c () =
  generate_header CStyle GPLv2plus;
  generate_gobject_c_static ();
  generate_gobject_c_structs ();
  generate_gobject_c_optargs ();
  generate_gobject_c_methods ();
