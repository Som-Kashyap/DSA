// Problem: Unbounded kanpsack - unlimited items

// TC and SC: O(n*capacity)

#include<bits/stdc++.h>

using namespace std;

int knapSackRecur(int n, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>>& memo) {

    if ( n == val.size() ) return 0;

    if ( memo[n][capacity] != -1 ) return memo[n][capacity];

    int notTake = knapSackRecur(n+1,capacity, val, wt, memo);

    int take = 0;

    if ( wt[n] <= capacity ) take = val[n] + knapSackRecur(n, capacity-wt[n], val, wt, memo );

    return memo[n][capacity] = max( take, notTake );

}

int fun (int n, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>>& memo) {

    int n = val.size();

    vector<vector<int>> memo(n, vector<int>(capacity+1,-1));

    return knapSackRecur(0, capacity,val, wt, memo);

}