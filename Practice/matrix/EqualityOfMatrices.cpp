#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<vector<int>> M1;
    int m1=M1.size(),n1=M1[0].size();
    vector<vector<int>> M2;
    int m2=M2.size(),n2=M2[0].size();

    cout<<"Enter Matrix 1:"<<endl;
    for(int i1=0;i1<n1;i1++){
        for(int j1=0;j1<n2;j1++){
            cin>>M1[i1][j1];
        }
    }
    

    cout<<"Enter Matrix 2: "<<endl;
     for(int i2=0;i2<n1;i2++){
        for(int j2=0;j2<n2;j2++){
            cin>>M1[i2][j2];
        }
    }
    if(m1==m2 && n1==n2){
         int cond=0;
        for(int i=0;i<n1;i++){
           
            for(int j=0;j<n1;j++){
                if(M1[i][j]==M2[i][j]){
                    cond=1;
                    
                }else{
                    cond=2;
                    break;
                    
                }
            }
        }
        if(cond==1){
        cout<<"Matrices are equal"<<endl;
      }
      else{
        cout<<"Matrices are unequal"<<endl;
      }
      
    }
      
    return 0;
    
}