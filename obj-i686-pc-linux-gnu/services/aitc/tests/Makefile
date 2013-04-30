# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/services/aitc/tests
VPATH     = /home/txema/work/firefox-20.0+build1/services/aitc/tests
relativesrcdir = services/aitc/tests

include $(DEPTH)/config/autoconf.mk

MODULE = test_services_aitc
XPCSHELL_TESTS = unit


MOCHITEST_BROWSER_FILES = \
  mochitest/head.js \
  mochitest/browser_id_simple.js \
  mochitest/file_browser_id_mock.html \
  $(NULL)

include $(topsrcdir)/config/rules.mk
