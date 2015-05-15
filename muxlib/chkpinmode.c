/*
 * chkpinmode.c
 *
 *  Created on: May 10, 2015
 *      Author: christian
 */
#include<sys/mman.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include"mux.h"

int chkpinmode(int header, int pin)
{
	/*
	 * WARNING: This piece of code has no error checking yet!
	 */
	//Calculations...
	int pinoffset=0;

	if(header==8)
	{//byte offset
		pinoffset=((pin-2)*8);//This get very program specific so DONT NOT EDIT THE pins STRUCTURE
	}
	else if(header==9)
	{//byte offset
		pinoffset=( (44 * 8)+( pin - 11 ) * 8 );//Defines at what point to look at the structure
	}
	char * pinConf=(char *)(&pins+pinoffset);//No need to worry about padding because structure is made up of pointers
	int pinConfValue=(int)*pinConf;

	int mode;

	mode=(int)(pinConfValue&7);//Checks one the first 3 bits
	mode=pinConfValue;

	return mode;
}
