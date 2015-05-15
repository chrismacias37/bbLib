/*
 * gpioWrite.c
 *
 *  Created on: Apr 30, 2015
 *      Author: christian
 */
#include"gpiommap.h"


int gpiowrite(gpioBank *bank, int pin, int value)
{

		//Removed because of the addition of gpioinit.c
//		switch(bank)//Seems much more efficient and cleaner to write...
//		{
//		case 0: gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO0BASE); break;//Sets the base address depending on what the user selected
//		case 1: gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO1BASE); break;
//		case 2: gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO2BASE); break;
//		case 3: gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO3BASE); break;
//		}


		//Commented to test out gpioInit and swtich statement(Which is now commented out)
//		if(bank==0)//will check the which gpio bank is selected and allocate the memory and return the address
//		{
//			gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO0BASE);
//		}
//		if(bank==1)
//		{
//			gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO1BASE);
//		}
//		if(bank==2)
//		{
//			gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO2BASE);
//		}
//		if(bank==3)
//		{
//			gpioBaseAddress=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO3BASE);
//		}
//		if(bank>3 || bank<0)//ERROR CHECK
//		{
//			fprintf(stderr, "\n%s", "Error in gpioWrite: Bank Selected is out of range. Must be 0, 1, 2, or 3");
//			fflush(stderr);
//			return -1;
//		}
//		if(pin>31 || pin < 0)//ERROR CHECK
//		{
//			fprintf(stderr,"\n%s", "Error in gpioWrite: Pin selected is out of range. Must be 0-31");
//			fflush(stderr);
//			return -1;
//		}

		//Sets the memory addresses. No longer needed because of gpioinit
//		gpioWriteSet=gpioAddress[bank]+GPIOSETDATOUT;
//		gpioWriteClear=gpioAddress[bank]+GPIOCLRDATOUT;

		if(value==0)
		{
			//write 1 to the clear register
			*(bank->clearDataOut)=(1<<pin);
		}

		if(value==1)
		{
			//write 1 to the set register
			*(bank->setDataOut)=(1<<pin);
		}

	return 0;
}
