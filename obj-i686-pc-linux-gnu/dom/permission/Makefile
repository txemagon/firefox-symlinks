# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this file,
# You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/dom/permission
VPATH = /home/txema/work/firefox-20.0+build1/dom/permission

include $(DEPTH)/config/autoconf.mk

MODULE         = dom
LIBRARY_NAME   = jsdompermissionsettings_s

XPIDL_MODULE   = dom_permissionsettings
GRE_MODULE     = 1

EXTRA_COMPONENTS =        \
  PermissionSettings.js       \
  PermissionSettings.manifest \
  PermissionPromptService.js \
  PermissionPromptService.manifest \
  $(NULL)

EXTRA_JS_MODULES =   \
  PermissionPromptHelper.jsm \
  PermissionSettings.jsm \
  $(NULL)

TEST_DIRS += tests

include $(topsrcdir)/config/config.mk
include $(topsrcdir)/ipc/chromium/chromium-config.mk
include $(topsrcdir)/config/rules.mk

DEFINES += -D_IMPL_NS_LAYOUT
