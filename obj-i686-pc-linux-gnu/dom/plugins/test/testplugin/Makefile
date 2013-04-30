#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/dom/plugins/test/testplugin
VPATH     = /home/txema/work/firefox-20.0+build1/dom/plugins/test/testplugin

include $(DEPTH)/config/autoconf.mk

MODULE       = nptest
LIBRARY_NAME = nptest
MODULE_NAME  = TestPlugin
ifndef _MSC_VER
FAIL_ON_WARNINGS = 1
endif # !_MSC_VER

DIRS = secondplugin

RELATIVE_PATH=.
COCOA_NAME=Test
include /home/txema/work/firefox-20.0+build1/dom/plugins/test/testplugin/testplugin.mk
