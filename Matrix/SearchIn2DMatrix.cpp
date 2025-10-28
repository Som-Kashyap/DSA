#include<iostream>
#include<vector>
using namespace std;

bool Search(vector<vector<int>>& mat,int tar){
    int m=mat.size(),n=mat[0].size();
     int st=0,end=n-1;
     for(int i=0; i<n; i++){
        int mid=st+(end-st)/2;
    for(int j=0; j<m; j++){
      if(mat[mid][i]==tar){
        return true;
      }
 else if(mat[st][i]<tar && tar<mat[end][i]){
        if(mat[mid][i]<tar){
            st=mid+1;
       
    }
  
    } 
      
  }
}