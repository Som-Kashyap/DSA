#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Repeated(vector<int> &nums)
{

    int freq = 1;
    int ans = -1;
    int n = (nums.size()) / 2;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {

        if (nums[i] == nums[i + 1])
        {
            freq++;
        }

        else
        {
            freq = 1;
        }

        if (freq >= n)
        {

            ans = nums[i];
            return ans;
            break;
        }
    }
    
}
int main()
{

    vector<int> nums = {1, 2, 3, 3};

    Repeated(nums);

    return 0;
}