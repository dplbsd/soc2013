# The FreeBSD Simplified Chinese Project
# Original Revision: 82872
#
# $FreeBSD: soc2013/dpl/head/release/doc/zh_CN.GB2312/readme/Makefile 242271 2012-10-01 11:26:49Z gabor $

RELN_ROOT?= ${.CURDIR}/../..
.ifdef NO_LANGCODE_IN_DESTDIR
DESTDIR?= ${DOCDIR}/readme
.else
DESTDIR?= ${DOCDIR}/zh_CN.GB2312/readme
.endif

DOC?= article
FORMATS?= html
INSTALL_COMPRESSED?= gz
INSTALL_ONLY_COMPRESSED?=

# 
# SRCS lists the individual SGML files that make up the document. Changes
# to any of these files will force a rebuild
#

# SGML content
SRCS+=	article.xml

.include "${RELN_ROOT}/share/mk/doc.relnotes.mk"
.include "${DOC_PREFIX}/share/mk/doc.project.mk"
