#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void SelectionSort(vector<int> nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        int MinIdx = i;

        for (int j = i + 1; j < nums.size(); j++)
        {

            if (nums[j] < nums[MinIdx])
            {
                MinIdx = j;
            }
        }

        swap(nums[i], nums[MinIdx]);
    }

    for (int val : nums)
    {

        cout << val << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> nums = {2, 4, 1, 5, 6};

    SelectionSort(nums);

    return 0;
}