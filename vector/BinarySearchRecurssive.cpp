#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int> &nums, int target, int st, int end)
{

    while (st < end)
    {

        int mid = st + (end - st) / 2;

        if (nums[mid] == target)
        {

            return mid;
            break;
        }

        else if (nums[mid] > target)
        {

            return BinarySearch(nums, target, st, mid - 1);
        }

        else
        {

            return BinarySearch(nums, target, mid + 1, end);
        }
    }
}
int main()
{

    vector<int> nums = {3, 5, 7, 9, 1, 2, 4, 6, 8};

    int target = 1;
    int st = 0;
    int end = nums.size() - 1;

    BinarySearch(nums, target, st, end);

    return 0;
}