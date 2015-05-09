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

int openGpioBanks;


gpioBank *gpioinit(int bank)
{
	gpioBank *bankToReturn;
	static int fd=0;

	if(fd<=0){
		fd=open("/dev/mem",O_RDWR);
	}
	bankToReturn=malloc(sizeof(gpioBank));//Allocated memory to store all the addresses and be able to return it
	if(fd < 0)
	{
		fprintf(stderr,"\n%s", "Error in gpioinit.c: file descriptor is invalid.");
		return NULL;
	}
	if(bank==0)
	{
		bankToReturn->baseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO0BASE);
		bankToReturn->fd=fd;
	}
	else if(bank==1)
	{
		bankToReturn->baseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO1BASE);
		bankToReturn->fd=fd;
	}
	else if(bank==2)
	{
		bankToReturn->baseAddress=mmap(0,4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO2BASE);
		bankToReturn->fd=fd;
	}
	else if(bank==3)
	{
		bankToReturn->baseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, GPIO3BASE);
		bankToReturn->fd=fd;
	}
	else
	{
		fprintf(stderr, "\n%s\n\t%s%i\n\t%s", "Error in gpioinit.c: Selected bank is out of range.", "You "
				"selected: " , bank, "Possible choices are 0, 1, 2, 3");
		return NULL;
	}

	bankToReturn->outputEnable=(bankToReturn->baseAddress)+GPIOOE;
	bankToReturn->dataIn=(bankToReturn->baseAddress)+GPIODATIN;
	bankToReturn->dataOut=(bankToReturn->baseAddress)+GPIODATOUT;
	bankToReturn->setDataOut=(bankToReturn->baseAddress)+GPIOSETDATOUT;
	bankToReturn->clearDataOut=(bankToReturn->baseAddress)+GPIOCLRDATOUT;

	openGpioBanks++;

	return bankToReturn;
}
