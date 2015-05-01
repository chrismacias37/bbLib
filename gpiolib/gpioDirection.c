/*
 * gpioDirection.c
 *
 *  Created on: Apr 28, 2015
 *      Author: christian
 */

#include<fcntl.h>
#include<string.h>
#include"gpiommap.h"



int gpiodirection(int bank, int pin, char *direction)
{
	int fd=open("/dev/mem", O_RDWR);//file descriptor
	volatile void *gpioBaseAddress=NULL;//Allocated memory for the address's
	unsigned volatile int *gpioOE=NULL;
	unsigned int oeValue;//Will store the Output Enable values

	if(bank==0)//will check the which gpio bank is selected and allocate the memory and return the address
	{
		gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO0BASE);
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
		fprintf(stderr, "\n%s", "Error in gpiodirection: Bank Selected is out of range. Must be 0, 1, 2, or 3");
		fflush(stderr);
		return -1;
	}
	if(pin>31 || pin < 0)
	{
		fprintf(stderr,"\n%s", "Error in gpiodirection: Pin selected is out of range. Must be 0-31");
		fflush(stderr);
		return -1;
	}

	gpioOE=gpioBaseAddress+GPIOOE;
	oeValue=*gpioOE;//Saves the Output Enable Values

	 if(gpioBaseAddress == MAP_FAILED)//Checks if map was successful
	 {
	        printf("\n%s", "Error in gpiodirection: Unable to map gpioBaseAddress");
	        return -1;
	 }

	if(strncmp(direction,"ou",2)==0)//Checks to see if the user typed "out"
	{
		*gpioOE=((1<<pin)|oeValue);
	}

	else if(strncmp(direction,"in",2)==0)//Checks to see if the user typed "out"
	{
		*gpioOE=~(~(oeValue)|(1<<pin));
	}
	else
	{
		printf("\n%s", "Error in gpiodirection: Selected Direction is invalid. Must be in or out");
		return -1;
	}


	close(fd);
	return 0;
}


