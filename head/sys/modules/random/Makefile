# $FreeBSD: soc2013/dpl/head/sys/modules/random/Makefile 241302 2012-09-05 13:18:51Z kib $

.PATH: ${.CURDIR}/../../dev/random
.PATH: ${.CURDIR}/../../crypto/rijndael
.PATH: ${.CURDIR}/../../crypto/sha2

KMOD=	random
SRCS=	randomdev.c probe.c
.if ${MACHINE} == "amd64" || ${MACHINE} == "i386"
SRCS+=	nehemiah.c
SRCS+=	ivy.c
.endif
SRCS+=	randomdev_soft.c yarrow.c hash.c
SRCS+=	rijndael-alg-fst.c rijndael-api-fst.c sha2.c
SRCS+=	bus_if.h device_if.h vnode_if.h opt_cpu.h

CFLAGS+= -I${.CURDIR}/../..

.include <bsd.kmod.mk>
