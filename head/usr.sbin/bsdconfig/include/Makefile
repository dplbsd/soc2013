# $FreeBSD: soc2013/dpl/head/usr.sbin/bsdconfig/include/Makefile 248481 2013-02-25 19:55:32Z dteske $

NO_OBJ=

FILESDIR=	${LIBEXECDIR}/bsdconfig/include
FILES=		bsdconfig.hlp media.hlp messages.subr network_device.hlp \
		options.hlp tcp.hlp usage.hlp

beforeinstall:
	mkdir -p ${DESTDIR}${FILESDIR}

.include <bsd.prog.mk>
