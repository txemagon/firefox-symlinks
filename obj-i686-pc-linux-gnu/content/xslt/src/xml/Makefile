# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           = ../../../..
topsrcdir       = /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/content/xslt/src/xml
VPATH           = /home/txema/work/firefox-20.0+build1/content/xslt/src/xml

include $(DEPTH)/config/autoconf.mk

MODULE = transformiix
LIBRARY_NAME = txxml_s
LIBXUL_LIBRARY = 1

CPPSRCS	= \
	txXMLUtils.cpp \
	txXMLParser.cpp \
	$(NULL)

# we don't want the shared lib, but we want to force the creation of a
# static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

INCLUDES += \
	-I$(srcdir)/../base \
	-I$(srcdir) \
	-I$(srcdir)/../xpath \
	-I$(srcdir)/../xslt \
	-I$(srcdir)/../../../base/src \
	$(NULL)
