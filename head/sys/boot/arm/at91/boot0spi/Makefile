#  $FreeBSD: soc2013/dpl/head/sys/boot/arm/at91/boot0spi/Makefile 164366 2006-11-16 00:53:28Z imp $

.PATH:	${.CURDIR}/../libat91

P=boot0spi
FILES=${P}
SRCS=arm_init.S main.c
NO_MAN=
LDFLAGS=-e 0 -T ${.CURDIR}/../linker.cfg
OBJS+=  ${SRCS:N*.h:R:S/$/.o/g}

.include <bsd.prog.mk>

CFLAGS+=-DBOOT_BOOT0
