# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/embedding/browser/build
VPATH		= /home/txema/work/firefox-20.0+build1/embedding/browser/build

include $(DEPTH)/config/autoconf.mk

MODULE		= webbrwsr
LIBRARY_NAME	= webbrwsr
IS_COMPONENT	= 1
MODULE_NAME	= Browser_Embedding_Module
EXPORT_LIBRARY	= 1
GRE_MODULE	= 1
LIBXUL_LIBRARY	= 1


CPPSRCS		= \
		nsWebBrowserModule.cpp		\
		$(NULL)

SHARED_LIBRARY_LIBS= \
		../webBrowser/$(LIB_PREFIX)nsWebBrowser_s.$(LIB_SUFFIX) \
		$(NULL)

include $(topsrcdir)/config/rules.mk

INCLUDES	+= \
		-I$(srcdir)			\
		-I$(srcdir)/../webBrowser		\
		-I$(srcdir)/../setup		\
		$(NULL)
