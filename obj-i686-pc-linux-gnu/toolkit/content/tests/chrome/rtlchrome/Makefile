#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtlchrome
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtlchrome
relativesrcdir  = toolkit/content/tests/chrome/rtlchrome

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

libs:: rtl.manifest rtl.css rtl.dtd
	$(INSTALL) /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtlchrome/rtl.manifest $(DEPTH)/_tests/testing/mochitest/chrome/$(relativesrcdir)/
	$(INSTALL) /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtlchrome/rtl.css $(DEPTH)/_tests/testing/mochitest/chrome/$(relativesrcdir)/
	$(INSTALL) /home/txema/work/firefox-20.0+build1/toolkit/content/tests/chrome/rtlchrome/rtl.dtd $(DEPTH)/_tests/testing/mochitest/chrome/$(relativesrcdir)/
