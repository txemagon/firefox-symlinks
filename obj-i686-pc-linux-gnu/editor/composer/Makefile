#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           := ../..
topsrcdir       := /home/txema/work/firefox-20.0+build1
srcdir          := /home/txema/work/firefox-20.0+build1/editor/composer
VPATH           := /home/txema/work/firefox-20.0+build1/editor/composer

include $(DEPTH)/config/autoconf.mk

PARALLEL_DIRS   := public src

TEST_DIRS       += test

# Enable Editor API Logging!
ENABLE_EDITOR_API_LOG=1

ifdef ENABLE_EDITOR_API_LOG
DEFINES += -DENABLE_EDITOR_API_LOG
endif

include $(topsrcdir)/config/rules.mk

