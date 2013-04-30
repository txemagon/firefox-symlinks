#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtltest
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtltest
relativesrcdir  = toolkit/content/tests/chrome/rtltest

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

libs:: righttoleft.manifest dirtest.xul
	$(INSTALL) /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtltest/righttoleft.manifest $(DEPTH)/_tests/testing/mochitest/chrome/$(relativesrcdir)/
	$(INSTALL) /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtltest/dirtest.xul $(DEPTH)/_tests/testing/mochitest/chrome/$(relativesrcdir)/content/
