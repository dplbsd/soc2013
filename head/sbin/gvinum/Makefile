# $FreeBSD: soc2013/dpl/head/sbin/gvinum/Makefile 240946 2012-08-28 14:20:41Z brooks $

PROG=	gvinum
SRCS=	gvinum.c gvinum.h geom_vinum_share.c
MAN=	gvinum.8

WARNS?=	2
CFLAGS+=	-I${.CURDIR}/../../sys -I${DESTDIR}/${INCLUDEDIR}/edit

DPADD=	${LIBEDIT} ${LIBTERMCAP} ${LIBDEVSTAT} ${LIBKVM} ${LIBGEOM}
LDADD=	-ledit -ltermcap -ldevstat -lkvm -lgeom

.PATH: ${.CURDIR}/../../sys/geom/vinum

.include <bsd.prog.mk>
