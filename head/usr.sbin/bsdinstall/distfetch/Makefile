# $FreeBSD: soc2013/dpl/head/usr.sbin/bsdinstall/distfetch/Makefile 251712 2013-05-11 13:46:05Z antoine $

BINDIR= /usr/libexec/bsdinstall
PROG=	distfetch
DPADD=	${LIBFETCH} ${LIBNCURSESW} ${LIBDIALOG} ${LIBM}
LDADD=	-lfetch -lncursesw -ldialog -lm

WARNS?=	6
NO_MAN=	true

.include <bsd.prog.mk>
