#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: soc2013/dpl/head/usr.bin/vmstat/Makefile 201429 2010-01-02 10:27:05Z ed $

PROG=	vmstat
MAN=	vmstat.8
DPADD=	${LIBDEVSTAT} ${LIBKVM} ${LIBMEMSTAT} ${LIBUTIL}
LDADD=	-ldevstat -lkvm -lmemstat -lutil

WARNS?=	1

.include <bsd.prog.mk>
