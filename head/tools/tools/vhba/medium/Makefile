# $FreeBSD: soc2013/dpl/head/tools/tools/vhba/medium/Makefile 208969 2010-06-08 22:26:47Z mjacob $
KMOD=	vmedium
SRCS=	vhba_medium.c vhba.c
CFLAGS += -I${.CURDIR}/.. -DVHBA_MOD=\"vmedium\"
VPATH=	${.CURDIR}/..

.include <bsd.kmod.mk>
