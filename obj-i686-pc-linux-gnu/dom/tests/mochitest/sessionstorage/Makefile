#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/dom/tests/mochitest/sessionstorage
VPATH		= /home/txema/work/firefox-20.0+build1/dom/tests/mochitest/sessionstorage
relativesrcdir	= dom/tests/mochitest/sessionstorage

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES	= \
    frameReplace.html \
    frameEqual.html \
    frameNotEqual.html \
    file_http.html \
    file_https.html \
    test_sessionStorageBase.html \
    test_sessionStorageClone.html \
    test_sessionStorageReplace.html \
    test_sessionStorageHttpHttps.html \
    interOriginSlave.js \
    interOriginTest.js \
    $(NULL)

MOCHITEST_CHROME_FILES = \
    test_sessionStorageFromChrome.xhtml \
    $(NULL)

include $(topsrcdir)/config/rules.mk
