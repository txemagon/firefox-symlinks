#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/intl/uconv/tests
VPATH		= /home/txema/work/firefox-20.0+build1/intl/uconv/tests
relativesrcdir = intl/uconv/tests

include $(DEPTH)/config/autoconf.mk

MODULE          = test_intl_uconv
XPCSHELL_TESTS	= unit

# Tests disabled because they dont work in libxul builds.
#MOZILLA_INTERNAL_API = 1
#
#
#CPPSRCS		= \
#		TestUConv.cpp \
#		nsconv.cpp \
#		plattest.cpp \
#		$(NULL)
#
#ifeq ($(OS_ARCH),WINNT)
#CPPSRCS		+= convperf.cpp
#endif
#
#SIMPLE_PROGRAMS	= $(CPPSRCS:.cpp=$(BIN_SUFFIX))

relativesrcdir	= intl/uconv/tests

MOCHITEST_FILES =	\
		test_bug335816.html \
		test_long_doc.html \
		test_singlebyte_overconsumption.html \
		test_unicode_noncharacterescapes.html \
		test_unicode_noncharacters_gb18030.html \
		test_unicode_noncharacters_utf8.html \
		test_utf8_overconsumption.html \
		$(NULL)

include $(topsrcdir)/config/rules.mk
