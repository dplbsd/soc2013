# $FreeBSD: soc2013/dpl/head/usr.sbin/fdread/Makefile 201433 2010-01-02 11:07:44Z ed $

PROG=	fdread
SRCS=	fdread.c fdutil.c

.if ${MACHINE} == "pc98"
CFLAGS+= -DPC98
.endif

.include <bsd.prog.mk>
