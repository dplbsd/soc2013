#	@(#)Makefile	8.1 (Berkeley) 8/14/93
# $FreeBSD: soc2013/dpl/head/share/doc/psd/15.yacc/Makefile 210210 2010-07-16 17:01:36Z emaste $

VOLUME=		psd/15.yacc
SRCS=		stubs ss_ ss0 ss1 ss2 ss3 ss4 ss5 ss6 ss7 ss8 ss9 \
		ss10 ss11 ssa ssb ssc ssd
EXTRA=		ref.bib
MACROS=		-ms
USE_REFER=
CLEANFILES=	stubs

stubs:
	@(echo .R1; echo database ${.CURDIR}/ref.bib; \
	    echo accumulate; echo .R2) > ${.TARGET}

.include <bsd.doc.mk>
