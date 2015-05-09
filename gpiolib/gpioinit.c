/*
 * gpioinit.c
 *
 *  Created on: May 1, 2015
 *      Author: christian
 *
 *   Description: This will set up all the local memory to use in the program.
 */
#include<sys/mman.h>
#include"gpiommap.h"


void gpioinit(int fd, int bank, gpioBank *memoryAllocated)
{
	if(fd < 0)
	{
		fprintf(stderr,"\n%s", "Error in gpioinit.c: file descriptor is invalid.");
		return;
	}
	if(bank==0)
	{
		memoryAllocated->baseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO0BASE);
	}
	else if(bank==1)
	{
		memoryAllocated->baseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO1BASE);
	}
	else if(bank==2)
	{
		memoryAllocated->baseAddress=mmap(0,4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO2BASE);
	}
	else if(bank==3)
	{
		memoryAllocated->baseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO3BASE);
	}
	else
	{
		fprintf(stderr, "\n%s\n\t%s%i\n\t%s", "Error in gpioinit.c: Selected bank is out of range.", "You "
				"selected: " , bank, "Possible choices are 0, 1, 2, 3");
		return;
	}

	memoryAllocated->outputEnable=(memoryAllocated->baseAddress)+GPIOOE;
	memoryAllocated->dataIn=(memoryAllocated->baseAddress)+GPIODATIN;
	memoryAllocated->dataOut=(memoryAllocated->baseAddress)+GPIODATOUT;
	memoryAllocated->setDataOut=(memoryAllocated->baseAddress)+GPIOSETDATOUT;
	memoryAllocated->clearDataOut=(memoryAllocated->baseAddress)+GPIOCLRDATOUT;



	return;
}
