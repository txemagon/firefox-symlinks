# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/accessible/src/jsat
VPATH     = /home/txema/work/firefox-20.0+build1/accessible/src/jsat

include $(DEPTH)/config/autoconf.mk

INSTALL_TARGETS += ACCESSFU

ACCESSFU_FILES := \
  AccessFu.jsm \
  EventManager.jsm \
  jar.mn \
  Makefile.in \
  Presentation.jsm \
  TouchAdapter.jsm \
  TraversalRules.jsm \
  Utils.jsm \
  UtteranceGenerator.jsm \
  $(NULL)

ACCESSFU_DEST = $(FINAL_TARGET)/modules/accessibility

include $(topsrcdir)/config/rules.mk

