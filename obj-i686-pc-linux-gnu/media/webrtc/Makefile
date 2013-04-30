# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/media/webrtc
VPATH           = /home/txema/work/firefox-20.0+build1/media/webrtc

include $(DEPTH)/config/autoconf.mk

DIRS = \
  trunk \
  trunk/testing \
  signaling \
  signalingtest \
  $(NULL)

# These Makefiles don't have corresponding Makefile.ins
NO_SUBMAKEFILES_RULE = 1
include $(topsrcdir)/config/rules.mk
