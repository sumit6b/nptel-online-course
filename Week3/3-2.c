#include<stdio.h>

int power(int x, int y);

int main()
{
/*write your code here*/
    int N,i,a,sum=0,X;
    scanf("%d %d",&N,&X);
    for(i=N;i>=0;--i)
    {
        scanf("%d",&a);
        sum += a*power(X,i);
    }
    printf("%d",sum);

    return 0;
}

/* THE CODE BELOW WILL BE AUTOMATICALLY UNCOMMENTED DURING EXECUTION. PLEASE DO NOT MODIFY ANYTHING BELOW THIS LINE.*/

 int power(int x, int y)
 {
   int i,result = x;

   if(y == 0) return 1;
   if(x < 0 || y < 0) return 0;

   for(i = 1; i < y; ++i)
   result *= x;

   return result;
}
