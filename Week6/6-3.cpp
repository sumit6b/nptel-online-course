/***FIXED PREFIXED CODE***/
#include<iostream>
#include <stdlib.h>
using namespace std;

class IntStack {
	private:
		int *Data;
		int MAX_SIZE;
		int top;
	public:
		IntStack(){
			top=-1;
			MAX_SIZE = 50;
			Data = new int[MAX_SIZE];
		}
		IntStack(int size) {
			top=-1;
			MAX_SIZE=size;
			Data=new int[MAX_SIZE];
		}
		int isfull() {
			if(top==(MAX_SIZE-1)) return 1;
			else return 0;
		}
		int isempty() {
			if(top==-1) return 1;
			else return 0;
		}
		int topData() {
			if(isempty()){
				cerr<<"Error:Stack Underflow"<<endl;
				return -1;
			}
			else return Data[top];
		}
		void push(int elem) {
			if (isfull()){
				cerr<<"Error:Stack is Full"<<endl;
			}
			else{
				Data[++top] = elem;
			}
		}
		int pop() {
			if(isempty()){
				cerr<<"Error:Stack Underflow"<<endl;
				return -1;
			}
			else {
				return Data[top--];
			}
		}
};
/***END OF FIXED PREFIX CODE **/

/***Prefix code will be automatically prepended here before compilation**/
int isOperator(char* buf)
{
    if(*buf == '+' || *buf == '-' || *buf == '*' || *buf == '/')
        return 1;
    else
        return 0;
}
int main(){
   /**write your code here**/
   IntStack stack;
   int n=0,i,x,y,ans,num;
   char buffer[256],c;
   cin>>n;


   for(i=0;i<n;i++)
   {
      cin>>buffer;
      if (!isOperator(buffer))
      {
          num = atoi(buffer);
          //cout<<num<<endl;
          if(!stack.isfull())
            stack.push(num);
          else
            cout<<"INVALID";
      }

      else if(isOperator(buffer))
      {
          if(!stack.isempty())
          {
              y = stack.pop();
              if(!stack.isempty())
              {
                  x = stack.pop();
              }
              else
                {
                    cout<<"INVALID";
                    return 0;
                }
          }
          else
          {
              cout<<"INVALID";
              return 0;
          }


        switch(buffer[0])
        {
        case '+':
            stack.push(x+y);
            break;
        case '-':
            stack.push(x-y);
            break;
        case '*':
            stack.push(x*y);
            break;
        case '/':
            stack.push(x/y);
        }
    }
   }
   ans = stack.pop();

   if(!stack.isempty())
    cout<<"INVALID";
   else
    cout<<ans;

   return 0;
}
