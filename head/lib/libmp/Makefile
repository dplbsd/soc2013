# $FreeBSD: soc2013/dpl/head/lib/libmp/Makefile 201424 2010-01-02 09:58:07Z ed $

LIB=		mp
SHLIB_MAJOR=	7
DPADD=		${LIBCRYPTO}
LDADD=		-lcrypto
MAN=		libmp.3
INCS=		mp.h
SRCS=		mpasbn.c

CFLAGS+=	-I${.CURDIR}/../../crypto

VERSION_DEF=	${.CURDIR}/../libc/Versions.def
SYMBOL_MAPS=	${.CURDIR}/Symbol.map

.include <bsd.lib.mk>
