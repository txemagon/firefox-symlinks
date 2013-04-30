# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/js/ipc
VPATH     = /home/txema/work/firefox-20.0+build1/js/ipc

include $(DEPTH)/config/autoconf.mk

MODULE = js
LIBRARY_NAME = jsipc_s
LIBXUL_LIBRARY = 1
FORCE_STATIC_LIB = 1
EXPORT_LIBRARY = 1

EXPORTS_NAMESPACES = mozilla/jsipc

EXPORTS_mozilla/jsipc = \
  CPOWTypes.h \
  ContextWrapperChild.h \
  ContextWrapperParent.h \
  ObjectWrapperParent.h \
  ObjectWrapperChild.h \
  $(NULL)

CPPSRCS = \
  ObjectWrapperParent.cpp \
  ObjectWrapperChild.cpp \
  $(NULL)

# For nsDependentJSString
LOCAL_INCLUDES += \
  -I$(topsrcdir)/dom/base \
  $(NULL)

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk

DEFINES += -DBIN_SUFFIX='"$(BIN_SUFFIX)"'
