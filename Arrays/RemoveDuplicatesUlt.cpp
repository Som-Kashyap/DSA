#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void RemoveDuplicates(vector<int> &nums, int n)
{

    unordered_set<int> set;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {

        if (set.find(nums[i]) == set.end())
        {
            ans.push_back(nums[i]);
            set.insert(nums[i]);
        }
    }
    for (int val : ans)
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums = {9, 8, 9, 7, 6, 8};
    int n = nums.size();

    RemoveDuplicates(nums, n);

    return 0;
}