# $FreeBSD: soc2013/dpl/head/gnu/lib/libreadline/history/Makefile 211286 2010-08-12 20:46:49Z will $

SUBDIR= doc

LIB=    history
MAN=    rlhistory.3

SRCS= $(HISTSRC) xmalloc.c

rlhistory.3: doc/history.3
	cp -f ${.ALLSRC} ${.TARGET}

CLEANFILES+= rlhistory.3

.include <bsd.lib.mk>
