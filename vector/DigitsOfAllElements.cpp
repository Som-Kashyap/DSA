#include <bits/stdc++.h>
using namespace std;

int PrintDigits(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (n == 0)
        {
            ans.push_back(0);
        }
        else
        {
            while (nums[i] > 0)
            {
                int digit = nums[i] % 10;
                ans.push_back(digit);
                nums[i] /= 10;
            }
            reverse(ans.begin(), ans.end());
        }
    }
    int DigSum=0;
    for (int i = 0; i < ans.size(); i++)
    {
        DigSum+=ans[i];
        cout << ans[i] << " ";
    }
    cout << endl;
    return DigSum;

}
int main()
{
    vector<int> nums = {1, 2, 22, 343, 56};
    cout << PrintDigits(nums) << endl;

    return 0;
}