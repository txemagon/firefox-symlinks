# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/js/ductwork/debugger
VPATH = /home/txema/work/firefox-20.0+build1/js/ductwork/debugger
relativesrcdir = js/ductwork/debugger

include $(DEPTH)/config/autoconf.mk

MODULE = jsdebugger
MODULE_NAME = jsdebugger
GRE_MODULE = 1

LIBRARY_NAME = jsdebugger
XPIDL_MODULE = jsdebugger
LIBXUL_LIBRARY = 1
EXPORT_LIBRARY = 1
IS_COMPONENT = 1

CPPSRCS = \
  JSDebugger.cpp \
  $(NULL)

EXTRA_DSO_LDOPTS += \
  $(MOZ_COMPONENT_LIBS) \
  $(MOZ_JS_LIBS) \
  $(NULL)

EXTRA_JS_MODULES = \
  jsdebugger.jsm \
  $(NULL)

XPIDLSRCS = \
  IJSDebugger.idl \
  $(NULL)

XPCSHELL_TESTS = tests

include $(topsrcdir)/config/rules.mk
