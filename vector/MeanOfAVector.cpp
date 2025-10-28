#include<iostream>
#include<vector>

using namespace std;

double Mean(vector<int>nums, int n){

    double sum=0;
   
    for(int i=0; i<n; i++){
        sum+=nums[i];
    }

    double mean = (sum/n);

    return mean;
}
int main(){

    vector<int>nums={5, 3, 6, 7, 5, 3};
    int n = nums.size();

     cout<<"Average of the vector is : "<<Mean(nums,n)<<endl;

  

    return 0;
}