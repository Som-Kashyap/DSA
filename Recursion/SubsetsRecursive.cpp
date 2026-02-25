#include <iostream>
#include <vector>

using namespace std;

void PrintSubsets(vector<int> &nums, vector<int> &ans, int i)
{

    int n = nums.size();

    if (i == n)
    {

        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // Selecting Elements:
    ans.push_back(nums[i]);

     PrintSubsets(nums, ans, i + 1);

    // Rejecting Elements:

    ans.pop_back();

     PrintSubsets(nums, ans, i + 1);
}
int main()
{

    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    int i = 0;

    PrintSubsets(nums, ans, 0);
    return 0;
}