#$FreeBSD: soc2013/dpl/head/kerberos5/lib/libheimipcs/Makefile 236777 2012-05-30 22:21:25Z obrien $

LIB=	heimipcs
INTERNALLIB=
LDADD=	-lheimbase -lroken
LDFLAGS=	-pthread
DPADD=	${LIBHEIMBASE} ${LIBROKEN}

SRCS=	\
	server.c \
	common.c

CFLAGS+=	-DPIC ${PICFLAG}
CFLAGS+=	-I${KRB5DIR}/lib/roken \
		-I${KRB5DIR}/base \
		-I${KRB5DIR}/lib/ipc -I.

.include <bsd.lib.mk>

.PATH: ${KRB5DIR}/lib/ipc
