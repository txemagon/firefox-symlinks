# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH            = ../../..
topsrcdir        = /home/txema/work/firefox-20.0+build1
srcdir           = /home/txema/work/firefox-20.0+build1/dom/interfaces/devicestorage
VPATH            = /home/txema/work/firefox-20.0+build1/dom/interfaces/devicestorage

include $(DEPTH)/config/autoconf.mk

MODULE           = dom
LIBRARY_NAME     = domdevicestorage_s
XPIDL_MODULE     = dom_devicestorage
LIBXUL_LIBRARY   = 1
FORCE_STATIC_LIB = 1

include $(topsrcdir)/dom/dom-config.mk

XPIDLSRCS = \
	nsIDOMDeviceStorage.idl \
	nsIDOMDeviceStorageStat.idl \
	nsIDOMDeviceStorageCursor.idl \
	nsIDOMNavigatorDeviceStorage.idl \
	nsIDOMDeviceStorageChangeEvent.idl

include $(topsrcdir)/config/rules.mk


XPIDL_FLAGS += \
  -I$(topsrcdir)/dom/interfaces/base \
  -I$(topsrcdir)/dom/interfaces/events \
  $(NULL)
