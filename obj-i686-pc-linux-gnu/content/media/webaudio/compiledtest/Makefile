# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          := ../../../..
topsrcdir      := /home/txema/work/firefox-20.0+build1
srcdir         := /home/txema/work/firefox-20.0+build1/content/media/webaudio/compiledtest
VPATH          := /home/txema/work/firefox-20.0+build1/content/media/webaudio/compiledtest
relativesrcdir := content/media/webaudio/compiledtest

include $(DEPTH)/config/autoconf.mk

ifndef _MSC_VER
FAIL_ON_WARNINGS = 1
endif # !_MSC_VER

LOCAL_INCLUDES := -I$(srcdir)/..

CPP_UNIT_TESTS := \
  TestAudioEventTimeline.cpp \
  $(NULL)

include $(topsrcdir)/config/rules.mk
