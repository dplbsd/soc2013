# $FreeBSD: soc2013/dpl/head/tools/tools/vhba/faulty/Makefile 208969 2010-06-08 22:26:47Z mjacob $
KMOD=	vfaulty
SRCS=	vhba_faulty.c vhba.c
CFLAGS += -I${.CURDIR}/.. -DVHBA_MOD=\"vfaulty\"
VPATH=	${.CURDIR}/..

.include <bsd.kmod.mk>
