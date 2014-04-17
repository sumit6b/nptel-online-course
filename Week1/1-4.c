#include<stdio.h>

int main()
{
    /*Enter your code here*/
    int num,i;
    scanf("%d",&num);
    for(i=1;i<=num;++i)
    {
    	if(num%i==0){
    		printf("%d",i);
    		if(num!=i)
    			printf(" ");
    		}
    }
    return 0;
}