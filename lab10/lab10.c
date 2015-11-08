/*EE231002 Lab10 Poker Hands
  103061232.Chong-yao,Zhang Jian
  DATE:2014.11.24
*/

#include <stdio.h>
#include <stdlib.h>
#define S 10000000

void givecards(int suit[5],int number[5]);
void analyze(int suit[5],int number[5],double result[9]);
int PAIR(int number[5]);
int FLUSH(int suit[5]);
int STRAIGHT(int number[5]);
void print(double result[9]);
/*use number 1~4 to represent suit
  0:Club 1:Diamonnd 2:Heart 3:Spade	
*/

int main (void){
	int suit[5],number[5],i,j;
	double result[9];
	
	for(i=0;i<S;i++){
		givecards(suit,number);
		analyze(suit,number,result);
	}
	print(result);

	return 0;
}

void givecards(int suit[5],int number[5]){
	int i,j,check,temp[5]={},tmp1,tmp2;

	for(i=0;i<5;){
		temp[i]=rand()%52;
		check=0;
		for(j=0;j<i;j++){
			if(temp[i]==temp[j]){
				j=i;	check=1;	
			}
		}
		if(check==0) i++;
	}
	for(i=0;i<5;i++){
		tmp1=temp[i]/13;
		tmp2=temp[i]%13;
		switch (tmp1){
			case 0: 
				suit[i]=tmp1;
				number[i]=tmp2;
				break;
			case 1:
				suit[i]=tmp1;
				number[i]=tmp2;
				break;
			case 2:
				suit[i]=tmp1;
				number[i]=tmp2;
				break;
			case 3:
				suit[i]=tmp1;
				number[i]=tmp2;
				break;
		}
	}
}

void analyze(int suit[5],int number[5],double result[9]){
	int i,j,pair,flush,straight;
	
	pair=PAIR(number);
	flush=FLUSH(suit);
	straight=STRAIGHT(number);	
	switch (pair){
		case 1:
		case 2:
		case 3: result[pair]++; break;
    	case 4: result[6]++	; break;
    	case 6: result[7]++	; break; 
    	default: switch(10*flush+straight){
        		 	case 11: result[8]++; break;
              		case  1: result[4]++; break;
              		case 10: result[5]++; break;
              		default: result[0]++;
				 }	
	}
}
	
int PAIR(int number[5]){
	int i,j,pair=0;
	for(i=0; i < 5; i++){
	   for(j=i+1; j < 5; j++){
	       if((number[i]-number[j])==0) pair++;
		   
	}
	return pair;
}	

int FLUSH(int suit[5]){
	int i,check,flush=0;

	for(i=0;i<4;i++){
		check=1;
		if(suit[i] !=suit[i+1]){
			check=0;	i=4;
		}
	}	
	if(check==1) flush++;
	return flush;
}	
	
int STRAIGHT(int number[5]){
	int i,j,temp,sum=0,straight=0;
	for(i=4;i>0; i--) {
        for(j=0;j<i;j++) {
            if( number[j+1] < number[j] ) {
                temp = number[j];
                number[j] = number[j+1];
                number[j+1] = temp;
            }
        }
    
    }
	for(i=0;i<4;){
		if(number[i+1]==number[i]+1) i++;
		else return straight; 
	}
	straight++;
	return straight;
}	

void print(double result[9]){
	printf("Catogories      Probability\n");
	printf("Straight flush   %.4lf%%\n",result[8]/(S/100));
	printf("Four of a kind   %.4lf%%\n",result[7]/(S/100));
	printf("Full house       %.4lf%%\n",result[6]/(S/100));
	printf("Flush            %.4lf%%\n",result[5]/(S/100));
	printf("Straight         %.4lf%%\n",result[4]/(S/100));
	printf("Three of a kind  %.4lf%%\n",result[3]/(S/100));
	printf("Two pair         %.4lf%%\n",result[2]/(S/100));
	printf("One pair         %.3lf%%\n",result[1]/(S/100));
	printf("High Card        %.3lf%%\n",result[0]/(S/100));
}
