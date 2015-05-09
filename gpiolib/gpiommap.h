/*
 * gpiommap.h
 *
 *  Created on: Apr 28, 2015
 *      Author: Christian Macias
 *      Description: GPIO Memory Mapping Header File
 */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#ifndef GPIOMMAP_H_
#define GPIOMMAP_H_

//The following are the physical base address to the GPIO banks in memory
#define GPIO0BASE 0x44E07000
#define GPIO1BASE 0x4804C000
#define GPIO2BASE 0x481AC000
#define GPIO3BASE 0x481AE000

/*	The following are the offsets used to edit each pin register
 * 		The offsets are the same for all the GPIO banks
 */
#define GPIOOE 0x134 //GPIO Output Enabled Register
#define GPIODATIN 0x138 //GPIO's input data. READ ONLY
#define GPIODATOUT 0x13C //GPIO's output data.
#define GPIOCLRDATOUT 0x190 //Turn off the gpio for selected pin
#define GPIOSETDATOUT 0x194 //Turn on the gpio for selected pin

typedef struct gpioProperties
{
	volatile void *baseAddress;//Will store the virtual base memory address
	volatile int *outputEnable;//Will be the base + OE GPIOOE
	volatile int *dataIn;//Same operation Base + OFFSET
	volatile int *dataOut;//Same operation Base + OFFSET
	volatile int *clearDataOut;//Same operation Base + OFFSET
	volatile int *setDataOut;//Same operation Base + OFFSET
	int fd;//File descriptor. All of the structs created will have the same value here.

}gpioBank;

gpioBank *gpioinit(int bank);//Sets the address to the gpioBanks.
int gpioDone(gpioBank *);//Clears the allocated memory.
int gpiodirection(gpioBank *bank, int pin, char *direction);//Sets GPIO Direction
int gpioRead(gpioBank *bank, int pin);//Reads GPIO if input
int gpiowrite(gpioBank *bank, int pin, int value);//Write a value to GPIO

extern int openGpioBanks; //Stores how many gpio banks are opened. Declared in the first run of gpioinit


#endif /* GPIOMMAP_H_ */
