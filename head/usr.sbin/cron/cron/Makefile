# $FreeBSD: soc2013/dpl/head/usr.sbin/cron/cron/Makefile 201433 2010-01-02 11:07:44Z ed $

PROG=	cron
MAN=	cron.8
SRCS=	cron.c database.c do_command.c job.c user.c popen.c

CFLAGS+= -DLOGIN_CAP -DPAM

DPADD=	${LIBCRON} ${LIBPAM} ${LIBUTIL}
LDADD=	${LIBCRON} ${MINUSLPAM} -lutil

WARNS?=	2

.include <bsd.prog.mk>
