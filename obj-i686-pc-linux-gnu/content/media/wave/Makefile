# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/media/wave
VPATH		= /home/txema/work/firefox-20.0+build1/content/media/wave
FAIL_ON_WARNINGS := 1

include $(DEPTH)/config/autoconf.mk

MODULE		= content
LIBRARY_NAME	= gkconwave_s
LIBXUL_LIBRARY 	= 1


EXPORTS		+= \
		WaveDecoder.h \
		WaveReader.h \
		$(NULL)

CPPSRCS		= \
		WaveDecoder.cpp \
		WaveReader.cpp \
		$(NULL)

FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk
