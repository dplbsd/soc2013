# $FreeBSD: soc2013/dpl/head/sys/modules/nandfs/Makefile 235866 2012-05-17 10:11:18Z gber $

.PATH: ${.CURDIR}/../../fs/nandfs

KMOD=	nandfs
SRCS=	vnode_if.h \
	bmap.c nandfs_bmap.c nandfs_dir.c nandfs_subr.c nandfs_vfsops.c \
	nandfs_vnops.c nandfs_alloc.c nandfs_cpfile.c nandfs_dat.c \
	nandfs_ifile.c nandfs_segment.c nandfs_sufile.c nandfs_buffer.c \
	nandfs_cleaner.c

.include <bsd.kmod.mk>
