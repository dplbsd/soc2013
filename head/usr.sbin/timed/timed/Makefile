#	@(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: soc2013/dpl/head/usr.sbin/timed/timed/Makefile 189133 2009-02-26 20:59:05Z ed $
#
# optional flags are: MEASURE TESTING DEBUG

PROG=	timed
MAN=	timed.8
SRCS=	acksend.c candidate.c correct.c master.c networkdelta.c readmsg.c \
	slave.c timed.c byteorder.c measure.c cksum.c

DPADD=	${LIBUTIL}
LDADD=	-lutil

WARNS?=	1

.include "../../Makefile.inc"
.include <bsd.prog.mk>
