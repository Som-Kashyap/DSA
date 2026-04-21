#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

vector<int> TopKFrequent(vector<int> &nums, int k)
{

    unordered_map<int, int> freq;
    vector<int> ans;

    for (int val : nums)
    {
        freq[val]++;
    }

    int max = -1;

    int ptr = 0;

    while (ptr < k)
    {
        for (int i = 0; i < nums.size(); i++)
        {

            if (freq[i] > max)
            {
                max = nums[i];
                ans.push_back(max);
                freq[i] = -2;
                ptr++;

            }
        }
    }
    return ans;
}

int main () {

    vector<int>nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int>res = TopKFrequent ( nums , k );
    
    for ( int val:res ) {
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}