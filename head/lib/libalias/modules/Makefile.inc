# $FreeBSD: soc2013/dpl/head/lib/libalias/modules/Makefile.inc 163171 2006-10-08 14:02:00Z piso $

.PATH: ${.CURDIR}/../../../../sys/netinet/libalias

SHLIBDIR?= /lib
LIB?=   alias_${NAME}
SHLIB_NAME?=libalias_${NAME}.so
WARNS?=	1
