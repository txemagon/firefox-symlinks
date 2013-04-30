# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/modules/test
VPATH		= /home/txema/work/firefox-20.0+build1/browser/modules/test
relativesrcdir  = browser/modules/test

DIRS = \
	chrome \
	$(NULL)

include $(DEPTH)/config/autoconf.mk

XPCSHELL_TESTS = unit

include $(topsrcdir)/config/rules.mk

_BROWSER_FILES = \
                 browser_NetworkPrioritizer.js \
                 browser_TelemetryTimestamps.js \
                 # bug 793906 - temporarily disabling desktop UI while working on b2g
                 # browser_SignInToWebsite.js \
                 $(NULL)

ifeq ($(MOZ_WIDGET_TOOLKIT),windows)
_BROWSER_FILES += \
                 browser_taskbar_preview.js \
                 $(NULL)
endif

libs::	$(_BROWSER_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/testing/mochitest/browser/$(relativesrcdir)
