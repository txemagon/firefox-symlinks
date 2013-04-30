#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/testing/mochitest/MochiKit
VPATH		= /home/txema/work/firefox-20.0+build1/testing/mochitest/MochiKit
relativesrcdir  = testing/mochitest/MochiKit

include $(DEPTH)/config/autoconf.mk
include $(topsrcdir)/config/rules.mk

_JS_FILES =	Async.js \
		Base.js \
		Color.js \
		Controls.js \
		DateTime.js \
		DOM.js \
		DragAndDrop.js \
		Format.js \
		Iter.js \
		Logging.js \
		LoggingPane.js \
		MochiKit.js \
		MockDOM.js \
		New.js \
		__package__.js \
		Signal.js \
		Sortable.js \
		Style.js \
		Test.js \
		Visual.js \
		$(NULL)	

libs:: $(_JS_FILES)
	$(INSTALL) $(foreach f,$^,"$f") $(DEPTH)/_tests/$(relativesrcdir)
