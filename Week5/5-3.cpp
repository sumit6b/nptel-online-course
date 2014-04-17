#include <iostream>
#include<stdio.h>
#include <cstring>

using namespace std;

struct matrixType{
    int matDimension;
    int matValues[10][10];
};

class MatrixADT{

    private:
        matrixType resultMatrix;

    public:

       //Member function declarations

        void intializeResultMatrix(int);
        matrixType add(matrixType, matrixType);
        matrixType subtract(matrixType,matrixType);
        matrixType multiply(matrixType,matrixType);
        void printResult();
};

//Member functions of Matrix class to be defined here
matrixType MatrixADT::add(matrixType M1, matrixType M2){
//Insert code here
int i,j;
    for(i=0;i<resultMatrix.matDimension;i++)
    {
        for(j=0;j<resultMatrix.matDimension;j++)
        {
            resultMatrix.matValues[i][j] = M1.matValues[i][j]+M2.matValues[i][j];
        }
    }
    return resultMatrix;
}

matrixType MatrixADT::subtract(matrixType M1, matrixType M2){
//Insert code here
int i,j;
    for(i=0;i<resultMatrix.matDimension;i++)
    {
        for(j=0;j<resultMatrix.matDimension;j++)
        {
            resultMatrix.matValues[i][j] = M1.matValues[i][j]-M2.matValues[i][j];
        }
    }
    return resultMatrix;
}

matrixType MatrixADT::multiply(matrixType M1, matrixType M2){
//Insert code here
int i,j,k;
    for(i=0;i<resultMatrix.matDimension;i++)
    {
        for(j=0;j<resultMatrix.matDimension;j++)
        {
            for(k=0;k<resultMatrix.matDimension;k++)
            {
                resultMatrix.matValues[i][j] += M1.matValues[i][k]*M2.matValues[k][j];
            }
        }
    }
    return resultMatrix;
}

void MatrixADT::intializeResultMatrix(int dim){
    int i,j;
    resultMatrix.matDimension = dim;
    for(i=0;i<resultMatrix.matDimension;i++)
    {
        for(j=0;j<resultMatrix.matDimension;j++)
        {
            resultMatrix.matValues[i][j] = 0;
        }
    }
}

int main(){

    MatrixADT maX;
    matrixType M1, M2;
    char op;
    int dim,i,j;
    cin>>dim>>op;

    for(i=0;i<dim; i++)
    {
        for(j=0;j<dim;j++)
        {
            scanf("%d",&M1.matValues[i][j]);
            //printf("scanned");
        }
    }
    for(i = 0; i<dim; i++)
    {
        for(j=0;j<dim;j++)
        {
            scanf("%d",&M2.matValues[i][j]);
        }
    }
    maX.intializeResultMatrix(dim);
    switch(op)
    {
    case '+':
        maX.add(M1,M2);
        break;
    case '*':
        maX.multiply(M1,M2);
        break;
    case '-':
        maX.subtract(M1,M2);
    }
/*Enter your code here to accept two input matrices as instances of class Matrix and perform the operations using member functions, display the result matrix using member function*/

/* DO NOT EDIT the code below; if you edit it, your program will not give correct output */
    
maX.printResult();
            
}


void MatrixADT::printResult(){

    int i,j;
    for (i=0;i<resultMatrix.matDimension;i++){
        for (j=0; j<resultMatrix.matDimension-1;j++){
            cout<<resultMatrix.matValues[i][j]<<" ";
        }
       cout <<resultMatrix.matValues[i][j]<<"\n";
    }
    cout <<”Done”;
}
