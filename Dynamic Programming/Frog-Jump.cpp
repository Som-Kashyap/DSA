// Problem : Frog Jump GFG

// Approach: Memoization is used along with recursion, choosing min energy expenditure path

// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>

using namespace std;

int frogJump ( vector<int>& heights, int n, vector<int>& dp ) {

   if ( n == 0 ) return 0;

   if ( n == 1 ) return heights[0];

   if ( dp[n] != -1 ) return dp[n];

   dp[n] = min (frogJump(heights, n-1, dp)+abs(heights[n]-heights[n-1]), frogJump(heights, n-2, dp)+abs(heights[n]-heights[n-2]));

   return dp[n];

}

int frogJump (vector<int>& heights, int n ) {

    vector<int> dp(n,-1);

    return frogJump(heights,n,dp);

}

// Using pointers: O(1) space

int frogJump ( vector<int>& heights, int n ) {

   if ( n == 1 ) return 0;

    int prev = abs(heights[1]-heights[0]);
    int prev2 = 0;

    for ( int i = 2; i < n; i++ ) {

        int curr = min(frogJump(heights, n-1)+abs(heights[n]-heights[n-1]), frogJump(heights,n-2)+abs(heights[n]-heights[n-2]));

        prev2 = prev;
        prev = curr;
        
    }
    return prev;

}