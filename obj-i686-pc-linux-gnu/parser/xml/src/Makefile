# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/parser/xml/src
VPATH     = /home/txema/work/firefox-20.0+build1/parser/xml/src

include $(DEPTH)/config/autoconf.mk

MODULE		= xml
LIBRARY_NAME	= saxp

MOZILLA_INTERNAL_API = 1
LIBXUL_LIBRARY	= 1


CPPSRCS		= \
		nsSAXAttributes.cpp \
		nsSAXLocator.cpp \
		nsSAXXMLReader.cpp \
		$(NULL)

EXPORTS		= \
		nsSAXAttributes.h \
		nsSAXLocator.h \
		nsSAXXMLReader.h \
		$(NULL)

FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk
