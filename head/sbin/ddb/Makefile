# $FreeBSD: soc2013/dpl/head/sbin/ddb/Makefile 204628 2010-03-02 16:58:04Z uqs $

PROG=	ddb
SRCS=	ddb.c ddb_capture.c ddb_script.c
MAN=	ddb.8
WARNS?=	3

DPADD=	${LIBKVM}
LDADD=	-lkvm

.include <bsd.prog.mk>
