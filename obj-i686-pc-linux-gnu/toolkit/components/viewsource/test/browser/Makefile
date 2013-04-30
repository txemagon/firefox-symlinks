# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH     = ../../../../..
topsrcdir = /home/txema/work/firefox-20.0+build1
srcdir    = /home/txema/work/firefox-20.0+build1/toolkit/components/viewsource/test/browser
VPATH     = /home/txema/work/firefox-20.0+build1/toolkit/components/viewsource/test/browser
relativesrcdir  = toolkit/components/viewsource/test/browser

include $(DEPTH)/config/autoconf.mk

MOCHITEST_BROWSER_FILES   = \
                browser_bug699356.js \
                browser_bug713810.js \
                browser_contextmenu.js \
                browser_gotoline.js \
                browser_viewsourceprefs.js \
                browser_viewsourceprefs_nonhtml.js \
                head.js \
                $(NULL)

include $(topsrcdir)/config/rules.mk
