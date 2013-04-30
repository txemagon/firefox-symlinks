#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/testing/mochitest/tests/SimpleTest
VPATH		= /home/txema/work/firefox-20.0+build1/testing/mochitest/tests/SimpleTest
relativesrcdir  = testing/mochitest/tests/SimpleTest
include $(DEPTH)/config/autoconf.mk

include $(topsrcdir)/config/rules.mk
_SIMPLETEST_FILES =	LogController.js \
			SimpleTest.js \
			test.css \
			TestRunner.js \
			setup.js \
			EventUtils.js \
			ChromeUtils.js \
			WindowSnapshot.js \
			MockObjects.js \
			NativeKeyCodes.js \
			paint_listener.js \
			$(DEPTH)/testing/specialpowers/content/MozillaLogger.js \
			$(DEPTH)/docshell/test/chrome/docshell_helpers.js \
			$(NULL)

libs:: $(_SIMPLETEST_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/$(relativesrcdir)

