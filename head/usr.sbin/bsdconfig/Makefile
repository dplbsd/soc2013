# $FreeBSD: soc2013/dpl/head/usr.sbin/bsdconfig/Makefile 251524 2013-05-07 05:40:20Z dteske $

SUBDIR=	console \
	diskmgmt \
	docsinstall \
	dot \
	examples \
	include \
	mouse \
	networking \
	packages \
	password \
	security \
	share \
	startup \
	timezone \
	ttys \
	usermgmt

FILESDIR=	${LIBEXECDIR}/bsdconfig
FILES=		USAGE

SCRIPTS= bsdconfig

MAN= bsdconfig.8

beforeinstall:
	mkdir -p ${DESTDIR}${FILESDIR}
	mkdir -p ${DESTDIR}${SCRIPTSDIR}
	mkdir -p ${DESTDIR}${MANDIR}8

.include <bsd.prog.mk>
