#include<stdio.h>
#include<string.h>
void swapstring(char*, char*);
int main()
{
    int n, i, j, k;
    char c[100][11];

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",c[i]);
    }

    i = 0; j = 1;
    for(j=1;j<n; j++)
    {
        i = j-1;
        //printf("poop0");
        k = j;
        while(1)
        {
            //printf("poop1");
            if(strcmp(c[i],c[k])>0&&i>=0)
            {
                //printf("poop");
                swapstring(&c[i][0],&c[k][0]);
                i--;k--;
            }
            else
                break;
        }
        //j++;
        //i = j-1;
    }

    for(i = 0; i<n; i++)
    {
        printf("%s\n",c[i]);
    }
}

void swapstring(char* i, char* j)
{   char temp[10];
    int k = 0, itr = 0;
    while(i[k]!='\0')
    {
        temp[k] = i[k];
        k++;
    }
    temp[k] = '\0';

    itr = 0;
    while(j[itr]!='\0')
    {
        i[itr] = j[itr];
        itr++;
    }
    i[itr] = '\0';

    itr = 0;
    while(temp[itr]!='\0')
    {
        j[itr] = temp[itr];
        itr++;
    }
    j[itr] = '\0';
}