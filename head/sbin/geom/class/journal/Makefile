# $FreeBSD: soc2013/dpl/head/sbin/geom/class/journal/Makefile 216511 2010-12-15 23:24:34Z obrien $

.PATH: ${.CURDIR}/../../misc

GEOM_CLASS=	journal
SRCS+=	geom_journal_ufs.c

DPADD=	${LIBMD} ${LIBUFS}
LDADD=	-lmd -lufs

CFLAGS+=-I${.CURDIR}/../../../../sys

.include <bsd.lib.mk>
