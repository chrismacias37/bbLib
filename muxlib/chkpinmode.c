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
	int mode=-1;

	if(header<8 || header>9)
	{//Error Check
		fprintf(errLog,"Error in chkpinmode(): Selected header is out of range.");
		return mode;
	}
	else if(pin<3 || pin > 46)
	{//Error Check
		fprintf(errLog,"Error in chkpinmode(): Selected pin is out of range.");
		return mode;
	}

	if(header==8)
	{//Looks for the Pin on the P8 header and returns the mode
	   switch(pin)
	   {
	   case 3: return((*pins.p8_3)&7); break;
	   case 4: return((*pins.p8_4)&7); break;
	   case 5: return((*pins.p8_5)&7); break;
	   case 6: return((*pins.p8_6)&7); break;
	   case 7: return((*pins.p8_7)&7); break;
	   case 8: return((*pins.p8_8)&7); break;
	   case 9: return((*pins.p8_9)&7); break;
	   case 10: return((*pins.p8_10)&7); break;
	   case 11: return((*pins.p8_11)&7); break;
	   case 12: return((*pins.p8_12)&7); break;
	   case 13: return((*pins.p8_13)&7); break;
	   case 14: return((*pins.p8_14)&7); break;
	   case 15: return((*pins.p8_15)&7); break;
	   case 16: return((*pins.p8_16)&7); break;
	   case 17: return((*pins.p8_17)&7); break;
	   case 18: return((*pins.p8_18)&7); break;
	   case 19: return((*pins.p8_19)&7); break;
	   case 20: return((*pins.p8_20)&7); break;
	   case 21: return((*pins.p8_21)&7); break;
	   case 22: return((*pins.p8_22)&7); break;
	   case 23: return((*pins.p8_23)&7); break;
	   case 24: return((*pins.p8_24)&7); break;
	   case 25: return((*pins.p8_25)&7); break;
	   case 26: return((*pins.p8_26)&7); break;
	   case 27: return((*pins.p8_27)&7); break;
	   case 28: return((*pins.p8_28)&7); break;
	   case 29: return((*pins.p8_29)&7); break;
	   case 30: return((*pins.p8_30)&7); break;
	   case 31: return((*pins.p8_31)&7); break;
	   case 32: return((*pins.p8_32)&7); break;
	   case 33: return((*pins.p8_33)&7); break;
	   case 34: return((*pins.p8_34)&7); break;
	   case 35: return((*pins.p8_35)&7); break;
	   case 36: return((*pins.p8_36)&7); break;
	   case 37: return((*pins.p8_37)&7); break;
	   case 38: return((*pins.p8_38)&7); break;
	   case 39: return((*pins.p8_39)&7); break;
	   case 40: return((*pins.p8_40)&7); break;
	   case 41: return((*pins.p8_41)&7); break;
	   case 42: return((*pins.p8_42)&7); break;
	   case 43: return((*pins.p8_43)&7); break;
	   case 44: return((*pins.p8_44)&7); break;
	   case 45: return((*pins.p8_45)&7); break;
	   case 46: return((*pins.p8_46)&7); break;
	   default: fprintf(errLog, "\n%s%i%s", "Error in chkpinmode(): pin ", pin, " on the P8 header is unavailable"); break;


	   }//switch(pin)

	}//if(header==8)

	if(header==9)
	{
		switch(pin)
		{
		case 11: return((*pins.p9_11)&7); break;
		case 12: return((*pins.p9_12)&7); break;
		case 13: return((*pins.p9_13)&7); break;
		case 14: return((*pins.p9_14)&7); break;
		case 15: return((*pins.p9_15)&7); break;
		case 16: return((*pins.p9_16)&7); break;
		case 17: return((*pins.p9_17)&7); break;
		case 18: return((*pins.p9_18)&7); break;
		case 19: return((*pins.p9_19)&7); break;
		case 20: return((*pins.p9_20)&7); break;
		case 21: return((*pins.p9_21)&7); break;
		case 22: return((*pins.p9_22)&7); break;
		case 23: return((*pins.p9_23)&7); break;
		case 24: return((*pins.p9_24)&7); break;
		case 25: return((*pins.p9_25)&7); break;
		case 26: return((*pins.p9_26)&7); break;
		case 27: return((*pins.p9_27)&7); break;
		case 28: return((*pins.p9_28)&7); break;
		case 29: return((*pins.p9_29)&7); break;
		case 30: return((*pins.p9_30)&7); break;
		case 31: return((*pins.p9_31)&7); break;
		default: fprintf(errLog, "\n%s%i%s", "Error in chkpinmode(): pin ", pin, " on the P9 header is unavailable"); break;

		}//switch(pin)
	}//if(header==9)


	return mode;
}
