/*
 * gpioRead.c
 *
 *  Created on: Apr 28, 2015
 *      Author: christian
 */


#include<stdio.h>
#include<fcntl.h>
#include"gpiommap.h"

int gpioRead(int bank, int pin)
{
	int fd=open("/dev/mem", O_RDWR);//file descriptor
	volatile void *gpioBaseAddress=NULL;//will store the base address for the gpio chosen. We has to use void because the size of this is 4Kbytes and there is not type for this.
	unsigned volatile int *gpioDataInput=NULL;//This on is an int because it is 32bits or 4 bytes
	unsigned int dataInputValues;//Will store the Output Enable values
	int returnVal;//Save the return Value

	if(bank==0)//will check the which gpio bank is selected and allocate the memory and return the address
	{
		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO0BASE);//Sets the memory map for use. This is used for the case address
	}
	if(bank==1)
	{
		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO1BASE);
	}
	if(bank==2)
	{
		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO2BASE);
	}
	if(bank==3)
	{
		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO3BASE);
	}
	if(bank>3 || bank<0)//ERROR CHECK
	{
		fprintf(stderr, "\n%s", "Error in gpioRead: Bank Selected is out of range. Must be 0, 1, 2, or 3");
		fflush(stderr);
		return -1;
	}
	if(pin>31 || pin < 0)
	{
		fprintf(stderr,"\n%s", "Error in gpioRead: Pin selected is out of range. Must be 0-31");
		fflush(stderr);
		return -1;
	}
	gpioDataInput=gpioBaseAddress+GPIODATIN;
	dataInputValues=*gpioDataInput;

	if(((~(dataInputValues)|(1<<pin))&dataInputValues)==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	close(fd);
	return -1;
}
