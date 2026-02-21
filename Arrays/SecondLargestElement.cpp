#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int SecondLargest(vector<int>& nums)
{

    sort(nums.begin(), nums.end());

    for(int i=nums.size()-2; i>=0 ; i--){
        if(nums[i]!=nums[nums.size()-1]){
            return nums[i];
        }else{
            return -1;
        }
    }
}
int main()
{

    vector<int> nums = {9, 87, 43, 21, 90, 52};

    cout << "Second largest element : " << SecondLargest(nums) << endl;

    return 0;
}