#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/intl/uconv/ucvibm
VPATH		= /home/txema/work/firefox-20.0+build1/intl/uconv/ucvibm

include $(DEPTH)/config/autoconf.mk

MODULE		= ucvibm
LIBRARY_NAME	= ucvibm_s
FORCE_STATIC_LIB = 1
LIBXUL_LIBRARY = 1


CPPSRCS		= \
		nsCP850ToUnicode.cpp \
		nsCP852ToUnicode.cpp \
		nsCP855ToUnicode.cpp \
		nsCP857ToUnicode.cpp \
		nsCP862ToUnicode.cpp \
		nsCP864ToUnicode.cpp \
		nsUnicodeToCP850.cpp \
		nsUnicodeToCP852.cpp \
		nsUnicodeToCP855.cpp \
		nsUnicodeToCP857.cpp \
		nsUnicodeToCP862.cpp \
		nsUnicodeToCP864.cpp \
		$(NULL)

ifeq ($(OS_ARCH),OS2)
CPPSRCS		+= \
		nsCP869ToUnicode.cpp \
		nsUnicodeToCP869.cpp \
		nsCP1125ToUnicode.cpp \
		nsUnicodeToCP1125.cpp \
		nsCP1131ToUnicode.cpp \
		nsUnicodeToCP1131.cpp \
		$(NULL)
endif

EXPORTS		= nsUCvIBMCID.h

LOCAL_INCLUDES = -I$(srcdir)/../util

include $(topsrcdir)/config/rules.mk
