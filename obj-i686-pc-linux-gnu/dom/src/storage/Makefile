#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          = ../../..
topsrcdir      = /home/txema/work/firefox-20.0+build1
srcdir         = /home/txema/work/firefox-20.0+build1/dom/src/storage
VPATH          = /home/txema/work/firefox-20.0+build1/dom/src/storage
FAIL_ON_WARNINGS := 1

include $(DEPTH)/config/autoconf.mk

MODULE         = dom
LIBRARY_NAME   = jsdomstorage_s
LIBXUL_LIBRARY = 1

CPPSRCS = \
       nsDOMStorage.cpp \
       nsDOMStorageBaseDB.cpp \
       nsDOMStorageDBWrapper.cpp \
       nsLocalStorageCache.cpp \
       nsDOMStoragePersistentDB.cpp \
       nsDOMStorageMemoryDB.cpp \
       StorageChild.cpp \
       StorageParent.cpp \
       $(NULL)

EXPORTS_NAMESPACES = mozilla/dom
EXPORTS_mozilla/dom = StorageChild.h StorageParent.h

# we don't want the shared lib, but we want to force the creation of a static lib.
FORCE_STATIC_LIB = 1

LOCAL_INCLUDES = \
                -I$(topsrcdir)/dom/base \
		-I$(topsrcdir)/content/events/src

DEFINES += -D_IMPL_NS_LAYOUT

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk
