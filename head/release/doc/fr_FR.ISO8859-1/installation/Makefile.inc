#
#      The FreeBSD Documentation Project
#      The FreeBSD French Documentation Project
#
#      $Id$
#      $FreeBSD: soc2013/dpl/head/release/doc/fr_FR.ISO8859-1/installation/Makefile.inc 97355 2002-05-26 16:49:48Z gioria $
#      Original revision: 1.2


.ifdef NO_LANGCODE_IN_DESTDIR
DESTDIR?=	${DOCDIR}/installation/${.CURDIR:T}
.else
DESTDIR?=	${DOCDIR}/fr_FR.ISO8859-1/installation/${.CURDIR:T}
.endif
