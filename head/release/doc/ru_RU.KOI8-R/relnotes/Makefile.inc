# The FreeBSD Russian Documentation Project
#
# $FreeBSD: soc2013/dpl/head/release/doc/ru_RU.KOI8-R/relnotes/Makefile.inc 129587 2004-05-21 11:59:56Z den $
# $FreeBSDru: frdp/release/doc/ru_RU.KOI8-R/relnotes/Makefile.inc,v 1.1 2004/05/20 07:02:25 den Exp $
#
# Original revision: 1.2

.ifdef NO_LANGCODE_IN_DESTDIR
DESTDIR?=	${DOCDIR}/relnotes/${.CURDIR:T}
.else
DESTDIR?=	${DOCDIR}/ru_RU.KOI8-R/relnotes/${.CURDIR:T}
.endif
