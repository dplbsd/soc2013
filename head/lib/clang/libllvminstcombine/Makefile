# $FreeBSD: soc2013/dpl/head/lib/clang/libllvminstcombine/Makefile 247460 2013-02-02 22:28:29Z dim $

.include <bsd.own.mk>

LIB=	llvminstcombine

SRCDIR=	lib/Transforms/InstCombine
SRCS=	InstCombineAddSub.cpp \
	InstCombineAndOrXor.cpp \
	InstCombineCalls.cpp \
	InstCombineCasts.cpp \
	InstCombineCompares.cpp \
	InstCombineLoadStoreAlloca.cpp \
	InstCombineMulDivRem.cpp \
	InstCombinePHI.cpp \
	InstCombineSelect.cpp \
	InstCombineShifts.cpp \
	InstCombineSimplifyDemanded.cpp \
	InstCombineVectorOps.cpp \
	InstructionCombining.cpp

TGHDRS=	Intrinsics

.include "../clang.lib.mk"
