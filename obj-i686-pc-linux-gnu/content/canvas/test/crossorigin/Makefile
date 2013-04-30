#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/content/canvas/test/crossorigin
VPATH		= /home/txema/work/firefox-20.0+build1/content/canvas/test/crossorigin
relativesrcdir  = content/canvas/test/crossorigin

include $(DEPTH)/config/autoconf.mk
MOCHITEST_FILES = \
	image-allow-credentials.png \
	image-allow-credentials.png^headers^ \
	image-allow-star.png \
	image-allow-star.png^headers^ \
	image.png \
	test_canvas2d_crossorigin.html \
	test_webgl_crossorigin_textures.html \
	video.sjs \
	test_video_crossorigin.html \
	$(NULL)

include $(topsrcdir)/config/rules.mk
