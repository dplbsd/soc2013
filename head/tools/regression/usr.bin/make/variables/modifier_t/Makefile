# $FreeBSD: soc2013/dpl/head/tools/regression/usr.bin/make/variables/modifier_t/Makefile 237574 2012-06-12 23:16:00Z obrien $
#
# Test the t modifier.
#
# below is missing '
ASCII=	!"\#$$%&()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~

test1:
	@echo '${ASCII}'

test2:
	@echo '${ASCII:tl}'

test3:
	@echo '${ASCII:tu}'
