#include<stdio.h>

int main()
{
    int a[100], b[100],c[200];
    int m,n,i,j;
    scanf("%d %d",&m,&n);
    for(i=0;i<=m;i++)
    {
        scanf("%d",&a[m-i]);
    }

    for(i=0;i<=n; i++)
    {
        scanf("%d",&b[n-i]);
    }
    for(i=0;i<=m+n;i++)
    {
        c[i]=0;
    }
    for(i=0; i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            c[j+i] += a[i]*b[j];
        }
    }
    printf("%d\n",m+n);
    for(i=0;i<=n+m;i++)
    {
        if(i==0)
            printf("%d",c[m+n-i]);
        else
            printf(" %d",c[m+n-i]);
    }
}