# $FreeBSD: soc2013/dpl/head/sys/modules/xe/Makefile 129783 2004-05-26 00:53:10Z imp $

.PATH: ${.CURDIR}/../../dev/xe

KMOD=	if_xe
SRCS=	if_xe.c if_xe_pccard.c
SRCS+=	bus_if.h card_if.h device_if.h pccarddevs.h

.include <bsd.kmod.mk>
