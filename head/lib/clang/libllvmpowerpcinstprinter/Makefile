# $FreeBSD: soc2013/dpl/head/lib/clang/libllvmpowerpcinstprinter/Makefile 247460 2013-02-02 22:28:29Z dim $

.include <bsd.own.mk>

LIB=	llvmpowerpcinstprinter

SRCDIR=	lib/Target/PowerPC/InstPrinter
INCDIR=	lib/Target/PowerPC
SRCS=	PPCInstPrinter.cpp

TGHDRS=	PPCGenAsmWriter \
	PPCGenInstrInfo \
	PPCGenRegisterInfo \
	PPCGenSubtargetInfo

.include "../clang.lib.mk"
