#include<stdio.h>
int main()
{
    int n,m,k,a[10],str,i;

    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    str = a[0];
    for(i=0;i<m;i++)
    {
        str = a[i+1]+k*str;
    }
    printf("%d",str);

}