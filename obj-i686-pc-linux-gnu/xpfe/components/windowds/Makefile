#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/xpfe/components/windowds
VPATH		= /home/txema/work/firefox-20.0+build1/xpfe/components/windowds

include $(DEPTH)/config/autoconf.mk

MODULE           = appcomps
XPIDL_MODULE     = windowds
LIBRARY_NAME     = windowds
MODULE_NAME      = nsWindowDataSourceModule
LIBXUL_LIBRARY   = 1
IS_COMPONENT     = 1
EXPORT_LIBRARY   = 1


CPPSRCS = nsWindowDataSource.cpp

XPIDLSRCS = nsIWindowDataSource.idl

include $(topsrcdir)/config/rules.mk
