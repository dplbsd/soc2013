# From:	@(#)Makefile	8.3 (Berkeley) 4/2/94
# $FreeBSD: soc2013/dpl/head/usr.bin/passwd/Makefile 244807 2012-11-27 16:23:12Z pjd $

.include <bsd.own.mk>

PROG	 = passwd
BINOWN	 = root
BINMODE	 = 4555
DPADD	 = ${LIBPAM}
LDADD	 = ${MINUSLPAM}
.if ${MK_NIS} != "no"
LINKS	 = ${BINDIR}/passwd ${BINDIR}/yppasswd
MLINKS	 = passwd.1 yppasswd.1
.endif

beforeinstall:
.for i in passwd yppasswd
	[ ! -e ${DESTDIR}${BINDIR}/$i ] || \
		chflags noschg ${DESTDIR}${BINDIR}/$i || true
.endfor

.if !defined(NO_FSCHG)
afterinstall:
	-chflags schg ${DESTDIR}${BINDIR}/passwd
.endif

.include <bsd.prog.mk>
