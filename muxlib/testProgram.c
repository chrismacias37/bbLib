/*
 * testProgram.c
 *
 *  Created on: May 14, 2015
 *      Author: christian
 */
#include"mux.h"

void main(void)
{
	int currentmode=-1;

	if(initmux()==-1)
	{//Stops the program if it could not initialize
		return;
	}
	currentmode=chkpinmode(9,11);
	if(currentmode==-1)
	{
		fprintf(stderr, "\n%s\n", "WOW WOW WOW... Something didn't work.... Check the log");
		return;
	}
	printf("\n%s%i\n", "Current mode: ", currentmode);
	muxdone();
}
