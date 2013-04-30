#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           = ../../..
topsrcdir       = /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/dom/interfaces/sidebar
VPATH           = /home/txema/work/firefox-20.0+build1/dom/interfaces/sidebar

include $(DEPTH)/config/autoconf.mk

MODULE          = dom
XPIDL_MODULE    = dom_sidebar
GRE_MODULE      = 1

XPIDLSRCS =                                     \
        nsISidebar.idl  \
        nsIWebContentHandlerRegistrar.idl \
        $(NULL)

include $(topsrcdir)/config/rules.mk
