# $FreeBSD: soc2013/dpl/head/sys/modules/vpo/Makefile 89302 2002-01-11 15:49:02Z ru $

.PATH: ${.CURDIR}/../../dev/ppbus

KMOD=	vpo
SRCS=	bus_if.h device_if.h ppbus_if.h \
	opt_cam.h opt_scsi.h opt_vpo.h \
	immio.c vpo.c vpoio.c

.include <bsd.kmod.mk>
