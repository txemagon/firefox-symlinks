# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/content/media/raw
VPATH = /home/txema/work/firefox-20.0+build1/content/media/raw

include $(DEPTH)/config/autoconf.mk

MODULE = content
LIBRARY_NAME = gkconraw_s
LIBXUL_LIBRARY = 1
ifndef _MSC_VER
FAIL_ON_WARNINGS := 1
endif # !_MSC_VER

EXPORTS += \
  RawDecoder.h \
  RawReader.h \
  RawStructs.h \
  $(NULL)

CPPSRCS += \
  RawDecoder.cpp \
  RawReader.cpp \
  $(NULL)

FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

INCLUDES	+= \
		-I$(srcdir)/../../base/src \
		-I$(srcdir)/../../html/content/src \
		$(NULL)
