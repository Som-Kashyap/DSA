// Problem LC: 64

// Approach: up and left path sum are calculated recursively and min of the two is taken

// TC and SC : O(m*n)

#include<bits/stdc++.h>
using namespace std;

 int fun ( vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp ) {

        if ( row == 0 && col == 0 ) return grid[0][0];

        if ( row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ) return INT_MAX;

        if ( dp[row][col] != -1 ) return dp[row][col];

        int up =  fun ( grid, row-1, col, dp );
        int left = fun ( grid, row, col-1, dp );

        return dp[row][col] = grid[row][col] + min ( up, left );

    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp ( m, vector<int> (n,-1));

        return fun ( grid, m-1, n-1, dp );

    }