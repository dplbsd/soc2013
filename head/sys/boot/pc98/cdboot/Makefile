# $FreeBSD: soc2013/dpl/head/sys/boot/pc98/cdboot/Makefile 243890 2012-11-07 19:51:53Z dim $

PROG=	cdboot
STRIP=
BINMODE=${NOBINMODE}
NO_MAN=
SRCS=	${PROG}.S

CFLAGS+=-I${.CURDIR}/../../i386/common

ORG=	0x0000

LDFLAGS=-e start -Ttext ${ORG} -Wl,-N,-S,--oformat,binary

.include <bsd.prog.mk>

# XXX: clang integrated-as doesn't grok .codeNN directives yet
CFLAGS.cdboot.S=	${CLANG_NO_IAS}
CFLAGS+=		${CFLAGS.${.IMPSRC:T}}
