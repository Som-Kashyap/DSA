#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter integer n: "<<endl;
    cin>>n;

    vector<int>ans;

    
    if(n==0){
     ans.push_back(0);
    }else{

    while(n>0){
        int digit =n%10;
     ans.push_back(digit);
     n/=10;
    }
    reverse(ans.begin(),ans.end());
}
   for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
   }
    cout<<endl;
    
    return 0;
}