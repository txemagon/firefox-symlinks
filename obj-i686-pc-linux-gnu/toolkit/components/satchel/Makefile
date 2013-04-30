# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/satchel
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/satchel

include $(DEPTH)/config/autoconf.mk

MODULE = satchel
LIBRARY_NAME = satchel
MODULE_NAME = satchel
IS_COMPONENT = 1
LIBXUL_LIBRARY = 1
EXPORT_LIBRARY = 1

XPIDLSRCS = \
  nsIFormAutoComplete.idl \
  nsIFormFillController.idl \
  nsIFormHistory.idl \
  nsIInputListAutoComplete.idl \
  $(NULL)

LOCAL_INCLUDES = \
  -I$(srcdir)/../build \
  $(NULL)

CPPSRCS = \
  nsFormFillController.cpp \
  $(NULL)

EXTRA_COMPONENTS = \
  nsFormAutoComplete.js \
  nsInputListAutoComplete.js \
  satchel.manifest \
  $(NULL)

EXTRA_PP_COMPONENTS = \
	nsFormHistory.js \
	$(NULL)

EXTRA_JS_MODULES = \
  nsFormAutoCompleteResult.jsm \
  $(NULL)

TEST_DIRS += test

include $(topsrcdir)/config/rules.mk
