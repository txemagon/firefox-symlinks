#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/browser/devtools/shared/test
VPATH     = /home/txema/work/firefox-20.0+build1/browser/devtools/shared/test
relativesrcdir  = browser/devtools/shared/test

include $(DEPTH)/config/autoconf.mk

XPCSHELL_TESTS = unit

MOCHITEST_BROWSER_FILES = \
  browser_browser_basic.js \
  browser_promise_basic.js \
  browser_require_basic.js \
  browser_templater_basic.js \
  browser_toolbar_basic.js \
  browser_toolbar_tooltip.js \
  browser_toolbar_webconsole_errors_count.js \
  browser_layoutHelpers.js \
  browser_eventemitter_basic.js \
  head.js \
  helpers.js \
  leakhunt.js \
  $(NULL)

MOCHITEST_BROWSER_FILES += \
  browser_templater_basic.html \
  browser_toolbar_basic.html \
  browser_toolbar_webconsole_errors_count.html \
  browser_layoutHelpers.html \
  browser_layoutHelpers_iframe.html \
  $(NULL)

include $(topsrcdir)/config/rules.mk
