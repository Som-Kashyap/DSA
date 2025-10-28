#include <iostream>
#include <vector>

using namespace std;

bool IsSorted(vector<int> nums)
{

    while (nums.size() > 1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i + 1])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (nums.size() == 0)
    {
        return true;
    }
}
int main()
{

    vector<int> nums = {1, 2, 3, 4, 5, 6};

    IsSorted(nums);

    return 0;
}