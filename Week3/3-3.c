#include<stdio.h>
int T(int);
int main()
{
    /*write your code here*/
    int k,tk;
    scanf("%d",&k);
    tk = T(k);
    printf("%d",tk);
    return 0;
}

int T(int k)
{
    int res;
    if(k==0)//?
        return 1;
    else
        res = T(k-1)+2*k;
    return res;
}

/*
A recurrence relation T is defined on
n >= 0 and is given as T(n) = T(n-1) + 2*n
with the base case T(0) = 1. You will be given one
integer k and you have to write a program to find out T(k).
The program must implement T( ) recursivel
*/
