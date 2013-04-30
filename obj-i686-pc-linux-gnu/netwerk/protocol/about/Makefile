#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/netwerk/protocol/about
VPATH     = /home/txema/work/firefox-20.0+build1/netwerk/protocol/about
FAIL_ON_WARNINGS := 1

include $(DEPTH)/config/autoconf.mk

MODULE         = necko
LIBRARY_NAME   = nkabout_s
LIBXUL_LIBRARY = 1
XPIDL_MODULE   = necko_about
GRE_MODULE     = 1

FORCE_STATIC_LIB = 1

EXPORTS = nsAboutProtocolUtils.h

XPIDLSRCS = nsIAboutModule.idl

CPPSRCS = \
  nsAboutProtocolHandler.cpp \
  nsAboutBlank.cpp \
  nsAboutBloat.cpp \
  nsAboutCache.cpp \
  nsAboutCacheEntry.cpp \
  $(NULL)

LOCAL_INCLUDES = \
  -I$(srcdir)/../../base/src \
  $(NULL)

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk

DEFINES += -DIMPL_NS_NET
