int printMaxActivities(struct Event events[], int n)

{

// insert code here
    int counter=0,i,val;
    qsort(events,n,sizeof(struct Event),comp);

    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            
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
/*
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

*/
