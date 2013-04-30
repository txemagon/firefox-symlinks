# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/dom/ipc/tests
VPATH		= /home/txema/work/firefox-20.0+build1/dom/ipc/tests
relativesrcdir  = dom/ipc/tests

include $(DEPTH)/config/autoconf.mk

MOCHITEST_CHROME_FILES = \
  test_process_error.xul \
  process_error.xul \
  process_error_contentscript.js \
  $(NULL)

include $(topsrcdir)/config/rules.mk
