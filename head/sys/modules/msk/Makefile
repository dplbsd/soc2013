# $FreeBSD: soc2013/dpl/head/sys/modules/msk/Makefile 165183 2006-12-13 02:37:48Z yongari $

.PATH: ${.CURDIR}/../../dev/msk

KMOD=	if_msk
SRCS=	if_msk.c device_if.h bus_if.h pci_if.h
SRCS+=	miibus_if.h

.include <bsd.kmod.mk>
