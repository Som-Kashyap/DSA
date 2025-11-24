#include<iostream>
#include<vector>

using namespace std;

vector<int> Digits(vector<int>& nums){

    vector<int>digits;

    for(int i=0; i<nums.size(); i++){

         int num = nums[i];
        while(nums[i]>0){

            int digit = num%10;
            digits.push_back(abs(num));
            num /= 10;

           
        }

    }

    return digits;
}
int main() {

    vector<int>nums = { 1,-21, 9 ,-4 ,67};

    Digits(nums);

    return 0;
}





