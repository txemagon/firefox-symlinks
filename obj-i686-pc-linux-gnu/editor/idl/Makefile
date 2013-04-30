#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           := ../..
topsrcdir       := /home/txema/work/firefox-20.0+build1
srcdir          := /home/txema/work/firefox-20.0+build1/editor/idl
VPATH           := /home/txema/work/firefox-20.0+build1/editor/idl

include $(DEPTH)/config/autoconf.mk

MODULE          := editor
GRE_MODULE      := 1

XPIDLSRCS       := \
                nsIDocumentStateListener.idl \
                nsIEditActionListener.idl \
                nsIEditor.idl \
                nsIEditorIMESupport.idl \
                nsIEditorMailSupport.idl \
                nsIEditorObserver.idl \
                nsIEditorSpellCheck.idl \
                nsIEditorStyleSheets.idl \
                nsIHTMLEditor.idl \
                nsIHTMLObjectResizer.idl \
                nsIHTMLAbsPosEditor.idl \
                nsIHTMLObjectResizeListener.idl \
                nsIHTMLInlineTableEditor.idl \
                nsIPlaintextEditor.idl \
                nsITableEditor.idl \
                nsIURIRefObject.idl \
                nsIContentFilter.idl \
                nsPIEditorTransaction.idl \
                $(NULL)

include $(topsrcdir)/config/rules.mk

