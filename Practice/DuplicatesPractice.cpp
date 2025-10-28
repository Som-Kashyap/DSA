
#include <bits/stdc++.h>

using namespace std;

void FindDuplicates(vector<int> &nums, int n)
{

    set<int> s;

    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
        {
            cout << "Duplicate found: " << nums[i] << endl;
        }
        s.insert(nums[i]);
    }
}
int main()
{
    vector<int> nums = {6, 7, 6, 5, 4, 7};
    int n = nums.size();
    FindDuplicates(nums, n);
    return 0;
}