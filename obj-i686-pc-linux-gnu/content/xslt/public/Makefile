# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/xslt/public
VPATH		= /home/txema/work/firefox-20.0+build1/content/xslt/public

include $(DEPTH)/config/autoconf.mk

MODULE       = content
XPIDL_MODULE = content_xslt

EXPORTS		= \
		nsIDocumentTransformer.h \
		$(NULL)

XPIDLSRCS	= \
		nsIXSLTException.idl  \
		nsIXSLTProcessor.idl  \
		nsIXSLTProcessorPrivate.idl  \
		txIFunctionEvaluationContext.idl  \
		txINodeSet.idl  \
		txIEXSLTRegExFunctions.idl  \
		txIXPathObject.idl  \
		$(NULL)

include $(topsrcdir)/config/rules.mk

