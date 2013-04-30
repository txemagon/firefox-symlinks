# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/image/encoders/png
VPATH		= /home/txema/work/firefox-20.0+build1/image/encoders/png

include $(DEPTH)/config/autoconf.mk

MODULE		= imgpnge
LIBRARY_NAME	= imgpnge_s
FORCE_STATIC_LIB = 1
MODULE_NAME	= imgEncoderPNGModule
LIBXUL_LIBRARY = 1
FAIL_ON_WARNINGS = 1

DEFINES		+= -DMOZ_PNG_WRITE \
	-DMOZ_PNG_READ \
	$(NULL)

LOCAL_INCLUDES += -I$(topsrcdir)/image/src/

CPPSRCS		= nsPNGEncoder.cpp

include $(topsrcdir)/config/rules.mk


