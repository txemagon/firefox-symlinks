# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/messages
VPATH            = /home/txema/work/firefox-20.0+build1/dom/messages

relativesrcdir   = dom/messages

include $(DEPTH)/config/autoconf.mk

PARALLEL_DIRS = interfaces

EXTRA_COMPONENTS = \
  SystemMessageManager.js \
  SystemMessageInternal.js \
  SystemMessageManager.manifest \
  $(NULL)

EXTRA_JS_MODULES += \
  SystemMessagePermissionsChecker.jsm \
  $(NULL)

include $(topsrcdir)/config/rules.mk
