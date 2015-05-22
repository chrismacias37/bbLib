/*
 * testProgram.c
 *
 *  Created on: May 14, 2015
 *      Author: christian
 */
#include"mux.h"
#include<unistd.h>
#include<stdio.h>

int main(void)
{
	int check1=1;//Runs until there is an error
	int counter1=3;
	int counter2=11;
	int mode1Value8[46];//Store the Value
	int mode1Value9[46];//Store the Value
	int mode2Value8[46];//Store the Value
	int mode2Value9[46];//Store the Value

	initmux();

	while(counter1<=46&&check1==1)
	{

		mode1Value8[counter1-1]=chkpinmode(8,counter1);

		if(mode1Value8[counter1-1]==-1)
		{
			check1=0;//Stops program
			fprintf(stdout, "\n%s", "Error while reading pin mux value");
			fflush(stdout);
		}

		counter1++;
	}

	while(counter2<=31&&check1==1)
	{
		mode1Value9[counter2-1]=chkpinmode(9,counter2);
		if(mode1Value9[counter2-1]==-1)
		{
			check1=0;//Stops program
			fprintf(stdout, "\n%s", "Error while reading pin mux value");
			fflush(stdout);
		}
		counter2++;
	}

	while(check1==1)
	{
		counter1=3;

		while(counter1<=46&&check1==1)
		{
			mode2Value8[counter1-1]=chkpinmode(8,counter1);
			counter1++;
		}//End while(counter1<=46&&check1==1)
		counter1=3;

		while(counter1<=46&&check1==1)
		{
			if(mode1Value8[counter1-1]!=mode2Value8[counter1-1])
			{
				fprintf(stdout,"\n%s\n\t%s%i", "There was a change in the mux on", " Header: 8 Pin: ", counter1);
				fflush(stdout);
				fprintf(stdout, "\n%s%i%s%i", "The value mux value was: ", mode1Value8[counter1-1], ". The new value is: ", mode2Value8[counter1-1]);
				fflush(stdout);
				mode1Value8[counter1-1]=mode2Value8[counter1-1];
			}//END if
			counter1++;
			usleep(50000);
		}//END while(counter1<=46&&check1==1)
		counter1=3;

		counter2=11;

		while(counter2<=31&&check1==1)
		{
			mode2Value9[counter2-1]=chkpinmode(9,counter2);
			counter2++;
		}

		counter2=11;
		while(counter2<=31&&check1==1)
		{
			if(mode1Value9[counter2-1]!=mode2Value9[counter2-1])
			{
				fprintf(stdout,"\n%s\n\t%s%i", "There was a change in the mux on", " Header: 9 Pin: ", counter2);
				fflush(stdout);
				fprintf(stdout, "\n%s%i%s%i", "The value mux value was: ", mode1Value9[counter2-1], ". New value is: ", mode2Value9[counter2-1]);
				fflush(stdout);
				mode1Value9[counter2-1]=mode2Value9[counter2-1];
			}//END if
			usleep(50000);
			counter2++;
		}//END while(counter1<=46&&check1==1)
		counter2=11;
	}//End while(check1==1)

	muxdone();

return 0;
}
