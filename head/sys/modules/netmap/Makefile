# $FreeBSD: soc2013/dpl/head/sys/modules/netmap/Makefile 236684 2012-05-29 19:55:07Z luigi $
#
# Compile netmap as a module, useful if you want a netmap bridge
# or loadable drivers.

.PATH: ${.CURDIR}/../../dev/netmap
.PATH.h: ${.CURDIR}/../../net
KMOD	= netmap
SRCS	= device_if.h bus_if.h opt_netmap.h
SRCS	+= netmap.c netmap.h netmap_kern.h

netmap.o: netmap_mem2.c

.include <bsd.kmod.mk>
