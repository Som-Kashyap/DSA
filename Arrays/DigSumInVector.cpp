#include<iostream>
#include<vector>

using namespace std;


int DigSum(vector<int> &nums){

    vector<int> digits;
    int DigSum=0;

    for(int i=0; i<nums.size(); i++){

        while( nums[i]>0 ){
        int digit = nums[i] % 10;
        digits.push_back(digit);
        nums[i] /= 10;

        }
        if(nums[i]==0){
            digits.push_back(0);
        }
    }

    for (int val : digits)
    {
        DigSum += val;
    }

     return DigSum;
   
}int main() {

    vector<int> nums = {16, 28, 39};

    cout<<DigSum(nums)<<endl;

    return 0;
}