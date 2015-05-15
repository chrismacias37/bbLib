/*
 * testProgram.c
 *
 *  Created on: May 14, 2015
 *      Author: christian
 */
#include<stdio.h>
#include"mux.h"

void main(void)
{
	int currentmode=-1;

	initmux();
	currentmode=chkpinmode(8,3);
	printf("\n%s%i\n", "Current mode: ", currentmode);
	muxdone();
}
