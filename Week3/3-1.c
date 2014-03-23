#include<stdio.h>

int power(int x, int y);

int main()
{
/*write your code here*/
    int N,i,A[30],B[30],j,counter=0;
    scanf("%d",&N);
    for(i=0;i<N;++i)
    {
        scanf("%d",&A[i]);
    }

    for(i=0;i<N-1;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(power(A[i],A[j])>power(A[j],A[i]))
            {
                counter++;
            }
        }

    }
    printf("%d",counter);
    return 0;
}

// THE CODE BELOW WILL BE AUTOMATICALLY UNCOMMENTED DURING EXECUTION. PLEASE DO NOT MODIFY ANYTHING BELOW THIS LINE.*/

int power(int x, int y)
 {
   int result = x;
    int i;
   if(y == 0) return 1;
   if(x < 0 || y < 0) return 0;

   for(i = 1; i < y; ++i)
   result *= x;

   return result;
}
