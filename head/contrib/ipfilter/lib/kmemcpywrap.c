/*	$FreeBSD: soc2013/dpl/head/contrib/ipfilter/lib/kmemcpywrap.c 170311 2007-06-04 02:54:36Z darrenr $	*/

/*
 * Copyright (C) 2002 by Darren Reed.
 * 
 * See the IPFILTER.LICENCE file for details on licencing.  
 *   
 * $Id: kmemcpywrap.c,v 1.1.4.1 2006/06/16 17:21:05 darrenr Exp $ 
 */     

#include "ipf.h"
#include "kmem.h"

int kmemcpywrap(from, to, size)
void *from, *to;
size_t size;
{
	int ret;

	ret = kmemcpy((caddr_t)to, (u_long)from, size);
	return ret;
}

