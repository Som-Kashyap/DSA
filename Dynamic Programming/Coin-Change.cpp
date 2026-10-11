// Problem LC: 322

// Approach: There are infinite no of each type of coins, so we can pick multiple coins from indices, hence we don't move until we can't 
//           pick any more coins from that idx
//           All possibilities, take/not-take are considered and min number of coins are returned

// TC and SC: O(n*amount)

#include<bits/stdc++.h>

using namespace std;

    int fun(int n, vector<int>& coins, int amount, vector<vector<int>>& memo) {

        if (n == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }

        if (memo[n][amount] != -1) return memo[n][amount];

        int notTake = fun(n-1, coins, amount, memo);

        int take = INT_MAX;

        if (coins[n] <= amount) take = 1 + fun(n, coins, amount - coins[n], memo);

        return memo[n][amount] = min(notTake, take);
    }

int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        
        vector<vector<int>> memo(n, vector<int>(amount+1, -1));

        int ans = fun(n-1, coins, amount, memo);

        return (ans >= 1e9) ? -1 : ans;
    }
