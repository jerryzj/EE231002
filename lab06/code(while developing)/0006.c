/*Lab06 finiding sudoku solutions
  101011134  ?—ç???
  10/31/14
*/

#include <stdio.h>
#include <stdbool.h>


void scan();         
	//scanning input still got some problems
	//the ways i can think of havent been covered yet 
	//so i cant use it
int check_legal();
	//numbers allowed
void condition(int, int);
	//recurstive
void print_x();

int x[9][9] = {0};		//array
int solution = 1;
int main()
{
	int row, column;
	
	scan();	            //call scan function
											
	condition(0,0);		//call contion function
	printf("\n\n solution = %d\n\n",solution);
	return 0;
}

void scan(void){
	int row,column,i,j;
	char blank;			//if blank is a number char will store as number

	for(row=0; row<9; row++){
		for(column=0; column<9; column++){
			scanf("%c", &blank);
			if(blank == '.')    //storing input
				x[row][column]=0; 
			else
				x[row][column]=blank-'0';	
		}	
	}	
}

void condition(int a, int b){
	int i;
	if(x[a][b]==0){             //if x is empty fill in numbers
		for(i=1;i<=0;i++){	
			if(check_legal(a,b,i)){//according rule of sudoku
				x[a][b] = i;
				if(a==8 && b==8){
					print_x();
					solution++;     
					return;
				}
				else{
					if(b==8){      //go to next line
						condition(a+1,0); 
					}
					else{
						condition(a,b+1); //revcursive
					}
				}
				x[a][b]=0;
			}
		}
	}	
	else{                    //if already filled
		if(a==8 && b==8){
			print_x();
			solution++;
			return;
		}
		else{
			if(b==8){
				condition(a+1,0);
			}
			else{
				condition(a,b+1);
			}
		}
	}
	return;
}


int check_legal(int a,int b,int filled_number){
	int row, column, k, p, q;  
	for (row=0; row<9; row++){
    	if (filled_number == x[row][b]) //rule for row
    	return 0;
	} 
	for (column=0; column<9; column++){
		if ( filled_number == x[a][column])//rule for column
	 	return 0;
	}
	
	int i,j;
	for(i=0;i<3;i++){                  //special rule in sudoko
		for(j=0;j<3;j++){
			if (x[p*3+i][q*3+j]==filled_number)
				return 0;
		}
	}
	
	return 1;
}

void print_x(){ //print ouput
	int i,j;
	for(i=0;i<9;i++){    //loop for matrix
		for(j=0;j<9;j++){
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}      
}
