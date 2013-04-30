# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/privatebrowsing/test/browser
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/privatebrowsing/test/browser
relativesrcdir  = browser/components/privatebrowsing/test/browser

include $(DEPTH)/config/autoconf.mk

MODULE		= test_privatebrowsing

# We have three category of browser-chrome tests:
#  global: these tests focus on the global PB service implementation.
#  perwindow: these tests focus on the per-window PB implementation.
#  obsolete: these tests focus on the global mode, but the functionality
#            that they are testing is specific to the global mode, and
#            will never have a per-window counterpart.
#
# As a transition plan, we have divided the existing tests into the
# global and obsolete categories, and we'll then focus on rewriting the
# global tests to test the per-window mode.

ifdef MOZ_PER_WINDOW_PRIVATE_BROWSING
DIRS += perwindow
else
DIRS += global obsolete
endif

include $(topsrcdir)/config/rules.mk
