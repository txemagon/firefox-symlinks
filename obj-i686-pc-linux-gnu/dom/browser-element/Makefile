# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/browser-element
VPATH            = /home/txema/work/firefox-20.0+build1/dom/browser-element

include $(DEPTH)/config/autoconf.mk

MODULE           = dom
LIBRARY_NAME     = dom_browserelement_s
XPIDL_MODULE     = dom_browserelement
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1
FAIL_ON_WARNINGS := 1

include $(topsrcdir)/dom/dom-config.mk

TEST_DIRS += mochitest

XPIDLSRCS = \
  nsIOpenWindowEventDetail.idl \
  nsIAsyncScrollEventDetail.idl \
  $(NULL)

EXPORTS = \
  nsOpenWindowEventDetail.h \
  nsAsyncScrollEventDetail.h \
  $(NULL)

EXPORTS_NAMESPACES = mozilla
EXPORTS_mozilla = \
  BrowserElementParent.h \
  $(NULL)

CPPSRCS = \
  nsOpenWindowEventDetail.cpp \
  nsAsyncScrollEventDetail.cpp \
  BrowserElementParent.cpp \
  $(NULL)

EXTRA_COMPONENTS = \
  BrowserElementParent.js \
  BrowserElementParent.manifest \
  $(NULL)

EXTRA_JS_MODULES = \
  BrowserElementPromptService.jsm \
  $(NULL)

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk

INCLUDES	+= \
		-I$(topsrcdir)/dom/base \
		-I$(topsrcdir)/dom/ipc \
		-I$(topsrcdir)/content/base/src \
		$(NULL)
