# $FreeBSD: soc2013/dpl/head/usr.bin/enigma/Makefile 125546 2004-02-05 22:44:25Z ru $

PROG=	enigma

LINKS=	${BINDIR}/enigma ${BINDIR}/crypt
MLINKS=	enigma.1 crypt.1

DPADD=	${LIBCRYPT}
LDADD=	-lcrypt

.include <bsd.prog.mk>
