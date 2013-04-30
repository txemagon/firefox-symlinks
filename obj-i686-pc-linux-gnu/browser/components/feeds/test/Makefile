# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/feeds/test
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/feeds/test
relativesrcdir  = browser/components/feeds/test

include $(DEPTH)/config/autoconf.mk

MODULE		= test_browser_feeds
XPCSHELL_TESTS	= unit

DIRS = \
	chrome \
	$(NULL)

MOCHITEST_FILES =	bug408328-data.xml \
		bug368464-data.xml \
		test_bug494328.html \
		bug494328-data.xml \
		test_bug589543.html \
		bug589543-data.xml \
		test_registerHandler.html \
		valid-feed.xml \
		valid-unsniffable-feed.xml \
		$(NULL)

include $(topsrcdir)/config/rules.mk
