/*	$FreeBSD: soc2013/dpl/head/contrib/ipfilter/lib/addicmp.c 170311 2007-06-04 02:54:36Z darrenr $	*/

/*
 * Copyright (C) 2000-2006 by Darren Reed.
 *
 * See the IPFILTER.LICENCE file for details on licencing.
 *
 * $Id: addicmp.c,v 1.10.2.5 2006/06/16 17:20:55 darrenr Exp $
 */

#include <ctype.h>

#include "ipf.h"


char	*icmptypes[MAX_ICMPTYPE + 1] = {
	"echorep", (char *)NULL, (char *)NULL, "unreach", "squench",
	"redir", (char *)NULL, (char *)NULL, "echo", "routerad",
	"routersol", "timex", "paramprob", "timest", "timestrep",
	"inforeq", "inforep", "maskreq", "maskrep", "END"
};
