/*
 * setpinmode.c
 *
 *  Created on: May 16, 2015
 *      Author: christian
 */




#include"mux.h"

volatile unsigned int *ctrlpinaddress(int header, int pin);
/*
 * Sets the desired values, Put a negative integer here to keep whatever value is already stores in the register.
 */
int setpinmode(int header, int pin, int slew, int rx_Buffer, int pullUpDown, int pullEnable, int mode)
{
	unsigned int controlPadValue;

	volatile unsigned int *pinsAddress = ctrlpinaddress(header, pin);

	controlPadValue=*(pinsAddress);//Save the current Value
	//Sets the slew rate
	if(slew==1)
	{
		controlPadValue=controlPadValue|(1<<6);
	}
	else if(slew==0)
	{
		controlPadValue=~(~controlPadValue|(1<<6));
	}

	//sets the rx_Buffer
	if(rx_Buffer==1)
	{
		controlPadValue=controlPadValue|(1<<5);
	}
	else if(rx_Buffer==0)
	{
		controlPadValue=~(~controlPadValue|(1<<5));
	}

	if(pullUpDown==1)
	{
		controlPadValue=controlPadValue|(1<<4);
	}
	else if(pullUpDown==0)
	{
		controlPadValue=~(~controlPadValue|(1<<4));
	}

	if(pullEnable==1)
	{
		controlPadValue=controlPadValue|(1<<3);
	}
	else if(pullEnable==0)
	{
		controlPadValue=~(~controlPadValue|(1<<3));
	}

	switch(mode)
	{
	case 0: controlPadValue=~(~controlPadValue|7); break;
	case 1: controlPadValue=~(~controlPadValue|7)|(1); break;
	case 2: controlPadValue=~(~controlPadValue|7)|(2); break;
	case 3: controlPadValue=~(~controlPadValue|7)|(3); break;
	case 4: controlPadValue=~(~controlPadValue|7)|(4); break;
	case 5: controlPadValue=~(~controlPadValue|7)|(5); break;
	case 6: controlPadValue=~(~controlPadValue|7)|(6); break;
	case 7: controlPadValue=~(~controlPadValue|7)|(7); break;
	}
	//printf("\n%s%i", "control pad value", controlPadValue);

	*pinsAddress=controlPadValue;
	return -1;
}

volatile unsigned int *ctrlpinaddress(int header, int pin)
{
	if(header==8)
	{//Looks for the Pin on the P8 header and returns the mode
	   switch(pin)
	   {
	   case 3: return(pins.p8_3); break;
	   case 4: return((pins.p8_4)); break;
	   case 5: return((pins.p8_5)); break;
	   case 6: return((pins.p8_6)); break;
	   case 7: return((pins.p8_7)); break;
	   case 8: return((pins.p8_8)); break;
	   case 9: return((pins.p8_9)); break;
	   case 10: return((pins.p8_10)); break;
	   case 11: return((pins.p8_11)); break;
	   case 12: return((pins.p8_12)); break;
	   case 13: return((pins.p8_13)); break;
	   case 14: return((pins.p8_14)); break;
	   case 15: return((pins.p8_15)); break;
	   case 16: return((pins.p8_16)); break;
	   case 17: return((pins.p8_17)); break;
	   case 18: return((pins.p8_18)); break;
	   case 19: return((pins.p8_19)); break;
	   case 20: return((pins.p8_20)); break;
	   case 21: return((pins.p8_21)); break;
	   case 22: return((pins.p8_22)); break;
	   case 23: return((pins.p8_23)); break;
	   case 24: return((pins.p8_24)); break;
	   case 25: return((pins.p8_25)); break;
	   case 26: return((pins.p8_26)); break;
	   case 27: return((pins.p8_27)); break;
	   case 28: return((pins.p8_28)); break;
	   case 29: return((pins.p8_29)); break;
	   case 30: return((pins.p8_30)); break;
	   case 31: return((pins.p8_31)); break;
	   case 32: return((pins.p8_32)); break;
	   case 33: return((pins.p8_33)); break;
	   case 34: return((pins.p8_34)); break;
	   case 35: return((pins.p8_35)); break;
	   case 36: return((pins.p8_36)); break;
	   case 37: return((pins.p8_37)); break;
	   case 38: return((pins.p8_38)); break;
	   case 39: return((pins.p8_39)); break;
	   case 40: return((pins.p8_40)); break;
	   case 41: return((pins.p8_41)); break;
	   case 42: return((pins.p8_42)); break;
	   case 43: return((pins.p8_43)); break;
	   case 44: return((pins.p8_44)); break;
	   case 45: return((pins.p8_45)); break;
	   case 46: return((pins.p8_46)); break;
	   default: fprintf(errLog, "\n%s%i%s", "Error in setpinmode(): pin ", pin, " on the P8 header is unavailable"); break;


	   }//switch(pin)
	}//if(header==8)

	if(header==9)
	{
		switch(pin)
		{
		case 11: return((pins.p9_11)); break;
		case 12: return((pins.p9_12)); break;
		case 13: return((pins.p9_13)); break;
		case 14: return((pins.p9_14)); break;
		case 15: return((pins.p9_15)); break;
		case 16: return((pins.p9_16)); break;
		case 17: return((pins.p9_17)); break;
		case 18: return((pins.p9_18)); break;
		case 19: return((pins.p9_19)); break;
		case 20: return((pins.p9_20)); break;
		case 21: return((pins.p9_21)); break;
		case 22: return((pins.p9_22)); break;
		case 23: return((pins.p9_23)); break;
		case 24: return((pins.p9_24)); break;
		case 25: return((pins.p9_25)); break;
		case 26: return((pins.p9_26)); break;
		case 27: return((pins.p9_27)); break;
		case 28: return((pins.p9_28)); break;
		case 29: return((pins.p9_29)); break;
		case 30: return((pins.p9_30)); break;
		case 31: return((pins.p9_31)); break;
		default: fprintf(errLog, "\n%s%i%s", "Error in setpinmode(): pin ", pin, " on the P9 header is unavailable"); break;

		}//switch(pin)
	}//if(header==9)
	return 0;

}//End pin Current Value
