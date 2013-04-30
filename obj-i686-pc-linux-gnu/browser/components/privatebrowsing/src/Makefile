# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH   = ../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/browser/components/privatebrowsing/src
VPATH   = /home/txema/work/firefox-20.0+build1/browser/components/privatebrowsing/src

include $(DEPTH)/config/autoconf.mk

MODULE = privatebrowsing
LIBRARY_NAME = privatebrowsing_s

FORCE_STATIC_LIB = 1
USE_STATIC_LIBS = 1

ifdef MOZ_PER_WINDOW_PRIVATE_BROWSING

EXTRA_COMPONENTS = \
  nsPrivateBrowsingServiceObsolete.manifest \
  nsPrivateBrowsingServiceObsolete.js \
  $(NULL)

else

CPPSRCS = \
	nsPrivateBrowsingServiceWrapper.cpp \
	$(NULL)

LOCAL_INCLUDES = -I$(srcdir)/../../build

EXTRA_COMPONENTS = \
  nsPrivateBrowsingService.manifest \
  $(NULL)

EXTRA_PP_COMPONENTS = \
	nsPrivateBrowsingService.js \
	$(NULL)

endif

include $(topsrcdir)/config/rules.mk
