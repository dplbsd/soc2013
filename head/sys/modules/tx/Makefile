# $FreeBSD: soc2013/dpl/head/sys/modules/tx/Makefile 150679 2005-09-27 18:10:43Z mlaier $

.PATH: ${.CURDIR}/../../dev/tx

KMOD=	if_tx
SRCS=	if_tx.c device_if.h bus_if.h pci_if.h
SRCS+=	miibus_if.h miidevs.h

.include <bsd.kmod.mk>
