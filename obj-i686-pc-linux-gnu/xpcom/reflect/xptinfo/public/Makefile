#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/xpcom/reflect/xptinfo/public
VPATH		= /home/txema/work/firefox-20.0+build1/xpcom/reflect/xptinfo/public

include $(DEPTH)/config/autoconf.mk

MODULE		= xpcom

XPIDL_MODULE = xpcom_xpti

GRE_MODULE	= 1

EXPORTS		= \
		xptinfo.h \
		$(NULL)

XPIDLSRCS = \
	nsIInterfaceInfo.idl          \
	nsIInterfaceInfoManager.idl   \
	$(NULL)

EXPORTS		:= $(addprefix $(srcdir)/, $(EXPORTS))

include $(topsrcdir)/config/rules.mk

CFLAGS		+= -DEXPORT_XPCI_API

