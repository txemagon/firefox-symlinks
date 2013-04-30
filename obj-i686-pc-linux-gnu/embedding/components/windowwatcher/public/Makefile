# vim:set ts=8 sw=8 sts=8 noet:
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/embedding/components/windowwatcher/public
VPATH		= /home/txema/work/firefox-20.0+build1/embedding/components/windowwatcher/public

include $(DEPTH)/config/autoconf.mk

MODULE		= windowwatcher
XPIDL_MODULE	= windowwatcher
GRE_MODULE	= 1

SDK_XPIDLSRCS   = nsIWindowWatcher.idl \
		  nsIPromptService.idl \
		  $(NULL)

XPIDLSRCS	= nsIDialogParamBlock.idl \
                  nsIPromptService2.idl \
                  nsPIPromptService.idl \
                  nsPIWindowWatcher.idl \
                  nsIPromptFactory.idl \
                  $(NULL)

EXPORTS		= nsPromptUtils.h \
                  $(NULL)

include $(topsrcdir)/config/rules.mk

