/*EE2310002 Lab08 Deciphering Roman Numerals
  10306132.Chong-yao,Zhang Jian
  DATE:2014.11.11
*/
#include <stdio.h>

int main (void){
	char A[100];					   //use array to store input 	
	int i,count=0,result=0;			   

	printf("Input a Roman Numeral: "); //print prompt
	for(i=0;A[i-1]!='\n';i++,count++){ 
		scanf("%c",&A[i]);			   //scan input
		switch (A[i]){				   //use switch statement to determine	
		case 'I': result+=1;    break; //the value of input
		case 'V': result+=5;    break;
		case 'X': result+=10;   break;
		case 'L': result+=50;   break;
		case 'C': result+=100;  break;
		case 'D': result+=500;  break;
		case 'M': result+=1000; break;
		}
	}
	/*Use "for" loop to deal with exceptions*/
	for(i=0;i<count-1;i++){
		if      (A[i]=='I' && A[i+1]=='V') result-=2;  //deal with input IV      
		else if (A[i]=='I' && A[i+1]=='X') result-=2;  //deal with input IX
		else if (A[i]=='X' && A[i+1]=='L') result-=20; //deal with input XL
		else if (A[i]=='X' && A[i+1]=='C') result-=20; //deal with input XC
		else if (A[i]=='C' && A[i+1]=='D') result-=200;//deal with input CD
		else if (A[i]=='C' && A[i+1]=='M') result-=200;//deal with input CM
	}
	printf("The value is: %d\n",result);  //print final result
	return 0;                             //program end
}
