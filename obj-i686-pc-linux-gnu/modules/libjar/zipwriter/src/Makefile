# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH                 = ../../../..
topsrcdir             = /home/txema/work/firefox-20.0+build1
srcdir                = /home/txema/work/firefox-20.0+build1/modules/libjar/zipwriter/src
VPATH                 = /home/txema/work/firefox-20.0+build1/modules/libjar/zipwriter/src

include $(DEPTH)/config/autoconf.mk

MODULE                = zipwriter
LIBRARY_NAME          = zipwriter
SHORT_LIBNAME         = zipwrite
MODULE_NAME           = ZipWriterModule
EXPORT_LIBRARY        = 1
LIBXUL_LIBRARY        = 1
IS_COMPONENT          = 1

CPPSRCS = \
  StreamFunctions.cpp \
  nsDeflateConverter.cpp \
  nsZipHeader.cpp \
  nsZipDataStream.cpp \
  nsZipWriter.cpp \
  ZipWriterModule.cpp \
  $(NULL)

include $(topsrcdir)/config/rules.mk
