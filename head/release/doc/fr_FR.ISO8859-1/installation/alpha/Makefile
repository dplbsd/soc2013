#
#      The FreeBSD Documentation Project
#      The FreeBSD French Documentation Project
#
#      $Id$
#      $FreeBSD: soc2013/dpl/head/release/doc/fr_FR.ISO8859-1/installation/alpha/Makefile 242271 2012-10-01 11:26:49Z gabor $
#      Original revision: 1.4

RELN_ROOT?= ${.CURDIR}/../../..

DOC?= article
FORMATS?= html
INSTALL_COMPRESSED?= gz
INSTALL_ONLY_COMPRESSED?=

# SGML content
SRCS+=	article.xml
SRCS+=	../common/artheader.xml
SRCS+=	../common/abstract.xml
SRCS+=	../common/install.xml
SRCS+=	../common/layout.xml
SRCS+=	../common/trouble.xml
SRCS+=	../common/upgrade.xml

.include "${RELN_ROOT}/share/mk/doc.relnotes.mk"
.include "${DOC_PREFIX}/share/mk/doc.project.mk"
