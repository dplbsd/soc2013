# $FreeBSD: soc2013/dpl/head/usr.sbin/bhyveload/Makefile 246355 2013-01-08 06:00:32Z neel $

PROG=	bhyveload
SRCS=	bhyveload.c
MAN=	bhyveload.8

DPADD+=	${LIBVMMAPI}
LDADD+=	-lvmmapi

WARNS?=	3

CFLAGS+=-I${.CURDIR}/../../sys/boot/userboot

.include <bsd.prog.mk>
