# $FreeBSD: soc2013/dpl/head/usr.sbin/bsdconfig/packages/Makefile 251524 2013-05-07 05:40:20Z dteske $

NO_OBJ=

SUBDIR= include

FILESDIR=	${LIBEXECDIR}/bsdconfig/030.packages
FILES=		INDEX USAGE

SCRIPTSDIR=	${FILESDIR}
SCRIPTS=	packages

beforeinstall:
	mkdir -p ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>
