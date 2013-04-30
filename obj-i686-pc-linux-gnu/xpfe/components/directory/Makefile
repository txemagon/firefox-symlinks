#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/xpfe/components/directory
VPATH		= /home/txema/work/firefox-20.0+build1/xpfe/components/directory

include $(DEPTH)/config/autoconf.mk

MODULE		= appcomps
XPIDL_MODULE	= directory
LIBRARY_NAME	= directory_s
LIBXUL_LIBRARY	= 1

XPIDLSRCS	= nsIHTTPIndex.idl

CPPSRCS		= nsDirectoryViewer.cpp

# we don't want the shared lib, but we want to force the creation of a
# static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

