#include <iostream>

using namespace std;

class binarySearchTree;
class treeNode{
	/*
	*with the following friend declaration
	*binarySearchTree class can also access private members of treeNode
	*/
	friend class binarySearchTree;
	private:
		int data;
		treeNode * left;
		treeNode * right;
	
	public:
		treeNode(){
			left=right=NULL;
			//parent = NULL;
		}
		treeNode(int key){
			data=key;
			left=right=NULL	;
			//parent=NULL;
		}
		int getData(){ return data;}
		void setData(int key){data=key;}
};

class binarySearchTree{
	private:
		treeNode * root;
	public:
		binarySearchTree(){root=NULL;}

/*THE ABOVE CODE WILL BE ADDED AS PREFIX TO YOUR CODE**/
/*Finish The Implementation of the binarySearchTree Class*/


/*THE ABOVE CODE WILL BE ADDED AS PREFIX TO YOUR CODE**/
/*Finish The Implementation of the binarySearchTree Class*/


/**Prefixed code **/
/*implement the insert, remove and print functions inside *binarySearchTree class and close the class declaration.
*/
/**Write Your Code Here**/
        bool insert(int val)
        {
            //printf("poop");
            bool flag = true;
            treeNode *rootptr = root;
            if(rootptr == NULL)
            {
                treeNode* ptr = new treeNode(val);
                root = ptr;
                //printf("root contains: %d\n",root->getData());
            }
            else{

            while(true)
            {
                if(val < rootptr->getData())
                {
                    if(rootptr->left==NULL)
                    {
                        treeNode* ptr = new treeNode(val);
                        rootptr->left = ptr;
                        //printf("inserted value is less than previous\n");
                        break;
                    }
                    else
                        rootptr = rootptr->left;
                }
                else if(rootptr->getData()<val)
                {
                    if(rootptr->right==NULL)
                    {
                        treeNode *ptr = new treeNode(val);
                        rootptr->right = ptr;
                        //printf("inserted value is greater than previous\n");
                        break;
                    }
                    else
                        rootptr = rootptr->right;
                }
                else if(val == rootptr->getData())
                    flag = false;
            }
            }
            return flag;
        }
        treeNode* remove(int val)
        {
            treeNode *rootptr = root, *parent=root;
            while(true)
            {
                //search value
                if(rootptr->getData() == val)
                    break;
                else if(val < rootptr->getData())
                {
                    parent = rootptr;
                    rootptr = rootptr->left;
                }
                else if(rootptr->getData()<val)
                {
                    parent = rootptr;
                    rootptr = rootptr->right;
                    //printf("value to be deleted is greater than root\n");
                }
                else
                    cout<<"Element not found"<<endl;
            }
            if(rootptr == root&&rootptr->left==NULL&&rootptr->right==NULL)
            {
                root = NULL;
                return root;
            }

            if(rootptr->left==NULL && rootptr->right==NULL)
            {
                if(parent->left==rootptr)
                {
                    parent->left=NULL;
                    return rootptr;
                }
                else if(parent->right==rootptr)
                {
                    parent->right = NULL;
                    return rootptr;
                }

            }
            else if(rootptr->left!=NULL&&rootptr->right==NULL)
            {
                //printf("bingo!");
                if(parent == rootptr)
                {
                    //treeNode* ptr =NULL;
                    rootptr->setData(rootptr->left!=NULL?rootptr->left->getData():rootptr->right->getData());
                    rootptr->left = NULL;
                }
                treeNode *ptr = rootptr->left;
                if(parent->left==rootptr)
                {
                    parent->left = ptr;
                }
                else
                    parent->right = ptr;
            }
            else if(rootptr->left==NULL && rootptr->right!=NULL)
            {
                treeNode *ptr = rootptr->right;
                if(parent->left==rootptr)
                {

                    parent->right = ptr;
                }
                else
                {
                    parent->right = ptr;
                }

            }
            else if(rootptr->left!=NULL&&rootptr->right!=NULL)
            {

                treeNode *predessor = rootptr->left, *parentPredessor=rootptr;
                while(predessor->right!=NULL)
                {
                    parentPredessor=predessor;
                    predessor = predessor->right;
                }

                if(predessor->left!=NULL)
                 {
                     //printf("hi");
                     parentPredessor->right = predessor->left;
                 }

                else
                    parentPredessor->left = NULL;

                rootptr->setData(predessor->getData());
                predessor->left = NULL;
                predessor->right =NULL;
            }



            return rootptr;
        }
        void print()
        {
            //printf("inprint\n");
            treeNode *parent = root;
            
            if(root == NULL)
            {
                cout<<"NULL";
                return;
            }

            if(root->left==NULL &&root->right==NULL)
            {
                cout<<root->getData();
                //cout<<root->getData()<<" ";
                return;
            }
            //cout<<" ";
            if(root->left!=NULL)
            {
                root = root->left;
                //cout<<" ";
                print();
                cout<<" ";
                root = parent;
            }
            //cout<<" ";
            
            if(root->right!=NULL)
            {
                root = root->right;
                //cout<<" ";
                print();
                cout<<" ";
                root = parent;
            }
            //cout<<" ";
            
            cout<<root->getData();
            //cout<<root->getData()<<" ";
        }

};

/**THE FOLLOWING CODE WILL BE APPENDED TO YOUR CODE BEFORE COMPILATION**/
/**Do not uncomment this code. You should not write main()*/

int main(){

	binarySearchTree bst;
	int N,val,k;
	char op;
	cin>>N;
	while(N--){
		cin>>val;
		bst.insert(val);
	}
	cin>>k;

	while(k--){
		cin>>op;
		cin>>val;

		if(op == 'i'){
			bst.insert(val);
		}
		else if (op=='d'){
			bst.remove(val);
		}

	}

	//print post order traversal of the tree
	bst.print();

	return 0;
}
