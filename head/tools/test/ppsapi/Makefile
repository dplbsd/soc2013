# $FreeBSD: soc2013/dpl/head/tools/test/ppsapi/Makefile 245233 2012-12-08 22:16:36Z eadler $

PROG=	ppsapitest
NO_MAN=

WARNS?=	5

.include <bsd.prog.mk>

test:	${PROG}
	./${PROG} /dev/cuau0
