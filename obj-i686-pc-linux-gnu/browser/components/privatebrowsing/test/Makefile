# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/privatebrowsing/test
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/privatebrowsing/test
relativesrcdir  = browser/components/privatebrowsing/test

include $(DEPTH)/config/autoconf.mk

MODULE		= test_privatebrowsing

# Most xpcshell PB tests use the global PB service, which means that we should
# not attempt to run them in regular builds.  We should look at the list and
# decide which ones of them should be ported to the browser/perwindow suite
# in the future.

ifndef MOZ_PER_WINDOW_PRIVATE_BROWSING
XPCSHELL_TESTS	= unit
endif

DIRS +=	browser \
		$(NULL)

include $(topsrcdir)/config/rules.mk
