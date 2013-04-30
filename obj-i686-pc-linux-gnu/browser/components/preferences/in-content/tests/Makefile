# -- This Source Code Form is subject to the terms of the Mozilla Public
#  - License, v. 2.0. If a copy of the MPL was not distributed with this file,
#  - You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/preferences/in-content/tests
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/preferences/in-content/tests
relativesrcdir  = browser/components/preferences/in-content/tests

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

_BROWSER_FILES = \
    head.js \
    browser_advanced_update.js \
    browser_bug410900.js \
    browser_bug731866.js \
    browser_connection.js \
    $(NULL)

ifndef MOZ_PER_WINDOW_PRIVATE_BROWSING
_BROWSER_FILES += \
    privacypane_tests.js \
    browser_bug567487.js \
    browser_privacypane_1.js \
    browser_privacypane_2.js \
    browser_privacypane_3.js \
    browser_privacypane_4.js \
    browser_privacypane_5.js \
    browser_privacypane_6.js \
    browser_privacypane_7.js \
    browser_privacypane_8.js \
    $(NULL)
else
_BROWSER_FILES += \
    privacypane_tests_perwindow.js \
    browser_privacypane_1.js \
    browser_privacypane_3.js \
    browser_privacypane_4.js \
    browser_privacypane_5.js \
    browser_privacypane_8.js \
    $(NULL)
endif

ifdef MOZ_SERVICES_HEALTHREPORT
_BROWSER_FILES += browser_healthreport.js
endif

libs::	$(_BROWSER_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/testing/mochitest/browser/$(relativesrcdir)
