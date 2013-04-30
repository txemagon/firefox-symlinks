#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/intl/uconv/ucvtw
VPATH		= /home/txema/work/firefox-20.0+build1/intl/uconv/ucvtw

include $(DEPTH)/config/autoconf.mk

MODULE		= ucvtw
LIBRARY_NAME	= ucvtw_s
FORCE_STATIC_LIB=1
LIBXUL_LIBRARY = 1


CPPSRCS		= \
		nsBIG5ToUnicode.cpp \
		nsUnicodeToBIG5.cpp \
		nsBIG5HKSCSToUnicode.cpp \
		nsUnicodeToBIG5HKSCS.cpp \
		nsUnicodeToHKSCS.cpp \
		$(NULL)

EXPORTS		= nsUCvTWCID.h

LOCAL_INCLUDES = -I$(srcdir)/../util

include $(topsrcdir)/config/rules.mk
