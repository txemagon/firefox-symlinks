#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/modules/libjar/test/chrome
VPATH		= /home/txema/work/firefox-20.0+build1/modules/libjar/test/chrome
relativesrcdir  = modules/libjar/test/chrome

include $(DEPTH)/config/autoconf.mk

MOCHITEST_CHROME_FILES = \
		test_bug386153.html    \
		signed.zip             \
		unsigned.zip           \
		signed-badca.zip       \
		signed-tampered.zip    \
		signed-added.zip       \
		$(NULL)

include $(topsrcdir)/config/rules.mk
