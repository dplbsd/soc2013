# $FreeBSD: soc2013/dpl/head/sys/modules/ata/atapci/Makefile 250414 2013-04-06 19:12:49Z marius $

SUBDIR += chipsets

.PATH: ${.CURDIR}/../../../dev/ata

KMOD=	atapci
SRCS=	ata-pci.c ata-dma.c ata-sata.c
SRCS+=	ata_if.h bus_if.h device_if.h pci_if.h

.include <bsd.kmod.mk>
