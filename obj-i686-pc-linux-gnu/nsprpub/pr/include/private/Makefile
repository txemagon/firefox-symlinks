# Generated automatically from Makefile.in by configure.
# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


#! gmake

MOD_DEPTH	= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1/nsprpub
srcdir		= /home/txema/work/firefox-20.0+build1/nsprpub/pr/include/private
VPATH		= /home/txema/work/firefox-20.0+build1/nsprpub/pr/include/private

include $(MOD_DEPTH)/config/autoconf.mk

include $(topsrcdir)/config/config.mk

RELEASE_HEADERS = pprio.h pprthred.h prpriv.h
RELEASE_HEADERS := $(addprefix $(srcdir)/, $(RELEASE_HEADERS))
RELEASE_HEADERS_DEST = $(RELEASE_INCLUDE_DIR)/private

HEADERS = $(RELEASE_HEADERS) $(srcdir)/pprmwait.h $(srcdir)/primpl.h

include_subdir = private

include $(topsrcdir)/config/rules.mk

export:: $(RELEASE_HEADERS)
	$(INSTALL) -m 444 $(RELEASE_HEADERS) $(dist_includedir)/private
