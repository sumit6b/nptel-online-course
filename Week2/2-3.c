#include<stdio.h>
#define Num 100
void printarr(int a[],int N);
//we can use amax array instead to shorten the code but who cares :P
int main()
{
    int rmax=0,cmax=0,d1max=0,d2max=0,maxi=0,k=0,j=0,N;
    int A[Num][Num],row[Num],col[Num],diag1[Num],diag2[Num],res[4];
    scanf("%d",&N);

    for(k=0;k<N;++k)
    {
        for(j=0;j<N;++j)
        {
            scanf("%d",&A[k][j]);
        }
    }
    //intitialize:
    for(k=0;k<N;++k)
    {
        row[k]=0;
        col[k]=0;
        diag1[k]=0;
        diag2[k]=0;
    }
//    printf("init done!");

    for(k=0;k<N;++k)
    {
        //rows and columns
        for(j=0;j<N;++j)
        {
            row[k] += A[k][j];
            col[k] += A[j][k];
        }
        diag1[k] += A[k][k];
//        printf("%d\n",diag1[k]);
        diag2[k] += A[k][N-1-k];
    }
    for(k=0;k<N;++k)
    {
        d1max += diag1[k];
        d2max += diag2[k];

    }

//    printarr(row,N);


    for(k=0;k<N;++k)
    {
        if(rmax<=row[k])
        {
            rmax=row[k];
        }
        if(cmax<=row[k])
        {
            cmax=row[k];
        }
        /*
        if(d1max<=diag1[k])
        {
            d1max=diag1[k];
        }
        if(d2max<=diag2[k])
        {
            d2max=diag2[k];
        }
        */

    }
//    printf("check done!");

    res[0]=rmax; res[1]=cmax; res[2]=d1max; res[3]=d2max;
    for(k=0;k<4;++k)
    {
        if(maxi<=res[k])
        {
            maxi = res[k];
        }
    }
    printf("%d",maxi);
}
/*
void printarr(int a[],int N)
{
    int k;
    for(k=0;k<N;++k)
    {
        printf("%d\n",a[k]);
    }

}
*/
