# $FreeBSD: soc2013/dpl/head/tools/test/iconv/refgen/Makefile 219062 2011-02-25 00:04:39Z gabor $

.PATH: ${.CURDIR}/../tablegen

PROG=	refgen
NO_MAN=	yes
SRCS=	tablegen.c

WARNS?=	3
CFLAGS+= -L/usr/local/lib -I/usr/local/include
LDADD=	-liconv
DPADD=  /usr/local/lib/libiconv.a

.include <bsd.prog.mk>
