#include <iostream>
using namespace std;

struct Node{
        int info;
	Node *next;
};

class QueueADT{
	private:		
		Node *qFront;
		Node *qRear;
		
	public:
		QueueADT(){ //constructor
			qFront = 0;
			qRear = 0;		
		}		
 		bool isEmpty(){
			if (qFront==NULL) return(true); 
			else return(false);
		}		
 		int dequeue(){	 	    	
 			int data;
 			data = qFront->info;
			qFront = qFront->next;
			if (qFront==0) qRear = 0;
			return data;
 		}		
 		void enqueue(int data){
 			Node *temp = new Node();    
 			temp->info = data;          
			temp->next = NULL;             
			
			if (qFront == 0) {
 				qFront = qRear = temp;
 			}
			else{
				qRear->next = temp;
 				qRear = temp;
			 }
		}		
		
};

int main(){
	int i, token, priority,j,k,data;
	QueueADT q1, q2, q3, q4;

	for (i=0;i<10;i++){
		cin>>token>>priority;
		/* Write code here to populate three queues for
                   separate priorities */
        switch (priority){
        case 1:
            q1.enqueue(token);
            //printf("in one");
            break;

        case 2:
            q2.enqueue(token);
            //printf("in 2nd");
            break;
        case 3:
            q3.enqueue(token);
        }
    	}
        /* Write code here to remove items from the three queues 
           based on the procedure specified, and add the "dequeued" 
           elements to queue q4, which will be printed using 
           non-editable loop given below */
	for(i=0;i<10;++i)
    {
        for(j=0;j<3;j++)
        {
            if(!q1.isEmpty())
            {
                data = q1.dequeue();
                q4.enqueue(data);
            }
        }
        for(k=0;k<2;++k)
        {
            if(!q2.isEmpty())
            {
                data = q2.dequeue();
                q4.enqueue(data);
            }
        }
        if(!q3.isEmpty())
        {
            data = q3.dequeue();
            q4.enqueue(data);
        }
    }
/* DO NOT edit the code below. It will be appended during compilation 

	for (i=0;i<10;i++)
		cout<<q4.dequeue()<<" ";
}
*/