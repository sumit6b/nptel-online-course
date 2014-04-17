#include<stdio.h>
int main() {
   /*Insert your code here*/
	int c=11,num;
	//printf("enter no");
	scanf("%d",&num);
	//printf("done");
	while(c>=10)
	{
		c=0;
		while(num>0)
		{
			//printf("%d\n",num);
			c+=num%10;
			num/=10;

		}
		num=c;

	}
	printf("%d",c);
   return 0;
}