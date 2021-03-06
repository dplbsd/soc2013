# $FreeBSD: soc2013/dpl/head/sbin/geom/class/Makefile.inc 250858 2013-04-19 19:45:00Z ed $

SHLIBDIR?=${GEOM_CLASS_DIR}
SHLIB_NAME?=geom_${GEOM_CLASS}.so
LINKS=	${BINDIR}/geom ${BINDIR}/g${GEOM_CLASS}
MAN=	g${GEOM_CLASS}.8
SRCS+=	geom_${GEOM_CLASS}.c subr.c

NO_WMISSING_VARIABLE_DECLARATIONS=

CFLAGS+= -I${.CURDIR}/../..

.include "../Makefile.inc"
