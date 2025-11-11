#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main () {

    pair<int , int>p1={1,2};
    pair<int , char>p2={2,'a'};
    vector<pair<int,char>> nums={{1,'a'},{2,'b'},{3,'c'}};
  

    cout<<p1.first<<endl;
    cout<<p1.second<<endl;

    for(auto val : nums){
      cout<<val.first<<endl;
    }

    return 0;

}