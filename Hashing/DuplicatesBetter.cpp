#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> FindingDuplicates(vector<int> &nums)
{

   unordered_map<int, int> freq;
   vector<int> ans;

   for (int val : nums)
   {
      freq[val]++;
   }

   for (int x : nums)
   {

      if (freq[x] > 1)
      {
         ans.push_back(x);
      }
   }
   return ans;
}
int main()
{

   vector<int> nums = {2, 2, 3, 1, 4, 5, 6, 5};

   FindingDuplicates(nums);

   return 0;
}