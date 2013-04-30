# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/toolkit/crashreporter/google-breakpad/src/client
VPATH		= /home/txema/work/firefox-20.0+build1/toolkit/crashreporter/google-breakpad/src/client

include $(DEPTH)/config/autoconf.mk

MODULE		= minidump_file_writer
LIBRARY_NAME	= minidump_file_writer_s
XPI_NAME 	= crashreporter

LOCAL_INCLUDES 	= -I$(srcdir)/..

CPPSRCS	= \
  minidump_file_writer.cc \
  $(NULL)

# need static lib
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk
