#	@(#)Makefile	8.1 (Berkeley) 6/5/93
# $FreeBSD: soc2013/dpl/head/sbin/ping/Makefile 161569 2006-08-22 08:03:01Z ru $

PROG=	ping
MAN=	ping.8
BINOWN=	root
BINMODE=4555
WARNS?=	2
DPADD=	${LIBM}
LDADD=	-lm

.if !defined(RELEASE_CRUNCH)
CFLAGS+=-DIPSEC
DPADD+=	${LIBIPSEC}
LDADD+=	-lipsec
.endif

.include <bsd.prog.mk>
