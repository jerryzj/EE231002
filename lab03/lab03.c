/*EE231002 Lab03 Roman Numerals
  103061232,張簡崇堯
  DATE:2014.10.6
*/
                                                                                                                                          
#include <stdio.h>

int main (void)                           //program start
{
	int innum,n4,n3,n2,n1;                //declare variables
	
	printf ("Input an integer between 1 and 3000: ");//ask for input number
	scanf("%d",&innum);                   //store input number at innum
	                                      //then separate innum into 4 groups
	n4=innum/1000;                        //take 4_digit group
	innum =innum%1000;                    //redefine innum
	n3=innum/100;                         //take 3_digit group
	innum =innum%100;                     //redefine innum
	n2=innum/10;                          //take 2_digit group
	innum =innum%10;                      //redefine innum
	n1=innum;                             //take 1_digit group

	switch (n4) {                         //in 4 digit group,choose 
	case 3: printf("MMM");   break;       //which case to print
	case 2: printf("MM");    break;		  
	case 1: printf("M");     break;		  
	}
	switch (n3) {                         //in 3 digit group,choose
	case 9:printf("CM");     break;		  //which case to print
	case 8:printf("DCCC");   break;       
	case 7:printf("DCC");    break;		  
	case 6:printf("DC");     break;		  
	case 5:printf("D");      break;		  
	case 4:printf("CD");     break;		  
	case 3:printf("CCC");    break;		  
	case 2:printf("CC");     break;		  
	case 1:printf("C");      break;		  
	}
	switch (n2) {						  //in 2 digit group.choose
	case 9:printf("XC");     break; 	  //which case to print
	case 8:printf("LXXX");   break;		  
	case 7:printf("LXX");    break;		  
	case 6:printf("LX");     break;		  
	case 5:printf("L");      break;		  
	case 4:printf("XL");     break;		  
	case 3:printf("XXX");    break;		  
	case 2:printf("XX");     break;		  
	case 1:printf("X");      break;		  
	}
	switch (n1) {						  //in 1 digit group,choose
    case 9:printf("IX\n");   break;		  //which case to print
    case 8:printf("VIII\n"); break;		  
    case 7:printf("VII\n");  break;		  
    case 6:printf("VI\n");   break;		  
    case 5:printf("V\n");    break;		  
    case 4:printf("IV\n");   break;		  
    case 3:printf("III\n");  break;		  
    case 2:printf("II\n");   break;		  
    case 1:printf("I\n");    break;		  
    case 0:printf("\n");     break;       
    }
	return 0;							  //program end
}
