#include<stdio.h>

int main() {
   /*Insert your code here*/
int m,c,x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    if(x2==x1&&x3==x1)
    	printf("Yes");
    else{	
    m=(y2-y1)/(x2-x1);
    c=y1-m*x1;
    if(y3==m*x3+c)
        printf("Yes");
    else
        printf("No");
    }
   return 0;
}