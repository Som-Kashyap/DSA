#include<iostream>
#include<vector>

using namespace std;

int Diff(vector<int>& nums){

    int DigSum=0;
    int ArrSum=0;

    for (int i = 0; i<nums.size() ; i++){

        ArrSum += nums[i];

        int n = nums[i];

        while ( n>0 ){

            int digit = n%10;
            DigSum += digit;
            n /= 10;
        }
    }

    return abs(ArrSum-DigSum);
}