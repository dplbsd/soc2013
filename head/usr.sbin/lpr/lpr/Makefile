#	From: @(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: soc2013/dpl/head/usr.sbin/lpr/lpr/Makefile 201433 2010-01-02 11:07:44Z ed $

.PATH: ${.CURDIR}/../common_source

BINDIR=	/usr/bin

PROG=	lpr
MAN=	lpr.1 printcap.5
BINOWN=	root
BINGRP=	daemon
BINMODE= 6555

CFLAGS+= -I${.CURDIR}/../common_source

WARNS?=	2

DPADD=	${LIBLPR}
LDADD=	${LIBLPR}

.include <bsd.prog.mk>
