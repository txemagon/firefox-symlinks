#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/testing/mochitest/chrome
VPATH		= /home/txema/work/firefox-20.0+build1/testing/mochitest/chrome
relativesrcdir  = testing/mochitest/chrome

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

_STATIC_FILES = test_sample.xul \
		test_sanityChromeUtils.xul \
		test_sanityPluginUtils.html \
		test_sanityException.xul \
		test_sanityException2.xul \
		$(NULL)

libs:: $(_STATIC_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/$(relativesrcdir)
