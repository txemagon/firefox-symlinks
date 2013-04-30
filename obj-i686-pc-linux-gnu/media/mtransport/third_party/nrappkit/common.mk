# This file was generated by mozmake.py. Do not edit it directly.
ifndef COMMON_MK_INCLUDED
COMMON_MK_INCLUDED := 1

ifdef MOZ_DEBUG
CFLAGS += $(CPPFLAGS_Debug) $(CFLAGS_Debug)
CXXFLAGS += $(CPPFLAGS_Debug) $(CXXFLAGS_Debug)
DEFINES += $(DEFINES_Debug)
LOCAL_INCLUDES += $(INCLUDES_Debug)
else # non-MOZ_DEBUG
CFLAGS += $(CPPFLAGS_Release) $(CFLAGS_Release)
CXXFLAGS += $(CPPFLAGS_Release) $(CXXFLAGS_Release)
DEFINES += $(DEFINES_Release)
LOCAL_INCLUDES += $(INCLUDES_Release)
endif

ifeq (WINNT,$(OS_TARGET))
# These get set via VC project file settings for normal GYP builds.
DEFINES += -DUNICODE -D_UNICODE
LOCAL_INCLUDES += -I"$(MOZ_DIRECTX_SDK_PATH)/include"
endif

# Don't use STL wrappers when compiling Google code.
STL_FLAGS =

# Work around the fact that Google codebases don't compile cleanly
# with -pedantic.
OS_CFLAGS := $(filter-out -pedantic,$(OS_CFLAGS))
OS_CXXFLAGS := $(filter-out -pedantic,$(OS_CXXFLAGS))

# Skip Mozilla-specific include locations.
# Specific GYP files can add them back by adding
# $(DIST)/include to their includes.
INCLUDES = -I. $(LOCAL_INCLUDES)

# Ensure that subdirs for sources get created before compiling
ifdef OBJS
SUB_SRCDIRS := $(addsuffix .dirstamp,$(addprefix $(CURDIR)/,$(sort $(dir $(OBJS)))))
$(OBJS): $(SUB_SRCDIRS)
$(SUB_SRCDIRS):
	$(MKDIR) -p $(dir $@)
	touch $@
endif

# COPY_SRCS get copied to the current directory to be compiled

define COPY_SRC
$(notdir $(1)): $(1)
	$$(INSTALL) $$(IFLAGS1) "$$<" .

endef # COPY_SRC
ifdef COPY_SRCS
GARBAGE += $(notdir $(COPY_SRCS))
$(foreach s,$(COPY_SRCS), $(eval $(call COPY_SRC,$(s))))
endif

# Rules for regenerating Makefiles from GYP files.
Makefile: $(topsrcdir)/media/mtransport/third_party/nrappkit/nrappkit.gyp $(topsrcdir)/media/webrtc/trunk/tools/gyp/pylib/gyp/generator/mozmake.py
	$(PYTHON) $(topsrcdir)/media/webrtc/trunk/build/gyp_chromium --format=mozmake --include=/home/txema/work/firefox-20.0+build1/media/webrtc/webrtc_config.gypi --depth=$(topsrcdir)/media/webrtc/trunk --generator-output=$(DEPTH)/media/mtransport/third_party/nrappkit --toplevel-dir=$(topsrcdir) -G OBJDIR=$(DEPTH) -Dbuild_with_mozilla=1 -DFORCED_INCLUDE_FILE=/home/txema/work/firefox-20.0+build1/media/webrtc/webrtc_config.gypi -Dtarget_arch=ia32 $(topsrcdir)/media/mtransport/third_party/nrappkit/nrappkit.gyp

endif