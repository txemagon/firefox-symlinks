# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH           = ../../../..
topsrcdir       = /home/txema/work/firefox-20.0+build1
srcdir          = /home/txema/work/firefox-20.0+build1/security/manager/boot/public
VPATH           = /home/txema/work/firefox-20.0+build1/security/manager/boot/public

include $(DEPTH)/config/autoconf.mk

MODULE = pipboot
GRE_MODULE	= 1

SDK_XPIDLSRCS = \
    nsISecurityWarningDialogs.idl \
    $(NULL)

XPIDLSRCS = \
    nsISSLStatusProvider.idl \
    nsIBufEntropyCollector.idl \
    nsISecurityUITelemetry.idl \
    $(NULL)

include $(topsrcdir)/config/rules.mk
