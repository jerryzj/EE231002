// quiz2A, Arrays
#include <stdio.h>
int main(void)
{   int i,j, p,q, sum, m[5]={1,2,3,4,5};
    int n[3][3]={ {1,2,3}, {4,5,6}, {7,8,9} };
    printf("%d %d\n",m[3],m[4]);
    p=m[0]+m[2];    q=m[4]/m[1];
    printf("%d %d\n",p,q);
    sum=0; for(i=0; i<5; i++) sum+=m[i];
    printf("%d\n",sum);
    p=n[1][1];      q=n[1][2];
    printf("%d %d\n",p,q);
    for(sum=0, i=1; i<3; i++)
        for(j=1; j<3; j++)
            sum+=n[i][j];
    printf("%d\n",sum);
    i=3; j=1; printf("%d %d\n",m[i+j],m[i-j]);
    printf("%d %d\n",n[m[j]][j],n[j][m[j]]);
    p=sizeof(m)/sizeof(int); q=sizeof(m[1])/sizeof(int);
    printf("%d %d\n",p,q);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(i>j) n[i][j]=i+1;
            else n[i][j]=j+1;
    printf("%d %d\n",n[0][1],n[1][0]);
    p=0; for(i=0;i<3;i++)
             for(j=0;j<3;j++)
                 n[i][j]=p++;
    printf("%d %d\n",n[1][2],n[2][1]);
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            n[i][j]=m[i];
    printf("%d %d\n",n[1][0],n[2][1]);
}
