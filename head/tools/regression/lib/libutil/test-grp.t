#!/bin/sh
#
# $FreeBSD: soc2013/dpl/head/tools/regression/lib/libutil/test-grp.t 178474 2008-04-23 00:49:13Z scf $
#

base=$(realpath $(dirname $0))
name=$(basename $0 .t)

set -e
cd $base
make -s $name >/dev/null
exec $base/$name
