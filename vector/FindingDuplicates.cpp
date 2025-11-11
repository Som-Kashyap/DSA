#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>


using namespace std;

int Duplicates(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
       

        if (s.find(arr[i]) != s.end())
        {
            ans.push_back(arr[i]);
            continue;
          
        }
        s.insert(arr[i]);
    }
    for (int val : ans)
    {
        return val;
    }
}
int main()
{
    vector<int> arr = {2, 1, 4, 5, 5,9,9};
    cout << Duplicates(arr) << endl;
    return 0;
}