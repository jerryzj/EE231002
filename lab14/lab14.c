/*EE231002 lab14 Linked lists
  103061232.Chong-yao,Zhang Jian
  DATE:2014.12.15
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct factor{		// node for a prime factor
	int prime;				// prime factor
	int power;				// associated power
	struct factor *next;	// pointer for the next prime factor
}FACTOR;

/*Function Declarations
factorize:to do prime factor decomposition
GCD:find greatest common divisor of 2 input numbers
LCM:find least common multiple of 2 input numbers
write:print calculation process
compute:doing calculation
*/
FACTOR *factorize(int N);
FACTOR *GCD(FACTOR *A,FACTOR *B);
FACTOR *LCM(FACTOR *A,FACTOR *B);
void write(FACTOR *A);
int compute(FACTOR *A);

int main (int argc,char *argv[]){
	int A,B;
	FACTOR *ALIST,*BLIST,*gcd,*lcm;
	
	A=atoi(argv[1]);		//transform command line
	B=atoi(argv[2]);		//arguments to integer
	ALIST=factorize(A);		//factorize A
    BLIST=factorize(B);		//factorize B
	printf("A = ");			//print title
	write(ALIST);			//print how to compose A
	printf("B = ");			//print title
	write(BLIST);			//print how to compose B
    gcd=GCD(ALIST,BLIST);   //find GCD of A,B
    lcm=LCM(ALIST,BLIST);   //find LCM of A,B
	printf("GCD = ");		//print title
	write(gcd);				//print how to compose gcd
	printf("LCM = ");		//print title
	write(lcm);				//print how to compose lcm
	
	return 0;				//program end
}

FACTOR *factorize(int N){
	int i=2,j;
	FACTOR *result,*temp;
	
	temp=(FACTOR*)malloc(sizeof(FACTOR)); //get memory
	result=temp;						  //copy for shift
	temp->next=NULL;					  //close linked list					
	while(N!=1){
		while(N%i!=0) i++;				  //use another number to check
		j=0;							  
		while(N%i==0){					  //is prime factor
			j++;						  //j records power
			N/=i;						  //divide N with factor
		}
		temp->prime=i;					  //store factor
		temp->power=j;					  //store power
		temp->next=(FACTOR*)malloc(sizeof(FACTOR));
		temp=temp->next;				  //link the next node
	}
	temp->prime=1;						  //set breakpoint
	temp->power=1;						  //...

	return result;						  //return result
}

FACTOR *GCD(FACTOR *A,FACTOR *B){
	FACTOR *result,*temp;	
	
	temp=(FACTOR*)malloc(sizeof(FACTOR)); //get memory
    result=temp;						  //copy for shift
	temp->next=NULL;					  //close linked list
    while(A->prime !=1 && B->prime !=1){
		if(A->prime == B->prime){		  //find common factor
			temp->prime=A->prime;
			if (A->power > B->power) temp->power=B->power;
            else temp->power=A->power;	  //choose smaller power
            A=A->next;					  //check next
            B=B->next;					  //check next
            temp->next=(FACTOR*)malloc(sizeof(FACTOR));//memory for next node
            temp=temp->next;			  //linking
		}
		else if(A->prime > B->prime) B=B->next;
		else A=A->next;					  //check next
	}  
    temp->prime=1;						  //set breakpoint
    temp->power=1;						  //set breakpoint

	return result;						  //return result
}

FACTOR *LCM(FACTOR *A,FACTOR *B){
	FACTOR *result,*temp;
	
	temp=(FACTOR*)malloc(sizeof(FACTOR)); //get memory
	result=temp;						  //copy to shift
	temp->next=NULL;					  //close linked list
	while((A->prime !=1) || (B->prime !=1)){
    	if (A->prime==1 && B->prime!=1){  //when A is end
            temp->prime=B->prime;		  //store B
            temp->power=B->power;
            B=B->next;					  //check next
            temp->next=(FACTOR*)malloc(sizeof(FACTOR));//memeory for next node
            temp=temp->next;			  //linking 
        }
        else if(B->prime==1 &&A->prime!=1){
            temp->prime=A->prime;
            temp->power=A->power;
            A=A->next;
            temp->next=(FACTOR*)malloc(sizeof(FACTOR));
            temp=temp->next;
        }
		else if(A->prime > B->prime){
			temp->prime=B->prime;
			temp->power=B->power;
			B=B->next;
			temp->next=(FACTOR*)malloc(sizeof(FACTOR));
			temp=temp->next;
		}
		else if(A->prime < B->prime){
            temp->prime=A->prime;
            temp->power=A->power;
            A=A->next;
            temp->next=(FACTOR*)malloc(sizeof(FACTOR));
            temp=temp->next;
        }
		else{
			if(A->power > B->power) temp->power=A->power;
			else temp->power=B->power;	   //check A->prime=B->prime 		
			temp->prime=A->prime;
			A=A->next;
			B=B->next;
			temp->next=(FACTOR*)malloc(sizeof(FACTOR));
			temp=temp->next;				
		}
	}   
	temp->prime=1;                         //set breakpoint
	temp->power=1;						   //set breakpoint

	return result;
}

void write(FACTOR *A){
	int sum;	
	
	sum=compute(A);
	if (A->prime==1) printf("1"); 			   
	while(A->prime!=1){
		printf("%d",A->prime);
		if(A->power > 1) printf("^%d",A->power);
		if(A->next->prime !=1) printf(" * ");
		A=A->next;
	}
	printf(" = %d\n",sum);
	
	return;						  
}

int compute(FACTOR *A){
	int i,result=1;
	
	while(A->prime!=1){
		for(i=0;i<A->power;i++){
			result*=A->prime;			//calculate
		}
		A=A->next;						//go to next node
	}
	return result;						//return answer
}
