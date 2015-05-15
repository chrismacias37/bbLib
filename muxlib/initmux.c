/*
 * initmux.c
 *
 *  Created on: May 14, 2015
 *      Author: christian
 */
#include<fcntl.h>
#include<sys/mman.h>
#include"mux.h"

/*
 * This function will allocate the virtual memory and assign it to each individual pin.
 * This will allow the functions to know where the memory is located and edit the registers.
 * WARNING: This is a huge file! It just sets the base address and uses offsets to determine the addresses
 * 	should you need to edit an offset or a base address, do so in the header file.
 */

int fdMux=0;
pinMux pins; //This is in the header file with extern. All functions may read this structure.

int initmux()
{
	if(pins.baseAddress!=0)
	{
		fprintf(stderr,"\n%s", "Error in: initmux - addresses are already allocated! ");
		return -1;
	}
	else
	{
		fdMux=open("/dev/mem", O_RDWR);
		pins.baseAddress=mmap(0, 128000,PROT_READ|PROT_WRITE, MAP_SHARED, fdMux, 0x44E10000);
	}

	if(pins.baseAddress==MAP_FAILED)
	{
		fprintf(stderr, "\n%s", "Error in: initmux - Could not set up base address. Running as root?");
		return -1;
	}

	/*
	 * AAAAAAaaand here begins the lengthy part...of setting the ofsets
	 */
	pins.p8_3=pins.baseAddress+M_P8_3;
	pins.p8_4=pins.baseAddress+M_P8_4;
	pins.p8_5=pins.baseAddress+M_P8_5;
	pins.p8_6=pins.baseAddress+M_P8_6;
	pins.p8_7=pins.baseAddress+M_P8_7;
	pins.p8_8=pins.baseAddress+M_P8_8;
	pins.p8_9=pins.baseAddress+M_P8_9;
	pins.p8_10=pins.baseAddress+M_P8_10;
	pins.p8_11=pins.baseAddress+M_P8_11;
	pins.p8_12=pins.baseAddress+M_P8_12;
	pins.p8_13=pins.baseAddress+M_P8_13;
	pins.p8_14=pins.baseAddress+M_P8_14;
	pins.p8_15=pins.baseAddress+M_P8_15;
	pins.p8_16=pins.baseAddress+M_P8_16;
	pins.p8_17=pins.baseAddress+M_P8_17;
	pins.p8_18=pins.baseAddress+M_P8_18;
	pins.p8_19=pins.baseAddress+M_P8_19;
	pins.p8_20=pins.baseAddress+M_P8_20;
	pins.p8_21=pins.baseAddress+M_P8_21;
	pins.p8_22=pins.baseAddress+M_P8_22;
	pins.p8_23=pins.baseAddress+M_P8_23;
	pins.p8_24=pins.baseAddress+M_P8_24;
	pins.p8_25=pins.baseAddress+M_P8_25;
	pins.p8_26=pins.baseAddress+M_P8_26;
	pins.p8_27=pins.baseAddress+M_P8_27;
	pins.p8_28=pins.baseAddress+M_P8_28;
	pins.p8_29=pins.baseAddress+M_P8_29;
	pins.p8_30=pins.baseAddress+M_P8_30;
	pins.p8_31=pins.baseAddress+M_P8_31;
	pins.p8_32=pins.baseAddress+M_P8_32;
	pins.p8_33=pins.baseAddress+M_P8_33;
	pins.p8_34=pins.baseAddress+M_P8_34;
	pins.p8_35=pins.baseAddress+M_P8_35;
	pins.p8_36=pins.baseAddress+M_P8_36;
	pins.p8_37=pins.baseAddress+M_P8_37;
	pins.p8_38=pins.baseAddress+M_P8_38;
	pins.p8_39=pins.baseAddress+M_P8_39;
	pins.p8_40=pins.baseAddress+M_P8_40;
	pins.p8_41=pins.baseAddress+M_P8_41;
	pins.p8_42=pins.baseAddress+M_P8_42;
	pins.p8_43=pins.baseAddress+M_P8_43;
	pins.p8_44=pins.baseAddress+M_P8_44;
	pins.p8_45=pins.baseAddress+M_P8_45;
	pins.p8_46=pins.baseAddress+M_P8_46;

	//Now the P9 Header...
	pins.p9_11=pins.baseAddress+M_P9_11;
	pins.p9_12=pins.baseAddress+M_P9_12;
	pins.p9_13=pins.baseAddress+M_P9_13;
	pins.p9_14=pins.baseAddress+M_P9_14;
	pins.p9_15=pins.baseAddress+M_P9_15;
	pins.p9_16=pins.baseAddress+M_P9_16;
	pins.p9_17=pins.baseAddress+M_P9_17;
	pins.p9_18=pins.baseAddress+M_P9_18;
	pins.p9_19=pins.baseAddress+M_P9_19;
	pins.p9_20=pins.baseAddress+M_P9_20;
	pins.p9_21=pins.baseAddress+M_P9_21;
	pins.p9_22=pins.baseAddress+M_P9_22;
	pins.p9_23=pins.baseAddress+M_P9_23;
	pins.p9_24=pins.baseAddress+M_P9_24;
	pins.p9_25=pins.baseAddress+M_P9_25;
	pins.p9_26=pins.baseAddress+M_P9_26;
	pins.p9_27=pins.baseAddress+M_P9_27;
	pins.p9_28=pins.baseAddress+M_P9_28;
	pins.p9_29=pins.baseAddress+M_P9_29;
	pins.p9_30=pins.baseAddress+M_P9_30;
	pins.p9_31=pins.baseAddress+M_P9_31;



	return 0;
}
