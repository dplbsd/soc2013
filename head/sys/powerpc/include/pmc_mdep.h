/*-
 * This file is in the public domain.
 *
 * $FreeBSD: soc2013/dpl/head/sys/powerpc/include/pmc_mdep.h 233911 2012-03-28 20:58:30Z fabient $
 */

#ifndef _MACHINE_PMC_MDEP_H_
#define	_MACHINE_PMC_MDEP_H_

#define PMC_MDEP_CLASS_INDEX_PPC7450	1

union pmc_md_op_pmcallocate {
	uint64_t		__pad[4];
};

/* Logging */
#define	PMCLOG_READADDR		PMCLOG_READ32
#define	PMCLOG_EMITADDR		PMCLOG_EMIT32

#if	_KERNEL

struct pmc_md_powerpc_pmc {
	uint32_t	pm_powerpc_evsel;
};

union pmc_md_pmc {
	struct pmc_md_powerpc_pmc	pm_powerpc;
};

#define	PMC_TRAPFRAME_TO_PC(TF)	(0)	/* Stubs */
#define	PMC_TRAPFRAME_TO_FP(TF)	(0)
#define	PMC_TRAPFRAME_TO_SP(TF)	(0)

#endif

#endif /* !_MACHINE_PMC_MDEP_H_ */
