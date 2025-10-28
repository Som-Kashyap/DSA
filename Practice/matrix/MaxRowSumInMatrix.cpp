#include<iostream>
#include<climits>
using namespace std;

int MaxSum(int matrix[3][3],int rows,int cols){
    int maxSum=INT_MIN;
   

    for(int i=0;i<rows;i++){
          int sum=0;
        for(int j=0;j<cols;j++){
         sum+=matrix[i][j];
            }
            maxSum=max(sum,maxSum);
        }
        
         return maxSum;
    }
    int main()
    {
        int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
        int rows=3,cols=3;

        cout<<"Max row sum: "<<MaxSum(matrix,rows,cols)<<endl;
        return 0;
    }
    
