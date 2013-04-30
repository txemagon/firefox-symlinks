#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/netwerk/protocol
VPATH     = /home/txema/work/firefox-20.0+build1/netwerk/protocol

include $(DEPTH)/config/autoconf.mk

PARALLEL_DIRS = \
  about \
  app \
  data \
  device \
  file \
  ftp \
  http \
  res \
  viewsource \
  websocket \
  wyciwyg \
  $(NULL)

include $(topsrcdir)/config/rules.mk

DEFINES += -DIMPL_NS_NET
