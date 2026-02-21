#include <iostream>
#include <vector>

using namespace std;

bool IsSorted(vector<int> &nums, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (nums[i + 1] < nums[i])
        {

            return false;
            break;
        }
    }

    return true;
}
int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    IsSorted(nums, n);

    return 0;
}