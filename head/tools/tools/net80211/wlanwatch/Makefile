# $FreeBSD: soc2013/dpl/head/tools/tools/net80211/wlanwatch/Makefile 160822 2006-07-28 10:59:27Z yar $

PROG=	wlanwatch
BINDIR=	/usr/local/bin
NO_MAN=

.include <bsd.own.mk>

.if ${MK_INET6_SUPPORT} != "no"
CFLAGS+= -DINET6
.endif

.include <bsd.prog.mk>
