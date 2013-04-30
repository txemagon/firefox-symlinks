#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/mozapps/downloads
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit/mozapps/downloads

include $(topsrcdir)/config/config.mk

MODULE = helperAppDlg

EXTRA_COMPONENTS = nsHelperAppDlg.manifest
EXTRA_PP_COMPONENTS = nsHelperAppDlg.js

EXTRA_JS_MODULES = \
  DownloadLastDir.jsm \
  DownloadPaths.jsm \
  DownloadUtils.jsm \
  $(NULL)

ifeq ($(OS_ARCH),WINNT)
EXTRA_JS_MODULES += \
  DownloadTaskbarProgress.jsm \
  $(NULL)
endif

TEST_DIRS += tests

include $(topsrcdir)/config/rules.mk
