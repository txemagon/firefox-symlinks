# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/canvas/public
VPATH		= /home/txema/work/firefox-20.0+build1/content/canvas/public

include $(DEPTH)/config/autoconf.mk

MODULE		= content
XPIDL_MODULE = content_canvas

EXPORTS_NAMESPACES = mozilla/ipc

EXPORTS		= \
		nsICanvasRenderingContextInternal.h \
		nsICanvasElementExternal.h \
		$(NULL)

EXPORTS_mozilla/ipc = \
		DocumentRendererChild.h \
		DocumentRendererParent.h \
		DocumentRendererShmemChild.h \
		DocumentRendererShmemParent.h \
		DocumentRendererNativeIDChild.h \
		DocumentRendererNativeIDParent.h \
		$(NULL)

XPIDLSRCS	= \
		nsICanvasGLPrivate.idl \
		$(NULL)

include $(topsrcdir)/config/rules.mk
