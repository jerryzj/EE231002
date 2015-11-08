/*EE231002 Lab04 Consecutive Primes
  103061232,張簡崇堯
  DATE:2014.10.13
*/

#include <stdio.h>
#define max 600000

int main (void)                         //program start
{
	int n,prime = 3,count = 1;          //declare variables

	if(prime=3)printf("Consecutive primes #%d: %d, %d\n",count++,prime,prime+2); 
	for(;prime <= max;prime+=2){        //use if to eliminite error when prime=3
		for(n = 2;n * n < prime;n++){   //judge whether a number is prime or not
			if(prime % n == 0 || (prime+2) % n ==0)break;
			else if ((n+1) * (n+1) > prime && (n+1) * (n+1) !=prime+2)
			printf("Consecutive primes #%d: %d, %d\n",count++,prime,prime+2);
			                           //show result
		}
	}
	return 0;                          //program end
}

















