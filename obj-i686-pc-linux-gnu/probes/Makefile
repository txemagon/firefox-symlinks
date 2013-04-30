# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/probes
VPATH		= /home/txema/work/firefox-20.0+build1/probes

include $(DEPTH)/config/autoconf.mk

ifdef HAVE_DTRACE
export:: $(DIST)/include/mozilla-trace.h

# Replace _DTRACE_VERSION with INCLUDE_MOZILLA_DTRACE
$(DIST)/include/mozilla-trace.h: mozilla-trace.d Makefile
	dtrace -h -s $(srcdir)/mozilla-trace.d -o mozilla-trace.h.tmp
	sed -e 's/if _DTRACE_VERSION/ifdef INCLUDE_MOZILLA_DTRACE/' \
	    mozilla-trace.h.tmp > $(DIST)/include/mozilla-trace.h
	rm mozilla-trace.h.tmp
endif

include $(topsrcdir)/config/rules.mk
