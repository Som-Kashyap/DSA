// Problem LC: 628

// Approach: If the array contains negatives, the max product is given by product of two smallest negatives with the max number.

// TC: O(nlogn)
// SC: O(1)

#include<bits/stdc++.h>

using namespace std;

int maxProduct ( vector<int>& nums ) {

    int n = nums.size();

    sort( nums.begin(), nums.end() );

    int ans = max ( nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1] );

    return ans;

}