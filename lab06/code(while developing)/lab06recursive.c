/*EE231002 Lab06 Finding Sudoku Solutions
  103061232,Chong-yao,Zhang Jian
  DATE:2014.10.27
*/
#include <stdio.h>						
#define TRUE 1
#define FALSE 0

int mat[9][9];							//a matrix to store sudoku puzzle
int count=1;							//count the number of solutions
int flag;								//to record wheather a number is okay 

void read (void);						//function to read the .dat file
void fill (int i,int j,int mat[9][9]);  //to fill the 0's from 1 to 9
int  check(int a,int b);				//check numbers by rules of sudoku
void print (void);						//print solution

int main (void)
{
	read();								//start reading
	fill(0,0,mat);						//fill 0's
	printf("Solution %d :\n",count);    //print result
	print();							//...
	return 0;
}

void read (void)
{	
	int i,j;							//declare looping index
	char temp;							//used to covert data type

	for(i = 0;i < 9;i++){
		for(j = 0;j < 9;j++){
			scanf(" %c",&temp);
			if(temp == '.')				//that's because we use"."to represent 0
			mat[i][j] = 0;				//...
			else mat[i][j] = temp -'0';
		}
	}
}

int check (int a,int b){

	int i,j,p,q;						//declare local variables

	for (i=0;i<9;i++){					
		if (i!=a && mat[a][b]==mat[i][b])//check row for not being repeated
		return FALSE;
		}	
	for (j=0;j<9;j++){
		if (j!=b && mat[a][b]==mat[a][j])//check column for not being repeated
		return FALSE;
		}
	p=a/3;								//check 3*3 cube for not being repeated
	q=b/3;								
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if (mat[p*3+i][q*3+j]==mat[a][b])
				return FALSE;
		}
	}

	return TRUE;						//the number is not repeated 
}	

void fill (int i,int j,int mat[9][9])
{
	int k=1;

	if(k<=9){	
		if(mat [i][j]==0){		//find where the space is
			mat[i][j]=k;		//fill blank from 1
			flag=check(i,j);    //call check function 
			if (flag==FALSE){   //when the number is fault,check 
	   	    k++	;				//next one
			return;
			}
			if (flag==FALSE && mat[i][j]==9){//when the blank is filled
				if (j==8) i+=1,j=0; //with 9 go back to the former one
				if (j==0) i-=1,j=8;
				else j--;
			}
			if (flag==TRUE){	    //when the number is okay
				if (j==8) i+=1,j=0; //go to next one blank
				if (j==0) i-=1,j=8;
				else j++;	
			}
		}
	}
} 	


void print(void)
{
	int i=0,j,k=0;							
	while(k<9){
	
		for(i=k;i<k+3;i++){
			for(j=0;j<9;j+=3){
				printf("%2d%2d%2d",mat[i][j],mat[i][j+1],mat[i][j+2]);
				if(j<6) printf(" |");      
			}
		
		printf("\n");	
		}
	k=i;
	printf("-------|-------|------\n");
	}	
}
