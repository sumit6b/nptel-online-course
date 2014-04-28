#include<stdio.h>

#include<stdlib.h>

struct Event

{

   int start_time,finish_time;

};

int comp (const void * elem1, const void * elem2)

{

struct Event  f = *((struct Event*)elem1);

struct Event  s = *((struct Event*)elem2);

if (f.finish_time > s.finish_time) return  1;

if (f.finish_time < s.finish_time) return -1;

return 0;

}

int printMaxActivities(struct Event events[], int n)
{
    int counter=0,i,val,a,b;
    qsort(events,n,sizeof(struct Event),comp);

    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            a = events[i].start_time;
            b = events[i].finish_time;
            val = events[i].finish_time;
            counter++;
            continue;
        }
        if(events[i].start_time>= val)
        {
            val = events[i].finish_time;
            counter++;
        }
    }
    return counter;
}

/**THE FOLLOWING CODE WILL BE APPENDED TO YOUR CODE BEFORE COMPILATION**/
/**Do not uncomment this code. You should not write main()*/

int main()

{

   int n,count,i;

   scanf("%d",&n);

   struct Event *events = (struct Event *)malloc(n*sizeof(struct Event));

   for(i=0;i<n;i++)

       scanf("%d",&events[i].start_time);

   for(i=0;i<n;i++)

       scanf("%d",&events[i].finish_time);




   count = printMaxActivities(events,n);

   printf("%d",count);

    return 0;

}


