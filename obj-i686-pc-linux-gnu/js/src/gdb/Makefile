# -*- Mode: makefile -*-
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ..
topsrcdir	= /home/txema/work/firefox-20.0+build1/js/src
srcdir		= /home/txema/work/firefox-20.0+build1/js/src/gdb
VPATH		= /home/txema/work/firefox-20.0+build1/js/src/gdb /home/txema/work/firefox-20.0+build1/js/src/gdb/tests

include $(DEPTH)/config/autoconf.mk

PROGRAM = gdb-tests$(BIN_SUFFIX)
CPPSRCS =					\
  gdb-tests.cpp					\
  test-jsid.cpp					\
  test-JSString.cpp				\
  test-JSObject.cpp				\
  test-jsval.cpp				\
  test-prettyprinters.cpp			\
  test-Root.cpp					\
  typedef-printers.cpp				\
  $(NULL)

# Building against js_static requires that we declare mfbt sybols "exported"
# on its behalf.
DEFINES += -DEXPORT_JS_API -DIMPL_MFBT

LIBS = $(DEPTH)/$(LIB_PREFIX)js_static.$(LIB_SUFFIX) $(NSPR_LIBS) $(MOZ_ZLIB_LIBS)

LOCAL_INCLUDES += -I$(topsrcdir) -I..

# Place a GDB Python auto-load file next to the gdb-tests executable, both
# in the build directory and in the dist/bin directory.
PP_TARGETS += GDB_AUTOLOAD
GDB_AUTOLOAD := gdb-tests-gdb.py.in
GDB_AUTOLOAD_FLAGS := -Dtopsrcdir=$(abspath $(topsrcdir))

INSTALL_TARGETS += GDB_INSTALL_AUTOLOAD
GDB_INSTALL_AUTOLOAD_FILES := $(CURDIR)/gdb-tests-gdb.py
GDB_INSTALL_AUTOLOAD_DEST := $(DIST)/bin

include $(topsrcdir)/config/rules.mk
