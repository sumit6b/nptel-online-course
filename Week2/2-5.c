#include<stdio.h>
#include<string.h>
#define true 1
#define false 0
typedef int bool;

int main()
{
    bool first = true, matchMode = false;
    char A[20], B[20];
    int n,i2=0,i1=0,index = -1,noofchar = 0;

    scanf("%s %s",&A,&B);
    n = strlen(A);
    //printf("%d",n);
    while(n--)
    {
        if(A[i1]==B[i2])
        {
            printf("%c matches with %c\n",A[i1],B[i2]);

            if(first)
            {
                index = i1;
                first = false;
                matchMode = true;
            }
            noofchar++;
            i1++;
            i2++;
            printf("i1 = %d i2 = %d index = %d\n",i1,i2,index);

        }
        else if(matchMode)
        {
            if(B[i2]=='\0')
            {
                printf("%d ",index);
                break;
            }
            else
            {
                printf("match failed reverting all variables...\n");
                i2 = 0; i1 = i1-noofchar+1;

                first = true;
                matchMode = false;
                noofchar = 0;
                index = -1;
                printf("now i1 = %d and i2 = %d index = %d\n\n",i1,i2,index);
            }

        }
        else
        {
            printf("i1 %d does not matched with i2 %d\n",i1,i2);
            if(A[i1]!='\0')
                i1++;

            else if(A[i1]=='\0')
            {
                printf("%d",index);
                break;
            }
        }

    }

}
