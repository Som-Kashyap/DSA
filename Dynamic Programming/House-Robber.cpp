// Problem LC: 198

// Approach: Memoization is used along with take / notTake cases, max of the two is considered
// Better: use pointers instead

// TC and SC: O(n)

#include<bits/stdc++.h>

using namespace std;

int rob (vector<int>& nums,int n,vector<int>& dp) {

    if ( n == 0 ) return nums[n];

    if ( n < 0 ) return 0;

    if ( dp[n] != -1 ) return dp[n];

    int take = nums[n] + rob(nums, n-2, dp);
    int notTake = rob(nums,n-1,dp);

    return dp[n] = max( take, notTake );

}

int rob (vector<int>& nums) {

    vector<int> dp(nums.size()+1,-1);

    return rob( nums, nums.size(), dp );
}