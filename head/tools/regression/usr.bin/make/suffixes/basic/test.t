#!/bin/sh

# $FreeBSD: soc2013/dpl/head/tools/regression/usr.bin/make/suffixes/basic/test.t 146865 2005-05-31 14:13:07Z harti $

cd `dirname $0`
. ../../common.sh

# Description
DESC="Basic suffix operation."

# Setup
TEST_COPY_FILES="TEST1.a 644"

# Reset
TEST_CLEAN="Test1.b"

# Run
TEST_N=1
TEST_1="-r test1"

eval_cmd $*
