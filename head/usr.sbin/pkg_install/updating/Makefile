# $FreeBSD: soc2013/dpl/head/usr.sbin/pkg_install/updating/Makefile 222110 2011-05-17 19:11:47Z flz $

PROG=	pkg_updating
SRCS=	main.c

CFLAGS+= -I${.CURDIR}/../lib

WFORMAT?= 1

DPADD=	${LIBINSTALL} ${LIBFETCH} ${LIBMD}
LDADD=	${LIBINSTALL} -lfetch -lmd

.include <bsd.prog.mk>
