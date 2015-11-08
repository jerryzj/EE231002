/*Lab06 finiding sudoku solutions
  101011134  林立恆
  10/31/14
*/

#include <stdio.h>
#include <stdbool.h>

FILE *f;

void scan();
void try_number();
int check_legal();
void condition(int, int);
void print_x();

int x[9][9] = {0};
int total = 0;
int main()
{
	f = fopen("s1.dat","r");
	int row, column;
					
	scan();	
	int i,j;


	condition(0,0);
	printf("\n\n total = %d\n\n",total);
	return 0;
}

void scan(void){
	int row,column,i,j;
	char blank[2];
	
	for(row=0; row<9; row++){
		for(column=0; column<9; column++){
			fscanf(f,"%s", &blank);
		
			if(blank[0] == '.')
				x[row][column]=0; 
			else
				x[row][column]=atoi(blank);	
			
		}	
	}	
}



void condition(int a, int b){
	
		 int i;
    if(x[a][b]==0){
		 for(i=1;i<=9;i++){
		 	if(check_legal(a,b,i)){
		 		x[a][b] = i;
		 		if(a==8 && b==8){
		 			print_x();
		 			total++;
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
		 		x[a][b]=0;
		 	}
		 }
	}
	else{
		if(a==8&&b==8){
			print_x();
			total++;
			return;
		}
		else if(b==8){
		 	condition(a+1,0);
		}
		else{
		 	condition(a,b+1);
		}
	}

    return ;
	
}

int check_legal(int a,int b,int filled_number){
	int t1=a;
	int t2=b;
	int row, column, k;  
	for (row=0; row<9; row++){
    	if (filled_number == x[row][b])
    	return 0;
	} 
	for (column=0; column<9; column++){
		if ( filled_number == x[a][column])
	 	return 0;
	}
	int p=0,q=0;
	while(t1>2){
		t1 = t1 -3;
		p++;
	}
	while(t2>2){
		t2 = t2 -3;
		q++;
	}
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if (x[p*3+i][q*3+j]==filled_number)
				return 0;
		}
	}
	
	return 1;
	
}

void print_x(){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%d ",x[i][j]);
		}
		printf("\n");
	}
}
