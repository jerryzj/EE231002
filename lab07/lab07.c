/*EE231002 Lab07. Matrix Determinants
  103061232.Chong-yao,Zhang Jian
  DATE:2014.11.3
*/
#include <stdio.h>
#if !defined(N)
#define N 3
#endif

double det(double A[N][N],int dim);	//to calculate determine

int main (void){

	int i,j;							//declare variables
	double A[N][N]; 				
	
	printf("Matrix A is\n");			//print title
	for(i=0;i<N;i++){					
		for(j=0;j<N;j++){
			scanf(" %lf",&A[i][j]);		//scan file
			printf("%3g",A[i][j]);		//print file
		}
		printf("\n");
	}							
	printf("det(A) = %g\n",det(A,N));	//print final answer
	return 0;
}



double det(double A[N][N],int dim){

	int a,b,k,power;					//a,b index. k locate elements.
	double ans=0,temp[N][N]={};			//temp record A after order reduction
	
	if (dim==2){
		return A[0][0]*A[1][1]-A[0][1]*A[1][0];//when dimension=2,count it
	}
	else{
		for(k=0;k<dim;k++){					   //doing matrix order reduction
			for(a=0;a<dim;a++){				   //and store it at temp	
				for(b=0;b<dim;b++){
					if(k==0){				   //put elements into temp with
						temp[a][b]=A[a+1][b+1];//some judgement
					}
					else if(k>0){
						if (a<k) temp[a][b]=A[a][b+1];
						else if (a>k) temp[a][b]=A[a+1][b+1];
					}	
				}
			}
			if(k%2==0) power=1;					  //determine +1/-1 by k
			else power=-1;
			ans=ans+power*A[k][0]*det(temp,dim-1);//count final answer
		}
	}
		return ans;							   //return answer to main function
}