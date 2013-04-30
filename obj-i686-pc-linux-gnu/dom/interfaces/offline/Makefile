#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/dom/interfaces/offline
VPATH          = /home/txema/work/firefox-20.0+build1/dom/interfaces/offline

include $(DEPTH)/config/autoconf.mk

MODULE         = dom
XPIDL_MODULE   = dom_offline
GRE_MODULE     = 1

XPIDLSRCS =                           \
        nsIDOMOfflineResourceList.idl \
        nsIDOMLoadStatus.idl          \
        $(NULL)

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/base \
  $(NULL)
