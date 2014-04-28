
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int MatrixChainOrder(int p[],int n);

int main()
{
	int n,i;
	scanf("%d",&n);
	int *p = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
 	printf("%d",MatrixChainOrder(p, n));
    return 0;
}

int MatrixChainOrder(int p[], int n)
{

//insert code here.
    int num,i,l,j,k,m[n-1][n-1],q;

    num = n-1;
    for(i=1;i<=num;i++)
        m[i][i]=0;
    for(l=2;l<=num;++l)
    {
        for(i=1;i<=num-l+1;++i)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k=i;k<=j-1;++k)
            {
                q = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                }
            }
        }
    }
    return m[1][n-1];

}

