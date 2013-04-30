# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/components/commandlines
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit/components/commandlines

include $(DEPTH)/config/autoconf.mk

MODULE = toolkitcomps
XPIDL_MODULE = commandlines
LIBRARY_NAME = commandlines
SHORT_LIBNAME = cmdlines
EXPORT_LIBRARY = 1
IS_COMPONENT = 1
MODULE_NAME = CommandLineModule
LIBXUL_LIBRARY = 1

XPIDLSRCS = \
  nsICommandLine.idl \
  nsICommandLineHandler.idl \
  nsICommandLineRunner.idl \
  nsICommandLineValidator.idl \
  $(NULL)

CPPSRCS = \
  nsCommandLine.cpp \
  $(NULL)

TEST_DIRS += test

include $(topsrcdir)/config/rules.mk
