/*EE231002 lab09 GCD & LCM
  103061232.Chong-yao,Zhang Jian
  DATE:2014.11.17
*/

#include <stdio.h>
#define S 20

/*Function Declarations
  factorize:to do prime factor decomposition
  GCD:find greatest common divisor of 2 input numbers
  LCM:find least common multiple of 2 input numbers
  write:print calculation process
  compute:compute power 
*/
void factorize(int N,int facors[S],int power[S]);
void GCD(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
		 int Cfactors[S],int Cpower[S]);
void LCM(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
         int Cfactors[S],int Cpower[S]);
void write(int factors[S],int power[S]);
int compute(int factor,int power);

int main (void){
	int a,b,af[S]={},ap[S]={},bf[S]={},bp[S]={};
	int cf[S]={},cp[S]={};  //variable declaration

	printf("input A: ");	//print argument
	scanf("%d",&a);			//scan input value and store it at a
	printf("input B: ");    //print argument
	scanf("%d",&b);			//scan input value and store it at b
	if (a==0 || b==0){
		printf(" WARNING : invalid input\n");	
		return 0;			//if input is wrong,program terminate
	}
	factorize(a,af,ap);		//factorize a
    factorize(b,bf,bp);		//factorize b
	printf("   A = ");		//print title
	write(af,ap);			//print how to compose a with prime numbers
	printf("   B = ");		//print title
	write(bf,bp);			//print how to compose b with prime numbers
	GCD(af,ap,bf,bp,cf,cp); //find GCD of a,b
	LCM(af,ap,bf,bp,cf,cp); //find LCM of a,b
	
	return 0;
}

void factorize(int N,int factors[S],int power[S]){
	int temp=0,i,j=0;
	
	temp=N;						//decompose temp instead of N
	for(i=2;i<=N && temp!=1;){
		if(temp%i==0){
			while(temp%i==0){	
				temp/=i;		//divide temp with factor i
				power[j]++;		//power add 1 each time
			}	
			factors[j]=i;		//record factor
			i++;	j++;		//use next element of array
		}
		else i++;
	}
	factors[j]=1;				//set last one valid element =1
	power[j]=1;					
}

void GCD(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
         int Cfactors[S],int Cpower[S]){
	int i=0,j=0,k=0;						//index for loop

	for(i=0;Afactors[i]!=1;i++){
		for(j=0;Bfactors[j]!=1;j++){
			if (Afactors[i]==Bfactors[j]){	//find common factor
				Cfactors[k]=Bfactors[j];	//store what we find 
				if (Apower[i]>=Bpower[j]) Cpower[k++]=Bpower[j];
				else Cpower[k++]=Apower[i]; //check smaller power
			}
		}
	}
	Cfactors[k]=1;							//set breakpint
	Cpower[k]=1;
	printf("   GCD(A,B) = ");				//print title
	write(Cfactors,Cpower);					//print calculation process
}

void LCM(int Afactors[S],int Apower[S],int Bfactors[S],int Bpower[S],
         int Cfactors[S],int Cpower[S]){
	int i=0,j=0,k=0;

	while(Afactors[i] !=1 && Bfactors[j] !=1){
		if (Afactors[i]==Bfactors[j]){		//check common factor
			Cfactors[k]=Bfactors[j];		//store common factor
			if (Apower[i]>Bpower[j]) Cpower[k]=Apower[i];
			else Cpower[k]=Bpower[j];		//check bigger power and store it
			i++;	j++;	k++;
		}
		else if (Afactors[i]>Bfactors[j]){  //when A factors > B factors
			Cfactors[k]=Bfactors[j];		//store Bfactor into Cfactor
			Cpower[k]=Bpower[j];			//store Bpower into Cpower
			j++;	k++;
		}
		else if (Afactors[i]<Bfactors[j]){  //when A factors < B factors
			Cfactors[k]=Afactors[i];		//store Afactor into Cfactor
			Cpower[k]=Apower[i];			//store Apower into Cpower 
			i++;	k++; 
		}
	}
	/*the following while  loop is to put all the rest factor into C array*/
	while(Afactors[i] !=1 || Bfactors[j] !=1){
		if (Bfactors[j]==1){
			Cfactors[k]=Afactors[i];
			Cpower[k]=Apower[i];
			i++;	k++;
		}
		else{ 
			Cfactors[k]=Bfactors[j];
			Cpower[k]=Bpower[j];
			k++;	j++;
		}
	}
	Cfactors[k]=1;							//set breakpoint
	Cpower[k]=1;
	printf("   LCM(A,B) = ");				//print title
	write(Cfactors,Cpower);					//print calculation process
}

void write(int factors[S],int power[S]){
	int i,sum=1;
	
	if (factors[0]==1 ) printf("1"); 			   //daal with coprime event
	for(i=0;factors[i]!=1;i++){
		sum=sum*compute(factors[i],power[i]);	   //calculate final answer
		if (power[i]==1) printf("%d",factors[i]);  //print factor only when
		else printf("%d^%d",factors[i],power[i]);  //power=1,else print both
		if (factors[i+1]!=1) printf(" * ");		   //print multiplication sign
	}
	printf(" = %d\n",sum);						   //print answer
}

int compute(int factor,int power){
	int i,result=1;			

	for(i=1;i<=power;i++){ 
		result*=factor;								//calculate x^n
	}

	return result;			
}
