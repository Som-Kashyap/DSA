#include<iostream>
using namespace std;

int LinarSearch(int matrix[4][3],int rows,int cols,int key){
    pair<int,int>p;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==key){
                p.first=i;
                p.second=j;
            }
               return -1;
        }
        cout<<p.first<<" "<<p.second<<endl;
    }
     return 0;
}
int main(){
    int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int rows=4;int cols=3;int key=18;

    cout<<"Row and column number of reqired element:"<<LinarSearch(matrix,rows,cols,key)<<endl;
    return 0;
}
