# $FreeBSD: soc2013/dpl/head/sys/modules/ext2fs/Makefile 221209 2011-04-28 14:27:17Z jhb $

.PATH:	${.CURDIR}/../../fs/ext2fs
KMOD=	ext2fs
SRCS=	opt_ddb.h opt_directio.h opt_quota.h opt_suiddir.h vnode_if.h \
	ext2_alloc.c ext2_balloc.c ext2_bmap.c ext2_inode.c \
	ext2_inode_cnv.c ext2_lookup.c ext2_subr.c ext2_vfsops.c \
	ext2_vnops.c

.include <bsd.kmod.mk>
