# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/devtools
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit/devtools

include $(topsrcdir)/config/config.mk

PARALLEL_DIRS += \
  debugger \
  sourcemap \
  webconsole \
  $(NULL)

include $(topsrcdir)/config/rules.mk

libs::
	$(NSINSTALL) $(srcdir)/*.jsm $(FINAL_TARGET)/modules/devtools
