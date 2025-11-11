#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int MaxPro(vector<int> &nums)
{

    sort(nums.begin(), nums.end());

    int a = nums[nums.size() - 1];
    int b = nums[nums.size() - 2];
    int c = nums[nums.size() - 3];

    int pro = a * b * c;

    return pro;
}
int main()
{
    vector<int> nums = {5, 3, 2, 4, 1};

    cout << "Max pro of 3 numbers : " << MaxPro(nums) << endl;

    return 0;
}