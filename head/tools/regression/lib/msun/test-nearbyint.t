#!/bin/sh
# $FreeBSD: soc2013/dpl/head/tools/regression/lib/msun/test-nearbyint.t 216182 2010-12-03 00:44:31Z das $

cd `dirname $0`

executable=`basename $0 .t`

make $executable 2>&1 > /dev/null

exec ./$executable
