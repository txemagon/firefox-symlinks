# vim:set ts=8 sw=8 sts=8 noet:
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/extensions/gio
VPATH		= /home/txema/work/firefox-20.0+build1/extensions/gio

include $(DEPTH)/config/autoconf.mk

MODULE		= nkgio
LIBRARY_NAME	= nkgio
SHORT_LIBNAME	= nkgio
IS_COMPONENT	= 1
EXPORT_LIBRARY	= 1
MODULE_NAME	= nsGIOModule
LIBXUL_LIBRARY	= 1

CPPSRCS		= \
		nsGIOProtocolHandler.cpp \
		$(NULL)

LOCAL_INCLUDES	= $(MOZ_GIO_CFLAGS)

include $(topsrcdir)/config/rules.mk
