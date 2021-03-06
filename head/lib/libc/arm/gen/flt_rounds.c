/*-
 * Copyright (c) 2012 Ian Lepore <freebsd@damnhippie.dyndns.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: soc2013/dpl/head/lib/libc/arm/gen/flt_rounds.c 230649 2012-01-20 06:54:30Z das $");

#include <fenv.h>
#include <float.h>

#include "softfloat-for-gcc.h"
#include "milieu.h"
#include "softfloat.h"

int
__flt_rounds(void)
{

#ifndef ARM_HARD_FLOAT
	/*
	 * Translate our rounding modes to the unnamed
	 * manifest constants required by C99 et. al.
	 */
	switch (__softfloat_float_rounding_mode) {
	case FE_TOWARDZERO:
		return (0);
	case FE_TONEAREST:
		return (1);
	case FE_UPWARD:
		return (2);
	case FE_DOWNWARD:
		return (3);
	}
	return (-1);
#else /* ARM_HARD_FLOAT */
	/*
	 * Apparently, the rounding mode is specified as part of the
	 * instruction format on ARM, so the dynamic rounding mode is
	 * indeterminate.  Some FPUs may differ.
	 */
	return (-1);
#endif /* ARM_HARD_FLOAT */
}
