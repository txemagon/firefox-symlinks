# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/components/migration/src
VPATH		= /home/txema/work/firefox-20.0+build1/browser/components/migration/src

include $(DEPTH)/config/autoconf.mk

MODULE		= migration
LIBRARY_NAME	= migration_s

FORCE_STATIC_LIB = 1
USE_STATIC_LIBS = 1

EXTRA_COMPONENTS = \
  ProfileMigrator.js \
  FirefoxProfileMigrator.js \
  $(NULL)

EXTRA_PP_COMPONENTS = \
  ChromeProfileMigrator.js \
  $(NULL)

ifeq ($(OS_ARCH),WINNT)
CPPSRCS += nsIEHistoryEnumerator.cpp

EXTRA_COMPONENTS += IEProfileMigrator.js \
                    $(NULL)

EXTRA_PP_COMPONENTS += SafariProfileMigrator.js \
                       $(NULL)

DEFINES += -DHAS_IE_MIGRATOR -DHAS_SAFARI_MIGRATOR
endif

ifeq (cocoa,$(MOZ_WIDGET_TOOLKIT))
EXTRA_PP_COMPONENTS += SafariProfileMigrator.js \
                       $(NULL)
DEFINES += -DHAS_SAFARI_MIGRATOR
endif

EXTRA_PP_COMPONENTS += \
	BrowserProfileMigrators.manifest \
	$(NULL)

EXTRA_PP_JS_MODULES = \
	MigrationUtils.jsm \
	$(NULL)

include $(topsrcdir)/config/rules.mk

