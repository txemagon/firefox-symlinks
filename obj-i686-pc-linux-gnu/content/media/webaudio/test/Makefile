# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH          := ../../../..
topsrcdir      := /home/txema/work/firefox-20.0+build1
srcdir         := /home/txema/work/firefox-20.0+build1/content/media/webaudio/test
VPATH          := /home/txema/work/firefox-20.0+build1/content/media/webaudio/test
relativesrcdir := content/media/webaudio/test

include $(DEPTH)/config/autoconf.mk

MOCHITEST_FILES := \
  webaudio.js \
  test_bug808374.html \
  test_bug827541.html \
  test_AudioBuffer.html \
  test_AudioContext.html \
  test_AudioListener.html \
  test_badConnect.html \
  test_biquadFilterNode.html \
  test_delayNode.html \
  test_dynamicsCompressorNode.html \
  test_gainNode.html \
  test_pannerNode.html \
  test_singleSourceDest.html \
  $(NULL)

include $(topsrcdir)/config/rules.mk
