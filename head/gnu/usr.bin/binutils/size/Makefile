# $FreeBSD: soc2013/dpl/head/gnu/usr.bin/binutils/size/Makefile 218865 2011-02-18 20:54:12Z dim $

.include "../Makefile.inc0"

.PATH: ${SRCDIR}/binutils ${SRCDIR}/binutils/doc

PROG=	size
SRCS=	size.c
CFLAGS+= -D_GNU_SOURCE
CFLAGS+= -I${.CURDIR}/${RELTOP}/libbinutils
CFLAGS+= -I${SRCDIR}/binutils
DPADD=	${RELTOP}/libbinutils/libbinutils.a
DPADD+=	${RELTOP}/libbfd/libbfd.a
DPADD+=	${RELTOP}/libiberty/libiberty.a
LDADD=	${DPADD}

.include <bsd.prog.mk>
