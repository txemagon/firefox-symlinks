#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/layout/xul/base/src/tree/public
VPATH		= /home/txema/work/firefox-20.0+build1/layout/xul/base/src/tree/public

include $(DEPTH)/config/autoconf.mk

MODULE		= layout
XPIDL_MODULE	= layout_xul_tree

XPIDLSRCS=	nsITreeColumns.idl \
		nsITreeView.idl \
                nsITreeSelection.idl \
                nsITreeBoxObject.idl \
                nsITreeContentView.idl \
                $(NULL)

EXPORTS		:= $(addprefix $(srcdir)/, $(EXPORTS))

include $(topsrcdir)/config/rules.mk

