# $FreeBSD: soc2013/dpl/head/lib/libproc/Makefile 241324 2012-09-06 03:19:48Z rpaulo $

.include <bsd.own.mk>

LIB=	proc

SRCS=	proc_bkpt.c		\
	proc_create.c		\
	proc_regs.c		\
	proc_sym.c		\
	proc_rtld.c		\
	proc_util.c

INCS=	libproc.h

CFLAGS+=	-I${.CURDIR}

.if ${MK_LIBCPLUSPLUS} != "no"
LDADD+=		-lcxxrt
DPADD+=		${LIBCXXRT}
.else
LDADD+=		-lsupc++
DPADD+=		${LIBSTDCPLUSPLUS}
.endif

SHLIB_MAJOR=	2

WITHOUT_MAN=

.include <bsd.lib.mk>
