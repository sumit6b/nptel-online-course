#include<stdio.h>
#include<string.h>
int StringLength(char[]);
void printChars(char*, char*);
int main()
{
    int i,n,counter = 0;
    char str[100],*p,*q;
    scanf("%s",str);
    n = strlen(str);
    //printf("%d",n);
    for(i = 0; i<=n/2;++i)
    {
        //printf("str[%d]=%c str[%d]=%c \n",i,str[i],(n-1)-i,str[(n-1)-i]);
        if(str[i]==str[(n-1)-i])
        {
            counter++;
            //printf("str[%d]=%c str[%d]=%c \n",i,str[i],(n-1)-i,str[(n-1)-i]);
        }

        else
            break;
    }
    //printf("%d",counter);
    p = str;
    if(counter == 0)
    {
        p = NULL;
    }
    q = p+counter-1;
    printChars(p,q);
}
/*
int StringLength(char str[])
{
    int counter=0,i=0;
    for(;i!='\0';i++)
    {
        counter++;
    }
    return counter;
}
*/
void printChars(char *p, char *q)
{

    if (p==NULL){
        printf("0");
    }
    else{
        while(p <= q){
            printf("%c",*p);
            p++;
        }
    }
}
