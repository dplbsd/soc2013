# $FreeBSD: soc2013/dpl/head/secure/lib/Makefile 156856 2006-03-17 18:54:44Z ru $

.include <bsd.own.mk>

SUBDIR= 
.if ${MK_OPENSSL} != "no"
SUBDIR+=libcrypto libssl
.if ${MK_OPENSSH} != "no"
SUBDIR+=libssh
.endif
.endif

.include <bsd.subdir.mk>
