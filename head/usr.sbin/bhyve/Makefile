#
# $FreeBSD: soc2013/dpl/head/usr.sbin/bhyve/Makefile 250376 2013-04-05 22:19:02Z grehan $
#

PROG=	bhyve

DEBUG_FLAGS= -g -O0 

SRCS=	acpi.c atpic.c bhyverun.c consport.c dbgport.c elcr.c inout.c 
SRCS+=  ioapic.c mem.c mevent.c mptbl.c
SRCS+=	pci_emul.c pci_hostbridge.c pci_passthru.c pci_virtio_block.c
SRCS+=	pci_virtio_net.c pci_uart.c pit_8254.c pmtmr.c post.c rtc.c
SRCS+=	xmsr.c spinup_ap.c

.PATH:	${.CURDIR}/../../sys/amd64/vmm
SRCS+=	vmm_instruction_emul.c

NO_MAN=

DPADD=	${LIBVMMAPI} ${LIBMD} ${LIBPTHREAD}
LDADD=	-lvmmapi -lmd -lpthread

WARNS?=	2

.include <bsd.prog.mk>
