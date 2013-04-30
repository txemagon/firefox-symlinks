# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/dom/activities/interfaces
VPATH     = /home/txema/work/firefox-20.0+build1/dom/activities/interfaces

include $(DEPTH)/config/autoconf.mk

XPIDL_MODULE = dom_activities

XPIDLSRCS = nsIDOMActivity.idl \
            nsIDOMActivityOptions.idl \
            nsIDOMActivityHandlerDescription.idl \
            nsIDOMActivityRequestHandler.idl \
            nsIDOMNavigatorActivities.idl \
            nsIActivityProxy.idl \
            nsIActivityUIGlue.idl \
            $(NULL)

include $(topsrcdir)/config/rules.mk

XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/base \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/events \
  $(NULL)
