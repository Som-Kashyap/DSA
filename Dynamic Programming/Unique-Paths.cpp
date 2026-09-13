// Problem LC: 62

// Approach: grid is traversed from last cell to 1st, recursive calls are made for up and left movements, sum is returned as no of paths

// TC: O(m*n)
// SC: O(m*n)

#include<bits/stdc++.h>

using namespace std;

int uniquePaths ( int i, int j, vector<vector<int>>& dp) {

    if ( i == 0 && j == 0 ) return 1;

    if ( i < 0 || j < 0 ) return 0;

    if ( dp[i][j] != -1 ) return dp[i][j];

    int top = uniquePaths ( i-1, j, dp );
    int left = uniquePaths ( i, j-1, dp );

    return dp[i][j] = top + left;

}

int func ( int m, int n ) {

    vector<vector<int>> dp ( m, vector<int>(n,-1) );

    return uniquePaths(m-1,n-1,dp);

}