#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintSubsets(vector<int> &nums, vector<int> &ans, int i)
{

    sort(nums.begin(), nums.end());

    int n = nums.size();

    if (i == n)
    {

        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Inclusion
    ans.push_back(nums[i]);
    int idx = i + 1;

    // Checking for equal elements:
    if (nums[idx] == nums[i])
    {

        PrintSubsets(nums, ans, i + 2);
    }

    PrintSubsets(nums, ans, i + 1);

    // Exclusion
    ans.pop_back();
    PrintSubsets(nums, ans, i + 1);
}
int main()
{

    vector<int> nums = {1, 2, 2};

    vector<int> ans;

    int i = 0;

    PrintSubsets(nums, ans, 0);

    return 0;
}