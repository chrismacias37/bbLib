/*
 * muxDone.c
 *
 *  Created on: May 14, 2015
 *      Author: christian
 */
#include"mux.h"
#include<fcntl.h>

void muxdone(void)
{
	close(fdMux);
	munmap(pins.baseAddress);
}
