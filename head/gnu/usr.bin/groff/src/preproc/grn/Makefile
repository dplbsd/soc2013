# $FreeBSD: soc2013/dpl/head/gnu/usr.bin/groff/src/preproc/grn/Makefile 114455 2003-05-01 13:22:21Z ru $

PROG_CXX=	grn
SRCS=		hdb.cpp hpoint.cpp hgraph.cpp main.cpp
DPADD=	 	${LIBGROFF} ${LIBM}
LDADD=	 	${LIBGROFF} -lm
CLEANFILES=	${MAN}

.include <bsd.prog.mk>
