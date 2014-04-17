/*
*THE BELOW CODE WILL BE PREPENDED BEFORE COMPILATION.
*ALL NECESSARY FUNCTIONS OF LIST, LISTNODE ARE IMPLEMENTED.
*
*/

#include <iostream>
#include <cstring>
using namespace std;

class ListNode{
	private:
		int data;
		ListNode * next;
	public:
		ListNode(){}
		ListNode(int num){
			data=num;
			next = NULL;
		}
		int getData();
		void setData(int);
		void setNext(ListNode *);
		ListNode* getNext();
};
/*
*Implementation of Node Methods
*/
int ListNode::getData(){
		return data;
}
void ListNode::setData(int x){
		data = x;
}
ListNode * ListNode::getNext(){
		return next;
}
void ListNode::setNext(ListNode * P){
		next = P;
}
/***End Of Node Methods Implementation**/

class List{
	private:
		ListNode * Head;
	public:
		
		List(){
			Head=NULL;
		}
		~List(){}
		 /*Already Implemented Methods.You can use them in your 
                 *functions
                 **/
		ListNode * getHead();
		void setHead(ListNode *);
		ListNode * last();
		void append(int);
		void prepend(int);
		void popBack();
		void print();
		void copy(List);
		void printReverse();	//prints the list from Tail to Head.		
		
		/*Implement the follwing if required. Not mandatory*/

		ListNode * prevNode(ListNode* P);
		void popFront();						
		
};
/*
****List Methods Implementaion***
*/
ListNode * List::getHead(){
		return Head;
}

ListNode * List::last(){
		ListNode * temp=Head;
		if(Head==NULL) return NULL;
		while(temp->getNext()!=NULL){
			temp=temp->getNext();
		}
		return temp;
}
void List::setHead(ListNode * P){
		Head = P;
}
void List::append(int num){
		ListNode * new_node = new ListNode(num);
		ListNode * temp=Head;
		if(temp==NULL){
			Head = new_node;
			return;
		}
		while(temp->getNext()!=NULL) temp=temp->getNext();
		temp->setNext(new_node);
}
void List::prepend(int num){
		ListNode * new_node = new ListNode(num);
			
		new_node->setNext(Head);
		Head = new_node;
}
/*
*Removes the Tail Node
*/
void List::popBack(){
		ListNode * temp=Head,*prev=NULL;
		//NULL list
		if(Head==NULL){cout<<"List is Empty\n";}
		//single element
		if(Head->getNext()==NULL){
			delete Head;
			Head=NULL;
			return;
		}
		while(temp->getNext()!=NULL){
			prev = temp;
			temp=temp->getNext();
		}
		delete temp;
		prev->setNext(NULL);
}
void List::print(){
		ListNode * temp=Head;
		while(temp!=NULL){
			cout<<temp->getData();
			temp=temp->getNext();
		}
}
//copy values of L into this list
void List::copy(List L){
		Head = NULL;
		ListNode * temp = L.Head;
		while(temp!=NULL){
			this->append(temp->getData());
			temp=temp->getNext();
		}
}

void List::printReverse(){
		ListNode * curr=Head;
		ListNode * prev_last=NULL;
	
		while(Head!=NULL && prev_last!=Head){
			curr = Head;				
			while(curr->getNext()!=prev_last){
				curr = curr->getNext();
			}
			cout<<curr->getData();
			prev_last = curr;
		}
}

/*****End Of List Methods Implementation************************/

/* This is the data type you need to write the required methods*/
class BigInt{
   private:	
	    List L;
   public:
	   BigInt(){}
	   ~BigInt(){}
      /*Must write code for append(),prepend(), add(), print() Methods*/
	   void append(int num);
	   void prepend(int num);
	   BigInt add(BigInt A);
	   void print();//mandatory
	
	   /*Helper Functions, not mandatory to implement
	   *Hint: Implement removeZeroes(), call it in print().
	   */
	   void removeZeroes();
	   void copy(BigInt B);

};
/*UPTO THIS LINE, THE CODE WIL BE PREPENDED BEFORE YOUR FUNCTIONS*/


/**THESE ARE THE ONLY FUNCTIONS YOU ARE REQUIRED TO FILL
*You are allowed to define additional global functions.
*Note: Remove/Comment the helper functions, if you are not implementing them.
*/

void populate(BigInt &A, char * str){
   /*write your code here**/
   int n,T,i,val;
   T = strlen(str);
   n = T;

   while(n--)
   {
       val = str[n] - '0';
       //printf("%d\n",val);
       A.append(val);
   }

   for(i = 0;i<40-T;i++)
   {
       A.append(0);
   }
}
void BigInt::append(int num){
   /*write your code here**/
   L.append(num);
}
void BigInt::prepend(int num){
   /*write your code here**/
   L.prepend(num);
}

BigInt BigInt::add(BigInt A){
      /**write your code here*/
      /**write your code here*/
      ListNode *Bptr, *Aptr; BigInt C; int carry = 0,i,num,dataA,dataB;
      //ListNode *ptr = A.L.getHead();
      Bptr = L.getHead();
      Aptr = A.L.getHead();
      for(i=0;i<40;i++)
      {
          dataA = Bptr->getData();

          dataB = Aptr->getData();
          num = dataA+dataB+carry;
          C.append(num%10);
          carry = num/10;
          Bptr = Bptr->getNext();
          Aptr = Aptr->getNext();
      }
      return C;
}

void BigInt::removeZeroes(){
     /**write your code here
      *Hint: Implement removeZeroes(), call it in print().
      */
      while(L.last()->getData()==0)
      {
          L.popBack();
      }
}
void BigInt::print(){
     /*write your code here*/
     removeZeroes();
     L.printReverse();
}
/*Warning:: The following code given below will be appended
 *at the end of your code before compilation.
 *You must not write main function.
**/

int main(){

      char str[40];
      BigInt A,B;
      cin>>str;
      populate(A,str);

      cin>>str;
      populate(B,str);

      (A.add(B)).print();

      return 0;
}
