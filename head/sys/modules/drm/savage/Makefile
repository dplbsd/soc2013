# $FreeBSD: soc2013/dpl/head/sys/modules/drm/savage/Makefile 152952 2005-11-28 23:13:57Z anholt $

.PATH:	${.CURDIR}/../../../dev/drm
KMOD= 	savage
CFLAGS += -I${.CURDIR}/../../../dev/drm
SRCS=	savage_bci.c savage_drv.c savage_state.c
SRCS+=	device_if.h bus_if.h pci_if.h opt_drm.h

.include <bsd.kmod.mk>
