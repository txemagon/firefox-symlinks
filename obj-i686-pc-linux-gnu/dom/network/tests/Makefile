# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/network/tests
VPATH            = /home/txema/work/firefox-20.0+build1/dom/network/tests

relativesrcdir   = dom/network/tests

include $(DEPTH)/config/autoconf.mk

DIRS = \
  $(NULL)

MOCHITEST_FILES = \
  test_network_basics.html \
  test_tcpsocket_default_permissions.html \
  test_tcpsocket_enabled_no_perm.html \
  test_tcpsocket_enabled_with_perm.html \
  $(NULL)

ifdef MOZ_B2G_RIL
MOCHITEST_FILES = \
  test_networkstats_basics.html \
  $(NULL)
endif

MODULE = test_dom_socket

XPCSHELL_TESTS = unit unit_ipc

ifdef MOZ_B2G_RIL
XPCSHELL_TESTS += unit_stats
endif

include $(topsrcdir)/config/rules.mk
