#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/netwerk/protocol/res
VPATH     = /home/txema/work/firefox-20.0+build1/netwerk/protocol/res

include $(DEPTH)/config/autoconf.mk

MODULE         = necko
LIBRARY_NAME   = nkres_s
LIBXUL_LIBRARY = 1
XPIDL_MODULE   = necko_res
GRE_MODULE     = 1
ifndef _MSC_VER
FAIL_ON_WARNINGS = 1
endif # !_MSC_VER

FORCE_STATIC_LIB = 1

XPIDLSRCS = \
  nsIResProtocolHandler.idl \
  $(NULL)

CPPSRCS = \
  nsResProtocolHandler.cpp \
  $(NULL)

LOCAL_INCLUDES = \
  -I$(topsrcdir)/netwerk/base/src \
  $(NULL)

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk

DEFINES += -DIMPL_NS_NET

XPIDL_FLAGS += -I$(topsrcdir)/netwerk/base/public
