/*
 * example ex83.c
 *     to fill an NxN array with integers
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3
int A[N][N];

int main(void)
{
	int i,j,k=1;

	/* to fill array with integers by rows */
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			A[i][j]=k++;
		}
	}

	/* print out array */
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf(" %d",A[i][j]);
		}
		printf("\n");
	}

	/* to fill array with integers by columns */
	k=1;
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			A[j][i]=k++;
		}
	}

	/* print out array */
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf(" %d",A[i][j]);
		}
		printf("\n");
	}

	/* to fill array with integers */
	for (i=0; i<N; i++) {
		k=i+1;
		for (j=0; j<N; j++) {
			A[i][j]=k++;
		}
	}

	/* print out array */
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			printf(" %d",A[i][j]);
		}
		printf("\n");
	}

	return 0;
}
