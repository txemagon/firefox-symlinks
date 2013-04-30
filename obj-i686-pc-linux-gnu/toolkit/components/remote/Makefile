# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/components/remote
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/components/remote

include $(DEPTH)/config/autoconf.mk

MODULE         = toolkitcomps
XPIDL_MODULE   = toolkitremote
LIBRARY_NAME	 = remoteservice
EXPORT_LIBRARY = 1
IS_COMPONENT   = 1
MODULE_NAME    = RemoteServiceModule

LIBXUL_LIBRARY = 1


XPIDLSRCS = nsIRemoteService.idl

CPPSRCS += nsXRemoteService.cpp
ifneq (,$(filter gtk2,$(MOZ_WIDGET_TOOLKIT)))
CPPSRCS += nsGTKRemoteService.cpp
endif

ifeq (qt,$(MOZ_WIDGET_TOOLKIT))
CPPSRCS += nsQtRemoteService.cpp
endif

include $(topsrcdir)/config/rules.mk

CXXFLAGS += $(TK_CFLAGS)

