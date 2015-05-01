/*
 * gpiommap.h
 *
 *  Created on: Apr 28, 2015
 *      Author: Christian Macias
 *      Description: GPIO Memory Mapping Header File
 */

#include<stdio.h>
#include <sys/mman.h>
#include<fcntl.h>

#ifndef GPIOMMAP_H_
#define GPIOMMAP_H_

//The following are the base address to the GPIO banks
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

/*
 * This is an attempt to make the program more efficient. Ill be making a data structure to store the address of gpio addresses
 */

void volatile *gpioAddress[4];//Will store the address to the gpioBanks

int gpioinit();//Sets the address to the gpioBanks.
int gpioDone();//Clears the allocated memory.
int gpiodirection(int bank, int pin, char *direction);
int gpioRead(int bank, int pin);
int gpiowrite(int bank, int pin, int value);


#endif /* GPIOMMAP_H_ */
