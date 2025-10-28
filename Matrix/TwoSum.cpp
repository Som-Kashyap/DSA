#include <iostream>
#include <vector>
using namespace std;

int TwoSum(vector<int> &nums, int tar)
{
    vector<int>ans;
    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i + 1; j < nums.size(); j++)
        {
            int sum = nums[i] + nums[j];
            if (sum == tar)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
     
        } 
          
    }for(int val:ans){
       cout<<val<<" ";
             }
        cout<<endl;

    return 0;
}
      

int main()
{
    vector<int> nums = {5, 1, 7, 2, 3};
    int tar = 19;
     cout<<TwoSum(nums, tar)<<endl;
    return 0;
}