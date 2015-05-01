/*
 * gpioWrite.c
 *
 *  Created on: Apr 30, 2015
 *      Author: christian
 */
#include <stdio.h>
#include <stdlib.h>
#include<fcntl.h>
#include"gpiommap.h"


int gpiowrite(int bank, int pin, int value)
{
		int fd=open("/dev/mem", O_RDWR);//file descriptor
		volatile void *gpioBaseAddress=NULL;//Allocated memory for the address's
		unsigned volatile int *gpioWriteSet=NULL;
		unsigned volatile int *gpioWriteClear=NULL;
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
			fprintf(stderr, "\n%s", "Error in gpioWrite: Bank Selected is out of range. Must be 0, 1, 2, or 3");
			fflush(stderr);
			return -1;
		}
		if(pin>31 || pin < 0)//ERROR CHECK
		{
			fprintf(stderr,"\n%s", "Error in gpioWrite: Pin selected is out of range. Must be 0-31");
			fflush(stderr);
			return -1;
		}
		//Sets the memory addresses
		gpioWriteSet=gpioBaseAddress+GPIOSETDATOUT;
		gpioWriteClear=gpioBaseAddress+GPIOCLRDATOUT;

		if(value==0)
		{
			//write 1 to the clear register
			gpioWriteClear=(1<<pin);
		}

		if(value==1)
		{
			gpioWriteSet=(1<<pin);
		}


		//Clear all the memory address
		gpioWriteSet=NULL;
		gpioWriteClear=NULL;
		munmap(gpioBaseAddress, 4096);

	return 0;
}
