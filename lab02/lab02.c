/*EE231002 Lab02 Linear System Solutions
  103061232,張簡崇堯
  DATE:2014.09.22
*/
#include <stdio.h>	

int main (void)                                        //program start
{
	float a,b,c,d,e;                                   //define variables
	
	e=(2*19-46*3)/(2-9*3);                             //count e 
	d=(46-9*19)/(2-9*3);                               //count d  
	c=25-2*d-3*e;                                      //count c
	b=(50-3*c-4*d-5*e)/2;                              //count b
	a=(78-4*b-5*c-6*d-7*e)/3;                          //count a
    	
	printf("Solution:\n");                             //show result  
	printf("  a=%g b=%g c=%g d=%g e=%g\n",a,b,c,d,e);  //show result 
	printf("Verification:\n");                         //start verification
	printf("  3a+ 4b+ 5c+ 6d+ 7e= %g\n",3*a+4*b+5*c+6*d+7*e);   //...
	printf("      2b+ 3c+ 4d+ 5e= %g\n",2*b+3*c+4*d+5*e);       //...
	printf("           c+ 2d+ 3e= %g\n",c+2*d+3*e);             //...
	printf("              2d+ 9e= %g\n",2*d+9*e);               //...
	printf("              3d+  e= %g\n",3*d+e);                 //...
	return 0;                                          //program end
}	
