# $FreeBSD: soc2013/dpl/head/sys/modules/mlx4ib/Makefile 234466 2012-04-12 14:01:06Z jhb $
.PATH:  ${.CURDIR}/../../ofed/drivers/infiniband/hw/mlx4

.include <bsd.own.mk>

KMOD    = mlx4ib
SRCS    = device_if.h bus_if.h pci_if.h vnode_if.h
SRCS+=	ah.c cq.c doorbell.c mad.c main.c mr.c qp.c srq.c wc.c
SRCS+=	opt_inet.h opt_inet6.h

CFLAGS+= -I${.CURDIR}/../../ofed/include/

.if !defined(KERNBUILDDIR)
.if ${MK_INET_SUPPORT} != "no"
opt_inet.h:
	@echo "#define INET 1" > ${.TARGET}
.endif

.if ${MK_INET6_SUPPORT} != "no"
opt_inet6.h:
	@echo "#define INET6 1" > ${.TARGET}
.endif
.endif

.include <bsd.kmod.mk>

CFLAGS+= -Wno-cast-qual -Wno-pointer-arith -fms-extensions
