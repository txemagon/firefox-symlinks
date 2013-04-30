# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          := ../../../..
topsrcdir      := /home/txema/work/firefox-20.0+build1
srcdir         := /home/txema/work/firefox-20.0+build1/xpfe/appshell/src/test
VPATH          := /home/txema/work/firefox-20.0+build1/xpfe/appshell/src/test
relativesrcdir := xpfe/appshell/src/test

include $(DEPTH)/config/autoconf.mk

ifdef MOZ_PER_WINDOW_PRIVATE_BROWSING
MOCHITEST_CHROME_FILES := \
  test_hiddenPrivateWindow.xul \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk
