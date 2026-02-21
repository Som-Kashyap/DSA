#include <iostream>
#include <vector>

using namespace std;

void Permutations(vector<int> &nums, vector<vector<int>> &ans, int idx)
{
    if (idx == nums.size())
    {

        ans.push_back({nums});
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {

        swap(nums[idx], nums[i]);
        Permutations(nums, ans, idx + 1);

        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> main()
{

    vector<int> nums = {1, 2, 3};
    int idx = 0;
    vector<vector<int>> ans;

    Permutations(nums, ans, 0);

    return ans;
}