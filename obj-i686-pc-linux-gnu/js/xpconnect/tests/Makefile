#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/js/xpconnect/tests
VPATH = /home/txema/work/firefox-20.0+build1/js/xpconnect/tests
relativesrcdir = js/xpconnect/tests

include $(DEPTH)/config/autoconf.mk

DIRS = idl mochitest chrome browser components/native components/js

XPCSHELL_TESTS = unit

LIBS = \
  $(DIST)/lib/$(LIB_PREFIX)xpcomglue_s.$(LIB_SUFFIX) \
  $(LIBS_DIR) \
  $(MOZ_JS_LIBS) \
  $(MOZ_COMPONENT_LIBS) \
  $(NULL)

include $(topsrcdir)/config/rules.mk
