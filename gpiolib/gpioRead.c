/*
 * gpioRead.c
 *
 *  Created on: Apr 28, 2015
 *      Author: christian
 */


#include<fcntl.h>
#include"gpiommap.h"

int gpioRead(gpioBank *bank, int pin)
{
	unsigned int dataInputValues;//Will store the Output Enable values

	//Removed after the addition of gpioinit.c
//	if(bank==0)//will check the which gpio bank is selected and allocate the memory and return the address
//	{
//		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO0BASE);//Sets the memory map for use. This is used for the case address
//	}
//	if(bank==1)
//	{
//		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO1BASE);
//	}
//	if(bank==2)
//	{
//		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO2BASE);
//	}
//	if(bank==3)
//	{
//		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO3BASE);
//	}
//	if(bank>3 || bank<0)//ERROR CHECK
//	{
//		fprintf(stderr, "\n%s", "Error in gpioRead: Bank Selected is out of range. Must be 0, 1, 2, or 3");
//		fflush(stderr);
//		return -1;
//	}
//	if(pin>31 || pin < 0)
//	{
//		fprintf(stderr,"\n%s", "Error in gpioRead: Pin selected is out of range. Must be 0-31");
//		fflush(stderr);
//		return -1;
//	}

	dataInputValues=*(bank->dataIn);

	if((dataInputValues&(1<<pin))==0)
	{
		return 0;
	}
	else
	{
		return 1;
	}

	return -1;
}
