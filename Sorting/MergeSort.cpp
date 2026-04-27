#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> nums, int st, int mid, int end)
{

    vector<int> temp;

    int i = st;
    int j = mid + 1;

    while (st <= mid && j < nums.size())
    {

        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j < nums.size())
    {
        temp.push_back(nums[j]);
        j++;
    }
    for (int idx = st; idx < temp.size(); idx++)
    {
        nums[idx + st] = temp[idx];
    }
}
void MergeSort(vector<int> nums, int st, int end)
{

    if (st < end)
    {
        int mid = st + (end - st) / 2;

        MergeSort(nums, st, mid);
        MergeSort(nums, mid + 1, end);
        Merge(nums, st, mid, end);
    }
}
int main()
{

    vector<int> nums = {3, 1, 5, 2, 7};

    MergeSort(nums, 0, nums.size() - 1);

    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}