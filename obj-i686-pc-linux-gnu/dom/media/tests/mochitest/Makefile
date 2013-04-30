# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir = /home/txema/work/firefox-20.0+build1/dom/media/tests/mochitest
VPATH = /home/txema/work/firefox-20.0+build1/dom/media/tests/mochitest
relativesrcdir = dom/media/tests/mochitest

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES = \
  test_getUserMedia_exceptions.html \
  test_getUserMedia_basicAudio.html \
  test_getUserMedia_basicVideo.html \
  test_getUserMedia_basicVideoAudio.html \
  head.js \
  mediaStreamPlayback.js \
  pc.js \
  $(NULL)

# The following tests are leaking and cannot be run by default yet
ifdef MOZ_WEBRTC_LEAKING_TESTS
MOCHITEST_FILES += \
  test_peerConnection_basicAudio.html \
  test_peerConnection_basicAudioVideo.html \
  test_peerConnection_basicAudioVideoCombined.html \
  test_peerConnection_basicVideo.html \
  $(NULL)
endif

include $(topsrcdir)/config/rules.mk
