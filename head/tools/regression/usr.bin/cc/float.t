#!/bin/sh
# $FreeBSD: soc2013/dpl/head/tools/regression/usr.bin/cc/float.t 230650 2012-01-20 06:57:21Z das $

cd `dirname $0`

executable=`basename $0 .t`

make $executable 2>&1 > /dev/null

exec ./$executable
