# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/settings/tests
VPATH            = /home/txema/work/firefox-20.0+build1/dom/settings/tests

relativesrcdir   = dom/settings/tests

include $(DEPTH)/config/autoconf.mk


MOCHITEST_FILES = \
  test_settings_basics.html \
  test_settings_events.html \
  test_settings_onsettingchange.html \
  $(NULL)

_CHROMEMOCHITEST_FILES = \
  $(NULL)

include $(topsrcdir)/config/rules.mk
