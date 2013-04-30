# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/media/libogg/src
VPATH		= /home/txema/work/firefox-20.0+build1/media/libogg/src

include $(DEPTH)/config/autoconf.mk

MODULE		= ogg
LIBRARY_NAME	= ogg
FORCE_STATIC_LIB= 1
ifeq (WINNT,$(OS_TARGET))
VISIBILITY_FLAGS =
endif

CSRCS		= \
		ogg_bitwise.c \
		ogg_framing.c \
		$(NULL)

include $(topsrcdir)/config/rules.mk
