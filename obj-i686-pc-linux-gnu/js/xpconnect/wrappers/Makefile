# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH 		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/js/xpconnect/wrappers
VPATH		= /home/txema/work/firefox-20.0+build1/js/xpconnect/wrappers

include $(DEPTH)/config/autoconf.mk

MODULE		= xpcwrappers
LIBRARY_NAME	= xpcwrappers_s
FORCE_STATIC_LIB = 1
LIBXUL_LIBRARY = 1

CPPSRCS = \
  AccessCheck.cpp \
  WaiveXrayWrapper.cpp \
  FilteringWrapper.cpp \
  ChromeObjectWrapper.cpp \
  XrayWrapper.cpp \
  WrapperFactory.cpp \
  $(NULL)

LOCAL_INCLUDES = \
                -I$(srcdir)/../src \
                -I$(srcdir)/../../../dom/base \

include $(topsrcdir)/config/rules.mk
