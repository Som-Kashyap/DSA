// Problem LC: 1463

// Approach: for every move of 1st robot, there exist 3 possible moves of 2nd robot, so all these possibilities are taken into account
//           and the max is computed and returned

// TC and SC: O(n*m*m)*9, there are n*m*m recursive calls and 9 possibilites

#include<bits/stdc++.h>

using namespace std;

 int dp[70][70][70] = {};

    int dfs(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {

        if (r == m) return 0; 

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int ans = 0;

        for (int i = -1; i <= 1; i++) {

            for (int j = -1; j <= 1; j++) {

                int nc1 = c1 + i, nc2 = c2 + j;

                if (nc1 >= 0 && nc1 < n && nc2 >= 0 && nc2 < n) {

                    ans = max(ans, dfs(grid, m, n, r + 1, nc1, nc2));

                }
            }
        }

        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];

        return dp[r][c1][c2] = ans + cherries;
    }

       int cherryPickup(vector<vector<int>>& grid) {

        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return dfs(grid, m, n, 0, 0, n - 1);

    }