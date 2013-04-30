# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit

include $(DEPTH)/config/autoconf.mk

PARALLEL_DIRS = \
  addon-sdk \
  components \
  content \
  devtools \
  forgetaboutsite \
  identity \
  locales \
  modules \
  mozapps/downloads \
  mozapps/extensions \
  mozapps/handling \
  mozapps/preferences \
  mozapps/plugins \
  mozapps/shared \
  obsolete \
  profile \
  themes \
  webapps \
  $(NULL)

DIRS += \
  mozapps/update \
  $(NULL)

ifdef MOZ_MAINTENANCE_SERVICE
DIRS += \
  components/maintenanceservice \
  $(NULL)
endif

ifneq (,$(filter gtk2 qt,$(MOZ_WIDGET_TOOLKIT)))
PARALLEL_DIRS += system/unixproxy
endif

ifneq (,$(filter cocoa,$(MOZ_WIDGET_TOOLKIT)))
PARALLEL_DIRS += system/osxproxy
endif

ifneq (,$(filter windows,$(MOZ_WIDGET_TOOLKIT)))
PARALLEL_DIRS += system/windowsproxy
endif

ifneq (,$(filter android,$(MOZ_WIDGET_TOOLKIT)))
PARALLEL_DIRS += system/androidproxy
endif

ifdef MOZ_CRASHREPORTER
PARALLEL_DIRS += crashreporter
endif

DIRS += \
  xre \
  $(NULL)

include $(topsrcdir)/config/rules.mk

export::
	@$(MAKE) -C xre export
