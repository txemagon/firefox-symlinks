# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/reflect
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/reflect

include $(DEPTH)/config/autoconf.mk

MODULE = jsreflect
MODULE_NAME = jsreflect
GRE_MODULE = 1

EXTRA_JS_MODULES = \
    reflect.jsm \
    $(NULL)

LIBRARY_NAME = jsreflect
LIBXUL_LIBRARY = 1
EXPORT_LIBRARY = 1
IS_COMPONENT = 1

CPPSRCS = \
    reflect.cpp \
    $(NULL)

EXTRA_DSO_LDOPTS += \
    $(MOZ_COMPONENT_LIBS) \
    $(MOZ_JS_LIBS) \
    $(NULL)

#ifdef ENABLE_TESTS
#DIRS += tests
#endif

include $(topsrcdir)/config/rules.mk
