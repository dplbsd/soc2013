# $FreeBSD: soc2013/dpl/head/tools/regression/lib/libc/stdlib/Makefile 131142 2004-06-25 12:31:12Z sobomax $

TESTS=	test-qsort	\
	test-heapsort	\
	test-mergesort

.PHONY: tests
tests: ${TESTS}
	for p in ${TESTS}; do ${.OBJDIR}/$$p; done

.PHONY: clean
clean:
	-rm -f ${TESTS}
