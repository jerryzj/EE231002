#include <stdio.h>
int main (void)
{
	int mat[9][9] ={ 0 };
	int i,j;

	
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				printf("% d",mat[i][j]);
				if(j==2||j==5) printf(" |");
			}
			printf("\n");
			if(i==2||i==5){
				printf("-------|-------|------\n");
	    	}
		}
		return 0;
}

