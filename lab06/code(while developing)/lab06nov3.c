/*EE231002 Lab06 Finding Sudoku Solutions
  103061232,Chong-yao,Zhang Jian
  DATE:2014.10.27
*/
#include <stdio.h>						
#define TRUE 1
#define FALSE 0

int mat[9][9];							//a matrix to store sudoku puzzle
int count=1;							//count the number of solutions
int flag;								//to record whether a number is okay 

void read (void);						//function to read the .dat file
void fill (int i,int j);				//to fill the 0's inside from 1 to 9
int  check(int a,int b);				//check numbers by rules of sudoku
void print (void);						//print solution

int main (void)
{
	read();								//start reading
	fill(0,0);							//fill 0's
	printf("Total number of Solutions found: %d.\n",count);//print result number
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

	int i,j,p,q;   						 //declare local variables

	for (i=0;i<9;i++){					
		if (i!=a && mat[a][b]==mat[i][b])//check row for not being repeated
		return FALSE;
		}	
	for (j=0;j<9;j++){
		if (j!=b && mat[a][b]==mat[a][j])//check column for not being repeated
		return FALSE;
		} 
						            	//check 3*3 cube for not being repeated
	p=(i/3)*3;
	q=(j/3)*3;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if (mat[p+i][q+j]==mat[a][b] && !(p+i==a && q+j==b))
				return FALSE;
		}
	}
	return TRUE;						//the number is not repeated 
}	

void fill (int i,int j)
{
	int k=1;

	if(mat[i][j]!=0){			//if all the elements in matrix is filled 
		if(i==8&&j==8){			//print the whole puzzle
			count++;
			print();
		}
		else if(j==8){			//when the last one space of a row is filled
			fill(i+1,0);        //go fill next row
		}
		else fill(i,j+1);	    //fill next one space
	}
	else if(mat[i][j]==0){ 	    //if the space has not been filled 
		for(;k<=9;k++){	
			mat[i][j]=k;		//fill blank from 1
			flag=check(i,j);    //call check function 
			if (flag==TRUE){    //when the number is fault,check 
				if(i==8&&j==8){
					count++;
					print();
				}
				else if(j==8) fill(i+1,0);
				else fill(i,j+1);
			}
		}
		mat[i][j]=0;
	}
}
 	


void print(void)
{
	int i,j;	
	
	printf("Solution %d:\n",count);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf(" %d",mat[i][j]);
			if(j==2||j==5) printf(" |");      
		}
		printf("\n");
		if(i==2||i==5){
			printf(" ------|-------|------\n");
		}
	}	
}
