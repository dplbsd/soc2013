# $FreeBSD: soc2013/dpl/head/lib/clang/libllvmx86asmparser/Makefile 250624 2013-04-12 17:57:40Z dim $

.include <bsd.own.mk>

LIB=	llvmx86asmparser

SRCDIR=	lib/Target/X86/AsmParser
INCDIR=	lib/Target/X86
SRCS=	X86AsmParser.cpp

TGHDRS=	X86GenAsmMatcher \
	X86GenInstrInfo \
	X86GenRegisterInfo \
	X86GenSubtargetInfo

.include "../clang.lib.mk"
