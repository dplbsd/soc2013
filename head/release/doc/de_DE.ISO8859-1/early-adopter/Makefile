# The FreeBSD Documentation
# The FreeBSD German Documentation Project
#
# $FreeBSD: soc2013/dpl/head/release/doc/de_DE.ISO8859-1/early-adopter/Makefile 242271 2012-10-01 11:26:49Z gabor $
# $FreeBSDde: de-docproj/relnotes/de_DE.ISO8859-1/early-adopter/Makefile,v 1.1 2002/10/28 18:37:20 ue Exp $
# basiert auf: 1.3

RELN_ROOT?= ${.CURDIR}/../..
.ifdef NO_LANGCODE_IN_DESTDIR
DESTDIR?= ${DOCDIR}/early-adopter
.else
DESTDIR?= ${DOCDIR}/de_DE.ISO8859-1/early-adopter
.endif

DOC?= article
FORMATS?= html
INSTALL_COMPRESSED?=gz
INSTALL_ONLY_COMPRESSED?=

SRCS+= article.xml

.include "${RELN_ROOT}/share/mk/doc.relnotes.mk"
.include "${DOC_PREFIX}/share/mk/doc.project.mk"
