/* $NetBSD: lttf2.c,v 1.1 2011/01/17 10:08:35 matt Exp $ */

/*
 * Written by Matt Thomas, 2011.  This file is in the Public Domain.
 */

#include "softfloat-for-gcc.h"
#include "milieu.h"
#include "softfloat.h"

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: soc2013/dpl/head/lib/libc/softfloat/lttf2.c 230645 2012-01-20 06:16:14Z das $");

#ifdef FLOAT128

flag __lttf2(float128, float128);

flag
__lttf2(float128 a, float128 b)
{

	/* libgcc1.c says -(a < b) */
	return -float128_lt(a, b);
}

#endif /* FLOAT128 */
