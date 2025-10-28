#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int FindingDuplicates(vector<int> &arr)
{
    int n = arr.size();

    vector<int> freq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int val : arr)
    {
        if (freq[val] > 1)
        {
            ans.push_back(val);
        }
    }
    for (int val : ans)
    {
        return val;
    }
}
int main()
{
    vector<int> arr = {1, 1, 3, 4, 2, 5, 2};
    cout << "Duplicates: " << FindingDuplicates(arr) << endl;
    return 0;
}