#	@(#)Makefile	8.8 (Berkeley) 6/21/2000
#
# $TSHeader: src/sbin/growfs/Makefile,v 1.4 2000/12/05 19:45:24 tomsoft Exp $
# $FreeBSD: soc2013/dpl/head/sbin/growfs/Makefile 235135 2012-04-30 16:08:02Z trasz $
#

#GFSDBG=

.PATH:	${.CURDIR}/../mount

PROG=   growfs
SRCS=   growfs.c getmntopts.c
MAN=	growfs.8
CFLAGS+=-I${.CURDIR}/../mount

.if defined(GFSDBG)
SRCS+=  debug.c
.endif  

DPADD=	${LIBUTIL}
LDADD=	-lutil

.include <bsd.prog.mk>      
