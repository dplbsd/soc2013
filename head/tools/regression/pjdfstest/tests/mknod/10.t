#!/bin/sh
# $FreeBSD: soc2013/dpl/head/tools/regression/pjdfstest/tests/mknod/10.t 211010 2010-08-06 20:51:39Z pjd $

desc="mknod returns EFAULT if the path argument points outside the process's allocated address space"

dir=`dirname $0`
. ${dir}/../misc.sh

echo "1..2"

expect EFAULT mknod NULL f 0644 0 0
expect EFAULT mknod DEADCODE f 0644 0 0
