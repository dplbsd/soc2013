#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: soc2013/dpl/head/usr.sbin/pwd_mkdb/Makefile 201433 2010-01-02 11:07:44Z ed $

.PATH: ${.CURDIR}/../../lib/libc/gen		# for pw_scan.c

PROG=	pwd_mkdb
MAN=	pwd_mkdb.8
SRCS=	pw_scan.c pwd_mkdb.c

CFLAGS+= -I${.CURDIR}/../../lib/libc/gen		# for pw_scan.h

.include <bsd.prog.mk>
