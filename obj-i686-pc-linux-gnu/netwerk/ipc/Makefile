# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/netwerk/ipc
VPATH = /home/txema/work/firefox-20.0+build1/netwerk/ipc
FAIL_ON_WARNINGS := 1

include $(DEPTH)/config/autoconf.mk

MODULE = necko

LIBRARY_NAME = neckoipc_s
LIBXUL_LIBRARY = 1
FORCE_STATIC_LIB = 1
EXPORT_LIBRARY = 1
XPIDL_MODULE   = necko_ipc

XPIDLSRCS = \
  nsIRemoteOpenFileListener.idl \
  $(NULL)

EXPORTS_NAMESPACES = mozilla/net

EXPORTS_mozilla/net = \
  NeckoParent.h       \
  NeckoChild.h        \
  NeckoCommon.h       \
  NeckoMessageUtils.h \
  ChannelEventQueue.h \
  RemoteOpenFileParent.h \
  RemoteOpenFileChild.h \
  $(NULL)

CPPSRCS =               \
  NeckoChild.cpp        \
  NeckoParent.cpp       \
  ChannelEventQueue.cpp \
  RemoteOpenFileParent.cpp \
  RemoteOpenFileChild.cpp  \
  $(NULL)

LOCAL_INCLUDES +=                  \
  -I$(srcdir)/../protocol/http \
  -I$(srcdir)/../base/src          \
  $(NULL)

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk
