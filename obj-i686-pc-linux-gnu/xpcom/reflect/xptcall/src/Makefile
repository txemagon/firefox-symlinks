#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/xpcom/reflect/xptcall/src
VPATH		= /home/txema/work/firefox-20.0+build1/xpcom/reflect/xptcall/src

include $(DEPTH)/config/autoconf.mk

MODULE		= xpcom
LIBRARY_NAME	= xptcall
MOZILLA_INTERNAL_API = 1

DIRS		= md


CPPSRCS		= xptcall.cpp

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1


include $(topsrcdir)/config/rules.mk

DEFINES		+= -DEXPORT_XPTC_API -D_IMPL_NS_COM

LOCAL_INCLUDES += -I$(srcdir)/../../xptinfo/src
