DEPTH		= ../../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/browser/devtools/responsivedesign
VPATH		= /home/txema/work/firefox-20.0+build1/browser/devtools/responsivedesign

include $(DEPTH)/config/autoconf.mk

ifdef ENABLE_TESTS
	DIRS += test
endif

include $(topsrcdir)/config/rules.mk

libs::
	$(NSINSTALL) $(srcdir)/*.jsm $(FINAL_TARGET)/modules/devtools
