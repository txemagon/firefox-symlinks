# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/toolkit/components/autocomplete
VPATH = /home/txema/work/firefox-20.0+build1/toolkit/components/autocomplete

include $(DEPTH)/config/autoconf.mk

MODULE = autocomplete
MODULE_NAME = tkAutoCompleteModule
LIBRARY_NAME = tkautocomplete
SHORT_LIBNAME = tkautoc
IS_COMPONENT = 1
EXPORT_LIBRARY = 1
LIBXUL_LIBRARY = 1

XPIDLSRCS = \
  nsIAutoCompleteController.idl \
  nsIAutoCompleteInput.idl \
  nsIAutoCompletePopup.idl \
  nsIAutoCompleteResult.idl \
  nsIAutoCompleteSearch.idl \
  nsIAutoCompleteSimpleResult.idl \
  $(NULL)

CPPSRCS = \
  nsAutoCompleteController.cpp \
  nsAutoCompleteSimpleResult.cpp \
  $(NULL)

TEST_DIRS += tests

include $(topsrcdir)/config/rules.mk
