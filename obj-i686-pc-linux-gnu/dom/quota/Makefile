# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/quota
VPATH            = /home/txema/work/firefox-20.0+build1/dom/quota

include $(DEPTH)/config/autoconf.mk

MODULE           = dom
LIBRARY_NAME     = domquota_s
XPIDL_MODULE     = dom_quota
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1

include $(topsrcdir)/dom/dom-config.mk

EXPORTS_NAMESPACES = mozilla/dom/quota

CPPSRCS = \
  CheckQuotaHelper.cpp \
  FileStreams.cpp \
  QuotaManager.cpp \
  $(NULL)

EXPORTS_mozilla/dom/quota = \
  FileStreams.h \
  QuotaCommon.h \
  QuotaManager.h \
  $(NULL)

include $(topsrcdir)/config/rules.mk
