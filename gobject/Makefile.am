BUILT_SOURCES = guestfs-gobject.h guestfs-gobject.c
EXTRA_DIST = $(BUILT_SOURCES)

libname = libguestfs-gobject-1.0.la

lib_LTLIBRARIES = $(libname)

libguestfs_gobject_1_0_ladir = $(includedir)

libguestfs_gobject_1_0_la_HEADERS = guestfs-gobject.h
libguestfs_gobject_1_0_la_SOURCES = guestfs-gobject.c
libguestfs_gobject_1_0_la_CFLAGS = -I$(top_srcdir)/src $(GOBJECT_CFLAGS)
libguestfs_gobject_1_0_la_LIBS = $(GOBJECT_LIBS)
libguestfs_gobject_1_0_la_LDFLAGS = $(LDFLAGS) -L$(top_builddir)/src
libguestfs_gobject_1_0_la_LIBADD = -lguestfs

-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir) --warn-all
INTROSPECTION_COMPILER_ARGS = --includedir=$(srcdir)

if HAVE_INTROSPECTION
introspection_sources = \
  $(libguestfs_gobject_1_0_la_HEADERS) \
  $(libguestfs_gobject_1_0_la_SOURCES)

Guestfs-1.0.gir: $(libname)
Guestfs_1_0_gir_INCLUDES = GObject-2.0 Gio-2.0
Guestfs_1_0_gir_CFLAGS = $(INCLUDES)
Guestfs_1_0_gir_LIBS = $(libname)
Guestfs_1_0_gir_FILES = $(introspection_sources)
INTROSPECTION_GIRS += Guestfs-1.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES = $(gir_DATA) $(typelib_DATA)
endif
