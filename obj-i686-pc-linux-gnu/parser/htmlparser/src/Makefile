# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/parser/htmlparser/src
VPATH     = /home/txema/work/firefox-20.0+build1/parser/htmlparser/src

include $(DEPTH)/config/autoconf.mk

MODULE         = htmlparser
LIBRARY_NAME   = htmlpars
EXPORT_LIBRARY = 1
IS_COMPONENT   = 1
MODULE_NAME	   = nsParserModule
SHORT_LIBNAME  = gkparser
GRE_MODULE	= 1
LIBXUL_LIBRARY = 1


SHARED_LIBRARY_LIBS = \
		$(DEPTH)/parser/xml/src/$(LIB_PREFIX)saxp.$(LIB_SUFFIX) \
		$(NULL)

CPPSRCS = \
		nsScannerString.cpp \
		nsDTDUtils.cpp      \
		nsHTMLTokenizer.cpp \
		nsElementTable.cpp  \
		nsExpatDriver.cpp   \
		CNavDTD.cpp         \
		nsHTMLEntities.cpp  \
		nsHTMLTags.cpp      \
		nsHTMLTokens.cpp    \
		nsParser.cpp        \
		CParserContext.cpp  \
		nsParserService.cpp \
		nsParserModule.cpp  \
		nsParserNode.cpp    \
		nsScanner.cpp       \
		nsToken.cpp         \
		nsParserMsgUtils.cpp\
		$(NULL)

include $(topsrcdir)/config/rules.mk
