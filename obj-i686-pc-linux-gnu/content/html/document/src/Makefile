#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/html/document/src
VPATH		= /home/txema/work/firefox-20.0+build1/content/html/document/src

include $(DEPTH)/config/autoconf.mk

MODULE		= content
LIBRARY_NAME	= gkconhtmldoc_s
LIBXUL_LIBRARY	= 1
ifndef _MSC_VER
FAIL_ON_WARNINGS = 1
endif # !_MSC_VER

CPPSRCS		= \
		nsHTMLContentSink.cpp \
		nsHTMLDocument.cpp \
		ImageDocument.cpp \
		MediaDocument.cpp \
		PluginDocument.cpp \
		$(NULL)

ifdef MOZ_MEDIA
CPPSRCS += VideoDocument.cpp
endif

EXPORTS		= \
		nsIHTMLDocument.h \
		$(NULL)

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

LOCAL_INCLUDES += \
		-I$(srcdir)/../../../base/src \
		-I$(srcdir)/../../../events/src \
		-I$(srcdir)/../../content/src \
		-I$(topsrcdir)/layout/style \
		-I$(topsrcdir)/dom/base \
		-I$(topsrcdir)/caps/include \
		-I$(topsrcdir)/xpcom/ds \
		$(NULL)

DEFINES += -D_IMPL_NS_LAYOUT
