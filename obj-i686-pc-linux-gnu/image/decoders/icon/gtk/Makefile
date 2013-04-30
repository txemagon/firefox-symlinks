# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/image/decoders/icon/gtk
VPATH		= /home/txema/work/firefox-20.0+build1/image/decoders/icon/gtk

include $(DEPTH)/config/autoconf.mk

MODULE		= imgicon
LIBRARY_NAME	= imgicongtk_s
LIBXUL_LIBRARY  = 1
FAIL_ON_WARNINGS = 1

CPPSRCS		= nsIconChannel.cpp

ifdef MOZ_ENABLE_GNOMEUI
LOCAL_INCLUDES += $(MOZ_GNOMEUI_CFLAGS)
else
LOCAL_INCLUDES += $(MOZ_GTK2_CFLAGS)
endif

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

