#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/base/test/websocket_hybi
VPATH		= /home/txema/work/firefox-20.0+build1/content/base/test/websocket_hybi
relativesrcdir  = content/base/test/websocket_hybi

include $(DEPTH)/config/autoconf.mk

#### MODULE = content

MOCHITEST_FILES = \
    test_send-arraybuffer.html \
    test_send-blob.html \
    file_check-binary-messages_wsh.py \
    test_receive-arraybuffer.html \
    test_receive-blob.html \
    file_binary-frames_wsh.py \
    $(NULL)

include $(topsrcdir)/config/rules.mk
