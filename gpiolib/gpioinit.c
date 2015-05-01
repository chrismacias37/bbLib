/*
 * gpioinit.c
 *
 *  Created on: May 1, 2015
 *      Author: christian
 */
#include<sys/mman.h>
#include"gpiommap.h"


int gpioinit(void)
{
	int fd;
	int counter=0;
	fd=open("/dev/mem",O_RDWR);
	gpioAddress[0]=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO0BASE);
	gpioAddress[1]=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO1BASE);
	gpioAddress[2]=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO2BASE);
	gpioAddress[3]=mmap(0, 4096, PROT_READ | PROT_WRITE , MAP_SHARED, fd, GPIO3BASE);

	while(counter<3)
	{
		if(gpioAddress[counter]==MAP_FAILED)
		{
			printf("\n%s%i", "Could not initialize gpio bank: " , counter);
		}
	}
	return 0;
}
