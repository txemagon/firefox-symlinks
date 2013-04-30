# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH        = ../../../..
topsrcdir    = /home/txema/work/firefox-20.0+build1
srcdir       = /home/txema/work/firefox-20.0+build1/extensions/pref/autoconfig/public
VPATH        = /home/txema/work/firefox-20.0+build1/extensions/pref/autoconfig/public

include $(DEPTH)/config/autoconf.mk

MODULE       = autoconfig

XPIDLSRCS    = \
               nsIAutoConfig.idl \
               nsIReadConfig.idl \
               $(NULL)

ifdef MOZ_LDAP_XPCOM
XPIDLSRCS += nsILDAPSyncQuery.idl
endif

include $(topsrcdir)/config/rules.mk

