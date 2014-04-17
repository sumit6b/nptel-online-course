#include<stdio.h>
#include<string.h>
int main()
{
    char a[30], b[10],temp;
    int na, nb, i, j, k;
    scanf("%s",a);
    scanf("%s",b);
    na = strlen(a); nb = strlen(b);
    //printf("poop\n");
    for(i=0;i<nb;i++)
    {
        a[na+i] = b[i];

    }
    a[na+nb] = '\0';

    i = 0; j = 1;
    while(a[j]!='\0')
    {
        //printf("poop\n");
        k = j;
        while(1)
        {
            if(a[i]>a[k])
            {
                //printf("poop\n");
                temp  = a[k];
                a[k] = a[i];
                a[i] = temp;
                i--;k--;
            }
            else
                break;
        }
        j++; i = j-1;
    }


    i = 0;
    while(a[i]!='\0')
    {
        printf("%c",a[i]);
        i++;
    }

}