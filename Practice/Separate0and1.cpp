#include<iostream>
#include<vector>

using namespace std;

int sort(vector<int>nums){

    int i=0,j=nums.size()-1;

    while(i<j){
        if(nums[i]<nums[j]){
            swap(nums[i],nums[j]);
            i++;j--;
        }else{
            i++;j--;
            continue;
        }
    }

    for(int i=0 ; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>nums={1,1,0,1,0,1,1,0,0,0};

    cout<<"Sorted array: "<<sort(nums)<<endl;

    return 0;
}