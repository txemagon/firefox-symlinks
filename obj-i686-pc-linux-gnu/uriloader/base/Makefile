# vim:set noet:
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/uriloader/base
VPATH		= /home/txema/work/firefox-20.0+build1/uriloader/base

include $(DEPTH)/config/autoconf.mk

MODULE		= uriloader
LIBRARY_NAME	= uriloaderbase_s
GRE_MODULE	= 1
LIBXUL_LIBRARY  = 1


CPPSRCS = 							\
				nsURILoader.cpp 		\
				nsDocLoader.cpp			\
				$(NULL)

SDK_XPIDLSRCS = 						\
				nsIURIContentListener.idl 	\
				nsIWebProgress.idl 	\
				nsIWebProgressListener.idl 	\
				$(NULL)

XPIDLSRCS = 							\
				nsIContentHandler.idl 		\
				nsIURILoader.idl	 	\
				nsCURILoader.idl		\
				nsITransfer.idl \
				nsIDocumentLoader.idl		\
				nsIWebProgressListener2.idl \
				$(NULL)

EXPORTS = 							\
				nsURILoader.h	 		\
				nsDocLoader.h			\
				$(NULL)

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk

