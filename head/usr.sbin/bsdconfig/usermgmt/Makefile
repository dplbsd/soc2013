# $FreeBSD: soc2013/dpl/head/usr.sbin/bsdconfig/usermgmt/Makefile 241856 2012-09-18 22:28:42Z dteske $

NO_OBJ=

SUBDIR= include share

FILESDIR=	${LIBEXECDIR}/bsdconfig/070.usermgmt
FILES=		INDEX USAGE

SCRIPTSDIR=	${FILESDIR}
SCRIPTS=	groupadd groupdel groupedit groupinput \
		useradd userdel useredit userinput usermgmt

beforeinstall:
	mkdir -p ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>
