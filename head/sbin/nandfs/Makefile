# $FreeBSD: soc2013/dpl/head/sbin/nandfs/Makefile 235866 2012-05-17 10:11:18Z gber $

PROG=	nandfs
SRCS=	nandfs.c lssnap.c mksnap.c rmsnap.c
MAN=	nandfs.8

DPADD=	${LIBNANDFS}
LDADD=	-lnandfs

.include <bsd.prog.mk>
