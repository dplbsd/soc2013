# $FreeBSD: soc2013/dpl/head/tools/regression/sbin/dhclient/Makefile 228540 2011-12-04 14:44:31Z dumbbell $

.PATH:	${.CURDIR}/../../../../sbin/dhclient

SRCS=	alloc.c convert.c hash.c options.c tables.c			\
	fake.c								\
	option-domain-search.c

CFLAGS+= -I${.CURDIR}/../../../../sbin/dhclient
LDADD=	-lutil

PROG=	option-domain-search

WARNS?=	2

.include <bsd.prog.mk>
