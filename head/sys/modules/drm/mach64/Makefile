# $FreeBSD: soc2013/dpl/head/sys/modules/drm/mach64/Makefile 145175 2005-04-16 03:44:47Z anholt $

.PATH:	${.CURDIR}/../../../dev/drm
KMOD	= mach64
SRCS	= mach64_dma.c mach64_drv.c mach64_irq.c mach64_state.c
SRCS	+=device_if.h bus_if.h pci_if.h opt_drm.h

.include <bsd.kmod.mk>
