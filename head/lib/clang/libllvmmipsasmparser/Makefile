# $FreeBSD: soc2013/dpl/head/lib/clang/libllvmmipsasmparser/Makefile 247460 2013-02-02 22:28:29Z dim $

.include <bsd.own.mk>

LIB=	llvmmipsasmparser

SRCDIR=	lib/Target/Mips/AsmParser
INCDIR=	lib/Target/Mips
SRCS=	MipsAsmParser.cpp

TGHDRS=	MipsGenAsmMatcher \
	MipsGenInstrInfo \
	MipsGenRegisterInfo \
	MipsGenSubtargetInfo

.include "../clang.lib.mk"
