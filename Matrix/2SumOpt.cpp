#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> TwoSum(vector<int> nums, int tar)
{
    unordered_map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];

        int sec = tar - first;
        if (m.find(sec) != m.end())
        {
            ans.push_back(i);
            ans.push_back(m[sec]);
        }
        m[first] = first;
    }
    return ans;
}
int main()
{
    vector<int> nums = {5, 1, 2, 3, 6, 7};
    int tar = 9;
    cout << TwoSum << endl;
    return 0;
}
