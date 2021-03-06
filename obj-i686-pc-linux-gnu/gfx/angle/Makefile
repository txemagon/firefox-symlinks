# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

DEPTH		= ../..
topsrcdir	= /home/txema/work/firefox-20.0+build1
srcdir		= /home/txema/work/firefox-20.0+build1/gfx/angle
VPATH		= /home/txema/work/firefox-20.0+build1/gfx/angle

include $(DEPTH)/config/autoconf.mk

MODULE		= angle
LIBRARY_NAME	= angle
LIBXUL_LIBRARY  = 1
ifeq (WINNT,$(OS_TARGET))
VISIBILITY_FLAGS =
endif

EXPORTS_NAMESPACES = angle

EXPORTS_angle = \
	include/GLSLANG/ShaderLang.h \
	$(NULL)

LOCAL_INCLUDES += -I$(srcdir)/include -I$(srcdir)/src

VPATH += $(srcdir)/src
VPATH += $(srcdir)/src/compiler
VPATH += $(srcdir)/src/compiler/preprocessor
VPATH += $(srcdir)/src/compiler/preprocessor/new
VPATH += $(srcdir)/src/compiler/timing
VPATH += $(srcdir)/src/compiler/depgraph

CPPSRCS = \
        Diagnostics.cpp \
        PreprocessorDiagnostics.cpp \
        DirectiveHandler.cpp \
        PreprocessorDirectiveHandler.cpp \
        DirectiveParser.cpp \
        ExpressionParser.cpp \
        Macro.cpp \
        MacroExpander.cpp \
        Tokenizer.cpp \
        InitializeParseContext.cpp \
        DependencyGraph.cpp \
        DependencyGraphBuilder.cpp \
        DependencyGraphOutput.cpp \
        DependencyGraphTraverse.cpp \
        RestrictFragmentShaderTiming.cpp \
        RestrictVertexShaderTiming.cpp \
        Compiler.cpp \
        DetectRecursion.cpp \
        InfoSink.cpp \
        Initialize.cpp \
        InitializeDll.cpp \
        Intermediate.cpp \
        intermOut.cpp \
        IntermTraverse.cpp \
        parseConst.cpp \
        ParseHelper.cpp \
        PoolAlloc.cpp \
        QualifierAlive.cpp \
        RemoveTree.cpp \
        ShaderLang.cpp \
        SymbolTable.cpp \
        VariableInfo.cpp \
        compilerdebug.cpp \
        util.cpp \
        ValidateLimitations.cpp \
        ForLoopUnroll.cpp \
        MapLongVariableNames.cpp \
        spooky.cpp \
        ArrayBoundsClamper.cpp \
        BuiltInFunctionEmulator.cpp \
        Input.cpp \
        Lexer.cpp \
        Preprocessor.cpp \
        Token.cpp \
        VariablePacker.cpp \
        $(NULL)

# flex/yacc generated files
CPPSRCS += \
        glslang_lex.cpp \
        glslang_tab.cpp \
        $(NULL)

# GLSL translator backend
CPPSRCS += \
        CodeGenGLSL.cpp \
        OutputGLSL.cpp \
        TranslatorGLSL.cpp \
        VersionGLSL.cpp \
        OutputESSL.cpp \
        OutputGLSLBase.cpp \
        TranslatorESSL.cpp \
        $(NULL)

ifeq ($(MOZ_WIDGET_TOOLKIT),windows)
CPPSRCS += ossource_win.cpp $(NULL)
else
CPPSRCS += ossource_posix.cpp $(NULL)
endif

CSRCS   = \
        atom.c \
        cpp.c \
        cppstruct.c \
        memory.c \
        scanner.c \
        symbols.c \
        tokens.c \
        $(NULL)

DEFINES += -DANGLE_BUILD -DCOMPILER_IMPLEMENTATION

#these defines are from ANGLE's build_angle.gyp
DEFINES += -DANGLE_DISABLE_TRACE
DEFINES += -DANGLE_COMPILE_OPTIMIZATION_LEVEL=D3DCOMPILE_OPTIMIZATION_LEVEL0
DEFINES += -DANGLE_USE_NEW_PREPROCESSOR=1

ifdef MOZ_ANGLE_RENDERER

# libEGL depends on (links against!) libGLESv2!
DIRS = src/libGLESv2 src/libEGL

libs::
ifdef MOZ_D3DX9_CAB
	expand "$(MOZ_D3DX9_CAB)" -F:$(MOZ_D3DX9_DLL) "$(DIST)/bin"
endif
ifdef MOZ_D3DCOMPILER_CAB
	expand "$(MOZ_D3DCOMPILER_CAB)" -F:$(MOZ_D3DCOMPILER_DLL) "$(DIST)/bin"
endif

endif

include $(topsrcdir)/config/rules.mk

# We have to filter out -pedantic, because of
# comma-at-end-of-enumerator list failures.  We can try to get this fixed
# upstream at some point.
CXXFLAGS := $(filter-out -pedantic,$(CXXFLAGS))
CFLAGS := $(filter-out -pedantic,$(CFLAGS))
