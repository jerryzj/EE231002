/*EE231002 Lab01 Unit Coversion
  103061232,ZHANG JIAN,CHONG-YAO
  DATE:2014.09.22
*/
#include <stdio.h>

int main (void)											//program start
																			
{	int m,f,i ;											//declare variables

	printf("Input length in meters: ");					//requst input
	scanf("%d",&m);										//read input value
	f=m*100/2.54/12;									//covert m into f
	i=m*100/2.54-f*12;									//covert m into i

	printf("Length in US customary units: %d feet %d inches\n",f,i );//show ans
	return 0;											//the end
}
																																									
