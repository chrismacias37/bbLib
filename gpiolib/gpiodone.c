/*
 * gpiodone.c
 *
 *  Created on: May 1, 2015
 *      Author: christian
 */

#include"gpiommap.h"
#include<sys/mman.h>

int gpiodone(gpioBank *addresses)
{
	munmap((void *)addresses->baseAddress,4096);
	return 0;
}
