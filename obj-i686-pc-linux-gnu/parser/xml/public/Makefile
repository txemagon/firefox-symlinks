# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/parser/xml/public
VPATH		= /home/txema/work/firefox-20.0+build1/parser/xml/public

include $(DEPTH)/config/autoconf.mk

MODULE = xml
XPIDL_MODULE = saxparser

XPIDLSRCS	= \
                nsISAXAttributes.idl \
                nsISAXMutableAttributes.idl \
                nsISAXContentHandler.idl \
                nsISAXDTDHandler.idl \
                nsISAXErrorHandler.idl \
                nsISAXLexicalHandler.idl \
                nsISAXLocator.idl \
                nsISAXXMLReader.idl \
                nsISAXXMLFilter.idl \
                nsIMozSAXXMLDeclarationHandler.idl \
		$(NULL)

include $(topsrcdir)/config/rules.mk
