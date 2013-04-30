#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/xml/document/src
VPATH		= /home/txema/work/firefox-20.0+build1/content/xml/document/src

include $(DEPTH)/config/autoconf.mk

MODULE		= content
LIBRARY_NAME	= gkconxmldoc_s
LIBXUL_LIBRARY	= 1
FAIL_ON_WARNINGS = 1

CPPSRCS		= \
		nsXMLContentSink.cpp \
		nsXMLFragmentContentSink.cpp \
		nsXMLDocument.cpp \
		nsXMLPrettyPrinter.cpp \
		$(NULL)

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

LOCAL_INCLUDES	= \
		-I$(srcdir) \
		-I$(srcdir)/../../../html/document/src \
		-I$(srcdir)/../../../../layout/style \
		-I$(srcdir)/../../../base/src \
		-I$(srcdir)/../../../xul/content/src \
		-I$(srcdir)/../../../events/src \
		-I$(srcdir)/../../../../dom/base \
		-I$(srcdir)/../../../../caps/include \
		-I$(topsrcdir)/xpcom/ds \
		$(NULL)

DEFINES += -D_IMPL_NS_LAYOUT
