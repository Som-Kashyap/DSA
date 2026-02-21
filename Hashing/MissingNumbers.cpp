#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> &MissingNumbers(vector<int> &nums, int n)
{

    unordered_set<int> actual(nums.begin(), nums.end());
    vector<int>ans;

    for (int i = 1; i <= n; i++)
    {

        if (actual.find(i) == actual.end())
        {

            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 3, 3, 4, 2, 5, 4, 6, 2};

    int n = nums.size();

    MissingNumbers(nums, n);

    return 0;
}