#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/feeds/test/chrome
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/feeds/test/chrome
relativesrcdir  = browser/components/feeds/test/chrome

include $(DEPTH)/config/autoconf.mk

# sample_feed.atom was copied from toolkit/components/places/tests/chrome
MOCHITEST_FILES	= \
		sample_feed.atom \
		$(NULL)

MOCHITEST_CHROME_FILES	= \
		test_423060.xul \
		test_bug368464.html \
		test_bug408328.html \
		test_maxSniffing.html \
		$(NULL)

include $(topsrcdir)/config/rules.mk

