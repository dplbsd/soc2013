#!/bin/sh

# $FreeBSD: soc2013/dpl/head/tools/regression/usr.bin/make/execution/ellipsis/test.t 228430 2011-11-30 05:49:17Z fjoe $

cd `dirname $0`
. ../../common.sh

# Description
DESC="Ellipsis command from variable"

# Run
TEST_N=1
TEST_1=

eval_cmd $*
