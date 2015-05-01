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
	int bank;
	int pin;
	char direction[5];
	int errorCheck;
	int loop=1;
	int pinValue;

	system("clear");
	printf("%s\n", "What GPIO bank do you wish to set as input or output? 0, 1, 2, or 3: ");
	fflush(stdout);
	fscanf(stdin, "%ui1", &bank);
	fflush(stdin);

	printf("\n%s\n", "What pin do you wish to edit the value of? 0-31: ");
	fflush(stdout);
	fscanf(stdin,"%ui2", &pin);
	fflush(stdin);

	printf("\n%s\n", "What direction do you wish to make this pin? in or out ");
	fflush(stdout);
	fscanf(stdin,"%s3", direction);
	fflush(stdin);

	printf("\n%s\n", "Here is what you typed");
	printf("\n%s%u\n", "Bank:", bank);
	printf("\n%s%u\n", "Pin:", pin);
	printf("\n%s%s\n", "Direction:", direction);

	errorCheck=gpiodirection(bank, pin, direction);
	if(errorCheck==-1)
	{
		fprintf(stderr,"\n%s\n", "Error changing direction pin.");
		return -1;
	}
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
	return 0;
}
