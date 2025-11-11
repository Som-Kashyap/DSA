#include <iostream>
#include <vector>

using namespace std;

int Sign(vector<int> &nums)
{

    int ans = 0;

    int negative;
    int positive;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            negative++;
        }
        else if (nums[i] > 0)
        {
            positive++;
        }
        else
        {
            ans = 0;
            
            break;
        }
    }

    if ((negative % 2) != 0)
    {
        ans = -1;
    }
    else if ((negative % 2) >= 0)
    {
        ans = 1;
    }

    return ans;
}
int main()
{

    vector<int> nums = {-1, -2, -3, -4, 3, 2, 1};

    Sign(nums);

    return 0;
}
