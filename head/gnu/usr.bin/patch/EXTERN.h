/* $FreeBSD: soc2013/dpl/head/gnu/usr.bin/patch/EXTERN.h 51005 1999-09-05 17:31:55Z peter $
 *
 * $Log: EXTERN.h,v $
 * Revision 2.0  86/09/17  15:35:37  lwall
 * Baseline for netwide release.
 *
 */

#ifdef EXT
#undef EXT
#endif
#define EXT extern

#ifdef INIT
#undef INIT
#endif
#define INIT(x)

#ifdef DOINIT
#undef DOINIT
#endif
