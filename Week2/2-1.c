#include<stdio.h>
void printarray(int a[][]);
int main()
{
    int N, maxm,elem=0,i,temp=0,rank,j,in,r=1;
    int arr[201][2];

    scanf("%d",&N);

    //intialize the array
    for(i=0;i<201;i++)
    {
    	for(j=0;j<2;j++)
    	{
    		arr[i][j] = 0;
    	}

    }
    printarray(arr);


    while(N--)
    {
        scanf("%d",&temp);
        in = temp+100;
        ++arr[in][0];
        if(arr[in][1]==0)
        {
        	arr[in][1]=r++;

        }
    }

    printarray(arr);

    maxm = arr[0][0];
    rank = 1000;

    for(i=1;i<201;i++)
    {
        if(maxm<=arr[i][0])
        {
        if (rank > arr[i][1]&&arr[i][1]!=0){

            maxm = arr[i][0];
            rank = arr[i][1];
            elem = i-100;
            }
        }
    }
    printf("%d",elem);
    return 0;
}

void printarray(int a[201][2])
{
    int i,j;
    for(i=0;i<201;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("||");
            printf("a[%d][%d] | %d",i,j,a[i][j]);
            printf("||");
        }
        printf("\n");
    }

}
