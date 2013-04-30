# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/ctypes
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/ctypes

include $(DEPTH)/config/autoconf.mk

MODULE = jsctypes
MODULE_NAME = jsctypes
GRE_MODULE = 1

EXTRA_JS_MODULES = \
    ctypes.jsm \
    $(NULL)

LIBRARY_NAME = jsctypes
LIBXUL_LIBRARY = 1
EXPORT_LIBRARY = 1
IS_COMPONENT = 1

CPPSRCS = \
    ctypes.cpp \
    $(NULL)

LOCAL_INCLUDES := \
  -I$(topsrcdir)/js/xpconnect/loader \
  $(NULL)

TEST_DIRS += tests

include $(topsrcdir)/config/rules.mk
