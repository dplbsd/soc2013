# $FreeBSD: soc2013/dpl/head/sys/modules/tpm/Makefile 211313 2010-08-13 04:00:35Z takawata $

.PATH:	${.CURDIR}/../../dev/tpm

KMOD=	tpm

SRCS=	tpm.c bus_if.h device_if.h
#Bus specific stuff.
SRCS+=	tpm_isa.c tpm_acpi.c isa_if.h opt_acpi.h acpi_if.h

.include <bsd.kmod.mk>
