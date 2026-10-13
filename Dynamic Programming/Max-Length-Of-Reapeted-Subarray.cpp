// Problem LC: 718

// Approach: Tabulation is used, the arrays are traversed and compared and 1 is added to already existing subarray length and max is
//           maintained.

// TC and SC: O(m*n)

#include<bits/stdc++.h>

using namespace std;

int findLength(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size();
    int m = nums2.size();

    vector<vector<int>> dp(n, vector<int>(m,0));

    int ans = 0;

    for ( int i = 1; i <= n; i++ ) {

        for ( int j = 1; j <= n; j++ ) {

            if ( nums1[i-1] == nums2[j-1] ) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }

            else dp[i][j] = 0;
        }
    }
    return ans;
}