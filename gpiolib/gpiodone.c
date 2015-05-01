/*
 * gpiodone.c
 *
 *  Created on: May 1, 2015
 *      Author: christian
 */


int gpioDone(void)
{
	int counter1;

	while (counter1<3)
	{
		munmap(gpioAddress[counter1] ,4096);
	}
	return 0;
}
