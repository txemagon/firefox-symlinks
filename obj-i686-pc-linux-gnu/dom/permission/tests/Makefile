# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/permission/tests
VPATH            = /home/txema/work/firefox-20.0+build1/dom/permission/tests

relativesrcdir   = dom/permission/tests

include $(DEPTH)/config/autoconf.mk

DIRS = \
  $(NULL)

MODULE          = test_permission
XPCSHELL_TESTS  = unit

include $(topsrcdir)/config/rules.mk

_TEST_FILES = \
  test_permission_basics.html \
  $(NULL)

_CHROME_TEST_FILES = \
  $(NULL)

libs:: $(_TEST_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/testing/mochitest/tests/$(relativesrcdir)
