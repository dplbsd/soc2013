# $FreeBSD: soc2013/dpl/head/sys/modules/agp/Makefile 244285 2012-11-15 20:25:09Z eadler $

.PATH: ${.CURDIR}/../../dev/agp

KMOD=	agp
SRCS=	agp.c agp_if.c
.if ${MACHINE_CPUARCH} == "i386"
SRCS+=	agp_i810.c agp_intel.c agp_via.c agp_sis.c agp_ali.c agp_amd.c \
	agp_nvidia.c agp_ati.c
.endif
.if ${MACHINE} == "i386"
SRCS+=	agp_amd64.c
.endif
.if ${MACHINE_CPUARCH} == "amd64"
SRCS+=	agp_amd64.c agp_i810.c agp_via.c
.endif
.if ${MACHINE_CPUARCH} == "powerpc"
SRCS+=  agp_apple.c
.endif
SRCS+=	device_if.h bus_if.h agp_if.h pci_if.h
SRCS+=	opt_agp.h
MFILES=	kern/device_if.m kern/bus_if.m dev/agp/agp_if.m dev/pci/pci_if.m
WERROR=

EXPORT_SYMS=	agp_find_device		\
		agp_state		\
		agp_acquire		\
		agp_release		\
		agp_enable		\
		agp_alloc_memory	\
		agp_free_memory		\
		agp_bind_memory		\
		agp_unbind_memory	\
		agp_memory_info


.if ${MACHINE_CPUARCH} == "i386"  || ${MACHINE_CPUARCH} == "amd64"
EXPORT_SYMS+=	intel_gtt_clear_range	\
		intel_gtt_insert_pages	\
		intel_gtt_get		\
		intel_gtt_chipset_flush	\
		intel_gtt_unmap_memory	\
		intel_gtt_map_memory	\
		intel_gtt_insert_sg_entries \
		intel_gtt_get_bridge_device
.endif

.include <bsd.kmod.mk>
