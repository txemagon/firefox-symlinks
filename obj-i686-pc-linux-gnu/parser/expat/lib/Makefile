# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/parser/expat/lib
VPATH		= /home/txema/work/firefox-20.0+build1/parser/expat/lib

include $(DEPTH)/config/autoconf.mk

MODULE		= expat
LIBRARY_NAME	= mozexpat_s

CSRCS		= \
		xmlparse.c \
		xmlrole.c \
		xmltok.c \
		$(NULL)

EXPORTS		= \
		expat.h \
		expat_external.h

# We want only the static lib, not the shared lib
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

xmltok.$(OBJ_SUFFIX): moz_extensions.c

DEFINES += -DHAVE_EXPAT_CONFIG_H
