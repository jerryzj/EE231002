/*EE231002 Lab05 Blackjack and Expected Values
  103061232,Chong-yao,Zhang Jian
  DATE:2014.10.20 
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10000
int main (void)
{
	int i,hand,k ;                        //declare variables
	float handf,busted,E;                 //...

	printf("Points  E(hit)  %% Busted\n");//print title
	for(hand = 2;hand < 21;hand++){       //
		handf = 0;                        //reset handf
		busted = 0;                       //reset busted
		for(i = 1;i <= N;i++){			  //test for 10000 times
			k = rand() % 13 + 1;		  //generate a random number as a card
	    	if (k >=10)					  //follow the rule,set J Q K card
			k = 10;						  //value = 10
			else if (hand <= 10 && k== 1) //set A card can be either 1 or 11
			k = 11;						  
			if (hand + k > 21) busted++;  //record busted times
			handf += hand + k;			  //record final points
			E = handf / N;				  //count expected value 
			}
		busted = busted * 100 / N;		  //count possibility of being busted 
		printf("%4d%10.2f%9.4g\n",hand,E,busted);//show result
	}
	return 0;							  //the end
}

