# $FreeBSD: soc2013/dpl/head/cddl/sbin/Makefile 168835 2007-04-16 21:20:26Z ru $

.include <bsd.own.mk>

SUBDIR=	${_zfs} ${_zpool}

.if ${MK_ZFS} != "no"
_zfs=	zfs
_zpool=	zpool
.endif

.include <bsd.subdir.mk>
