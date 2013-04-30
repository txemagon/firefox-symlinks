# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/profile/dirserviceprovider/src
VPATH		= /home/txema/work/firefox-20.0+build1/profile/dirserviceprovider/src

include $(DEPTH)/config/autoconf.mk
include $(srcdir)/objs.mk

MODULE		= profdirserviceprovider
LIBRARY_NAME	= profdirserviceprovider_s
MOZILLA_INTERNAL_API = 1


CPPSRCS		= $(MODULES_PROFILEDIRSERVICE_SRC_LCSRCS)

# we don't want the shared lib
FORCE_STATIC_LIB = 1

include $(topsrcdir)/config/rules.mk
