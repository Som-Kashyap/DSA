#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

int Duplicates(vector<int>& nums){

    vector<int>Ans;

    unordered_set<int>s;

    for(int i = 0; i < nums.size(); i++){
        if(s.find(nums[i])!=s.end()){
            s.insert(nums[i]);
        }else{
            Ans.push_back(nums[i]);
        }
    }

    for(int val : Ans){
        return val;
    }
  
}
int main () {
    vector<int>nums = {4,3,2,7,8,2,3,1};

    Duplicates(nums);

    return 0;
}