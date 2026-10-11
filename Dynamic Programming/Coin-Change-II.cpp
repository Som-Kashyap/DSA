// Problem LC: 518

// Approach: Instead of min coins, number of ways are returned

// TC and SC: O(n*amount)

#include<bits/stdc++.h>

using namespace std;

  int fun (int n, int amount, vector<int>& coins, vector<vector<unsigned long long>>& memo) {

        if ( n == 0 ) {
            if ( amount%coins[0] == 0 ) return 1;

            else return 0;
        }

        if ( memo[n][amount] != -1 ) return memo[n][amount];

        int notTake = 0 + fun(n-1, amount, coins, memo);

        int take = 0;

        if (coins[n] <= amount) take = fun(n, amount-coins[n], coins, memo);

        return memo[n][amount] = take + notTake;

    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<vector<unsigned long long>> memo (n, vector<unsigned long long>(amount+1, -1));

        return fun(n-1, amount, coins, memo);

    }