/*
 * main.c
 *
 *  Created on: Apr 28, 2015
 *      Author: christian Macias
 *      Tests the functions
 */

#include <stdio.h>
#include <stdlib.h>
#include "gpiommap.h"

int main(void)
{
	int bankNumber;
	int pin;
	char direction[5];
	int errorCheck;
	int loop=1;
	int pinValue;
	int value;
	gpioBank *bank;//Creates the pointer that will hold the structure to store all the address for the gpio bank

	system("clear");
	printf("%s\n", "What GPIO bank do you wish to set as input or output? 0, 1, 2, or 3: ");
	fflush(stdout);
	fscanf(stdin, "%ui1", &bankNumber);
	fflush(stdin);

	printf("\n%s\n", "What pin do you wish to edit or read the value of? 0-31: ");
	fflush(stdout);
	fscanf(stdin,"%ui2", &pin);
	fflush(stdin);

	printf("\n%s\n", "What direction do you wish to make this pin? in or out ");
	fflush(stdout);
	fscanf(stdin,"%s3", direction);
	fflush(stdin);

	printf("\n%s\n", "Should the pin be high(1) or low(0) if output (Ignored it not)?: ");
	fflush(stdout);
	fscanf(stdin,"%ui2", &value);
	fflush(stdin);

	printf("\n%s", "Here is what you typed");
	printf("\n%s%u", "Bank:", bankNumber);
	printf("\n%s%u", "Pin:", pin);
	printf("\n%s%s", "Direction:", direction);
	printf("\n%s%u\n", "Value to write:", value);

	bank=gpioinit(bankNumber);
	gpiodirection(bank, pin, direction);

	if(strncmp("in",direction,2)==0)
	{
		pinValue=gpioRead(bank,pin);
		printf("\n%s%u","Current Value:", pinValue);
		while(loop==1)
		{
			printf("\n%s", "Would you like to read the value of the pin again? (1)Yes (0)No: ");
			scanf("%u1", &loop);
			pinValue=gpioRead(bank,pin);
			printf("\n%s%u","Current Value:", pinValue);
		}
	}
	if(strncmp("ou",direction,2)==0)
	{
		gpiowrite(bank, pin, value);
	}
	gpiodone(bank);//Don't forget to close the banks you aren't going to use.
	return 0;
}
