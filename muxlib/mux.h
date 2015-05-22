/*
 * mux.h
 *
 *      Author: Christian Macias
 *      Description: This Library contains all the functions necessary to edit and read the pin mux
 *      				current may not be extremely efficient but works perfectly.
 *      				I left room for expansion by adding a structure that you can add more to.
 */

/*
 * This header file looks scary but it's just defines the physical memory locations
 * of the control register that will control the pin mux and control registers.
 */


#ifndef MUX_H_
#define MUX_H_

#include<stdio.h>

int initmux();//Must be run before any other funtion
void muxdone(void);//Releases any alocated memory and file descriptors
int chkpinmode(int header, int pin);//Checks the current mode of the pin.
/*
 * SetPinMode
 * 	Header: 8 or 9
 * 	Pin: Pin number on the header
 * 	Slew:  Fast (0) or Slow (1)
 * 	RX_Buffer: (0) Disable (1)Enable
 * 	PulUpDown: (0) Pull Down (1)Pull Up
 * 	PullEnable: (0)Enabled (1)Disabled
 * 	Mode: Mode 0-7 on the selected pin
 * 	To leave any of the parameters as they current are type a negative integer and they
 * 		will be left at their current value.
 */
int setpinmode(int header, int pin, int slew, int rx_Buffer, int pullUpDown, int pullEnable, int mode);

//Controle Module Base Address
#define BASE_ADDRESS 0x44E10000

//All the pinControl offsets for the P8 Header
#define M_P8_3 0x818
#define M_P8_4 0x81C
#define M_P8_5 0x808
#define M_P8_6 0x80C
#define M_P8_7 0x980
#define M_P8_8 0x894
#define M_P8_9 0x89C
#define M_P8_10 0x898
#define M_P8_11 0x834
#define M_P8_12 0x830
#define M_P8_13 0x824
#define M_P8_14 0x828
#define M_P8_15 0x83C
#define M_P8_16 0x838
#define M_P8_17 0x82C
#define M_P8_18 0x88C
#define M_P8_19 0x820
#define M_P8_20 0x884
#define M_P8_21 0x880
#define M_P8_22 0x814
#define M_P8_23 0x810
#define M_P8_24 0x804
#define M_P8_25 0x800
#define M_P8_26 0x87C
#define M_P8_27 0x8E0 //LCD Registers begin here. BE CAREFUL. Editing these may mess up HDMI output.
#define M_P8_28 0x8E8
#define M_P8_29 0x8E4
#define M_P8_30 0x8EC
#define M_P8_31 0x8D8
#define M_P8_32 0x8DC
#define M_P8_33 0x8D4
#define M_P8_34 0x8CC
#define M_P8_35 0x8D0
#define M_P8_36 0x8C8
#define M_P8_37 0x8C0
#define M_P8_38 0x8C4
#define M_P8_39 0x8B8
#define M_P8_40 0x8BC
#define M_P8_41 0x8B0
#define M_P8_42 0x8B4
#define M_P8_43 0x8A8
#define M_P8_44 0x8AC
#define M_P8_45 0x8A0
#define M_P8_46 0x8A4


//All the pinControl offsets for the P9 Header
#define M_P9_11 0x870
#define M_P9_12 0x878
#define M_P9_13 0x874
#define M_P9_14 0x848
#define M_P9_15 0x840
#define M_P9_16 0x84C
#define M_P9_17 0x95C
#define M_P9_18 0x958
#define M_P9_19 0x97C
#define M_P9_20 0x978
#define M_P9_21 0x954
#define M_P9_22 0x950
#define M_P9_23 0x844
#define M_P9_24 0x974
#define M_P9_25 0x9AC
#define M_P9_26 0x980
#define M_P9_27 0x9A4
#define M_P9_28 0x99C
#define M_P9_29 0x994
#define M_P9_30 0x998
#define M_P9_31 0x990

typedef struct pinMuxAddress
{	/*
	 * I Know.. the structure is huge and it takes a crap load of memory but it attacking
	 * this with brute force until i have it up and running.
	 */
	volatile void *baseAddress;
	volatile unsigned int *p8_3;
	volatile unsigned int *p8_4;
	volatile unsigned int *p8_5;
	volatile unsigned int *p8_6;
	volatile unsigned int *p8_7;
	volatile unsigned int *p8_8;
	volatile unsigned int *p8_9;
	volatile unsigned int *p8_10;
	volatile unsigned int *p8_11;
	volatile unsigned int *p8_12;
	volatile unsigned int *p8_13;
	volatile unsigned int *p8_14;
	volatile unsigned int *p8_15;
	volatile unsigned int *p8_16;
	volatile unsigned int *p8_17;
	volatile unsigned int *p8_18;
	volatile unsigned int *p8_19;
	volatile unsigned int *p8_20;
	volatile unsigned int *p8_21;
	volatile unsigned int *p8_22;
	volatile unsigned int *p8_23;
	volatile unsigned int *p8_24;
	volatile unsigned int *p8_25;
	volatile unsigned int *p8_26;
	volatile unsigned int *p8_27;
	volatile unsigned int *p8_28;
	volatile unsigned int *p8_29;
	volatile unsigned int *p8_30;
	volatile unsigned int *p8_31;
	volatile unsigned int *p8_32;
	volatile unsigned int *p8_33;
	volatile unsigned int *p8_34;
	volatile unsigned int *p8_35;
	volatile unsigned int *p8_36;
	volatile unsigned int *p8_37;
	volatile unsigned int *p8_38;
	volatile unsigned int *p8_39;
	volatile unsigned int *p8_40;
	volatile unsigned int *p8_41;
	volatile unsigned int *p8_42;
	volatile unsigned int *p8_43;
	volatile unsigned int *p8_44;
	volatile unsigned int *p8_45;
	volatile unsigned int *p8_46;

	volatile unsigned int *p9_11;
	volatile unsigned int *p9_12;
	volatile unsigned int *p9_13;
	volatile unsigned int *p9_14;
	volatile unsigned int *p9_15;
	volatile unsigned int *p9_16;
	volatile unsigned int *p9_17;
	volatile unsigned int *p9_18;
	volatile unsigned int *p9_19;
	volatile unsigned int *p9_20;
	volatile unsigned int *p9_21;
	volatile unsigned int *p9_22;
	volatile unsigned int *p9_23;
	volatile unsigned int *p9_24;
	volatile unsigned int *p9_25;
	volatile unsigned int *p9_26;
	volatile unsigned int *p9_27;
	volatile unsigned int *p9_28;
	volatile unsigned int *p9_29;
	volatile unsigned int *p9_30;
	volatile unsigned int *p9_31;
}pinMux;


extern int fdMux;
extern pinMux pins;
extern pinmode(int header ,int pin);//Returns pin mode NO ERROR CHECKING

/*
 * If you dont want errors going to the text console, you can define a path for a log
 * file to go to. This will create the file. Make sure the program can access because if
 * it cant the program will give strange results.
 */
#define ERRORLOG "stderr"
extern FILE * errLog;


#endif /* MUX_H_ */
