// Problem : Max Path Sum In A Matrix

// Approach: DP is used, for every cell of every row, all possibilities are calculated and max is taken

// TC and SC: O(m*n)

#include<bits/stdc++.h>

using namespace std;

int maxSum ( vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp ) {

    if ( i == mat.size()-1  ) return mat[i][j];

    if ( j > mat[0].size() || j < 0 ) return -1e9 ;

    if ( dp[i][j] != -1 ) return dp[i][j];

    int down = mat[i][j] + maxSum ( mat, i+1, j, dp );

    int right = mat[i][j] + maxSum ( mat, i+1, j+1, dp );

    int left = mat[i][j] + maxSum ( mat, i+1, j-1, dp );

    return dp[i][j] = max (down, max(right, left));

}

int fun ( vector<vector<int>>& mat ) {

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp ( n, vector<int> (m,-1) );

    for ( int i = 0; i < m; i++ ) {
        return ( mat, 0, 0, dp );
    }
}