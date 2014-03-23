#include<stdio.h>
//void printarray(int a[][],int m,int n);
int main()
{
    int maxm,naxm,m,n,i,j,x,k=0,y,z,w,coun=10,l=0;
    int A[5][5];
    int B[5][5];

    scanf("%d %d",&maxm,&naxm);
    m = maxm;
    n = naxm;

    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            scanf("%d",&A[i][j]);
        }
    }

//    printarray(A,m,n);


    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            B[i][j] = 0;
        }
    }

    while(coun--){
    for(x=0;x<n-l;++x)
    {
        if(k==1)
            printf(" ");
        if(B[k][x+k]==0)
        {
            printf("%d",A[k][x+k]);

            B[k][x+k]=1;
        }
        if(x<n-1&&k!=1)
            printf(" ");
    }

    for(y=0;y<(m-1)-l;++y)
    {
        if(B[y+1+k][n-1]==0)
        {
            printf(" ");
            printf("%d",A[y+1+k][n-1]);
            //printf(" ");
            B[y+1+k][n-1]=1;
        }
    }

    for(z=0;z<(n-1)-l;++z)
    {
        if(B[m-1][(n-1)-1-z]==0)
        {
            printf(" ");
            printf("%d",A[m-1][(n-1)-1-z]);
            //printf(" ");
            B[m-1][(n-1)-1-z]=1;
        }
    }

    for(w=0;w<(m-2)-l;++w)
    {
        if(B[(m-1)-1-w][k]==0)
        {
            printf(" ");
            printf("%d",A[(m-1)-1-w][k]);
            //printf(" ");
            B[(m-1)-1-w][k]=1;
        }
    }

    m--;
    n--;
    k++;
    l++;

    }

}
/*
void printarray(int a[5][5],int m, int n)
{
    int i,j;
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

}
*/
