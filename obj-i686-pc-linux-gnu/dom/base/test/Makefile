# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/dom/base/test
VPATH = /home/txema/work/firefox-20.0+build1/dom/base/test
relativesrcdir = dom/base/test

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES = \
  test_constructor.html \
  test_constructor-assignment.html \
  test_document.all_unqualified.html \
  test_domrequest.html \
  test_e4x_for_each.html \
  test_gsp-standards.html \
  test_gsp-quirks.html \
  test_gsp-qualified.html \
  test_nondomexception.html \
  test_screen_orientation.html \
  test_window_constructor.html \
  test_window_enumeration.html \
  test_writable-replaceable.html \
  $(NULL)

MOCHITEST_CHROME_FILES = \
   test_bug715041.xul \
   test_bug715041_removal.xul \
   $(NULL)

include $(topsrcdir)/config/rules.mk

