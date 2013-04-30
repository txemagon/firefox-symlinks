#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/xul/content/test
VPATH		= /home/txema/work/firefox-20.0+build1/content/xul/content/test
relativesrcdir  = content/xul/content/test

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES = 	\
		test_bug486990.xul \
		test_bug749367.xul \
		$(NULL)

MOCHITEST_CHROME_FILES = \
		test_bug233643.xul \
		test_bug398289.html \
		398289-resource.xul \
		test_bug775972.xul \
		$(NULL)

include $(topsrcdir)/config/rules.mk
