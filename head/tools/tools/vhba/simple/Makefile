# $FreeBSD: soc2013/dpl/head/tools/tools/vhba/simple/Makefile 208969 2010-06-08 22:26:47Z mjacob $
KMOD=	vsimple
SRCS=	vhba_simple.c vhba.c
CFLAGS += -I${.CURDIR}/.. -DVHBA_MOD=\"vsimple\"
VPATH=	${.CURDIR}/..

.include <bsd.kmod.mk>
