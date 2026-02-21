#include <bits/stdc++.h>
using namespace std;

int DiffOfSum(vector<int> &nums)
{

    int ArrSum, ESum = 0;
    vector<int> digits;

    for (int i = 0; i < nums.size(); i++)
    {
        ArrSum += nums[i];
        if (nums[i] == 0)
        {
            digits.push_back(0);
        }
        else
        {
            while (nums[i] > 0)
            {
                int digit = nums[i] % 10;
                digits.push_back(digit);
                nums[i] /= 10;
            }
            reverse(digits.begin(), digits.end());
        }
    }
    for (int val : digits)
    {
        ESum += val;
    }
    int diff = ArrSum - ESum;
    return abs(diff);
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 55, 67, 89, 21};

    cout << DiffOfSum(nums) << endl;
    return 0;
}