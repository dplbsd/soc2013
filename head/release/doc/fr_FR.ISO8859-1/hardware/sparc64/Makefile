#
#      The FreeBSD Documentation Project
#      The FreeBSD French Documentation Project
#
#      $Id$
#      $FreeBSD: soc2013/dpl/head/release/doc/fr_FR.ISO8859-1/hardware/sparc64/Makefile 242271 2012-10-01 11:26:49Z gabor $
#      Original revision: 1.1


RELN_ROOT?= ${.CURDIR}/../../..

DOC?= article
FORMATS?= html
INSTALL_COMPRESSED?= gz
INSTALL_ONLY_COMPRESSED?=

JADEFLAGS+=	-V %generate-article-toc%

# SGML content
SRCS+=	article.xml 
SRCS+=	proc-sparc64.xml 
SRCS+=	dev-sparc64.xml 
SRCS+=	../common/hw.ent
SRCS+=	../common/artheader.xml

.include "${RELN_ROOT}/share/mk/doc.relnotes.mk"
.include "${DOC_PREFIX}/share/mk/doc.project.mk"
