# $FreeBSD: soc2013/dpl/head/kerberos5/tools/make-roken/Makefile 233577 2012-03-22 08:48:42Z stas $

PROG=	make-roken
NO_MAN=

CLEANFILES= make-roken.c

.include "../Makefile.inc"

make-roken.c: ${KRB5DIR}/lib/roken/roken.awk ${KRB5DIR}/lib/roken/roken.h.in
	awk -f ${.ALLSRC} > ${.TARGET}

.include <bsd.prog.mk>
