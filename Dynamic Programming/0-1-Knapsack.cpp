// Problem: 0/1 Knapsack

// Approach: Greedy approach fails because a case might arise where higher score indices might fall short on total score
//           So all possibilities are taken into account using recursion ( pick/not-pick )

// TC and SC: O(n*W)

#include<bits/stdc++.h>

using namespace std;

int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>>& memo) {

    if ( n == 0 || W == 0 ) return 0;

    if ( memo[n][W] != -1 ) return memo[n][W];

    int take = 0;

    if ( wt[n-1] <= W ) take = val[n-1] + knapsackRec( W-wt[n], val, wt, n-1, memo );

    int notTake = 0 + knapsackRec( W, val, wt, n-1, memo );

    return memo[n][W] = max ( take, notTake );

}

int fun (int W, vector<int> &val, vector<int> &wt, int n) {

    int sz = val.size();

    vector<vector<int>> memo(sz,vector<int>(sz,-1));

    return knapsackRec(W, val, wt, n, memo );

}