/*
 * gpioDirection.c
 *
 *  Created on: Apr 28, 2015
 *      Author: christian
 */

#include<string.h>
#include"gpiommap.h"



int gpiodirection(gpioBank *bank,int pin, char *direction)
{
	unsigned int oeValue;//Will store the Output Enable values


	oeValue=*(bank->outputEnable);//Saves the Output Enable Values


	if(strncmp(direction,"ou",2)==0)//Checks to see if the user typed "out"
	{
		*(bank->outputEnable)=(oeValue|(1<<pin));
	}

	else if(strncmp(direction,"in",2)==0)//Checks to see if the user typed "out"
	{
		*(bank->outputEnable)=oeValue&(~(1<<pin));
	}
	else
	{
		printf("\n%s", "Error in gpiodirection.c: Selected Direction is invalid. Must be in or out");
		return -1;
	}


	return 0;
}


