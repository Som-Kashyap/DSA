// Problem: Count Subsets With Sum K

// Approach: DP is used, inclusion/exclusion approach is applied and sum of the two is retuned

// TC and SC: O(n*target), there are n*target possible states

#include<bits/stdc++.h>

using namespace std;

int countSubsets(int i, int currentSum, int target, vector<int> &arr, vector<vector<int>> &dp) {

    if ( i == 0 ) return ( arr[i] == currentSum );

    if ( dp[i][currentSum] != -1 ) return dp[i][currentSum];

    int notTake = countSubsets(i-1, currentSum, target, arr, dp);

    int take = 0;

    if ( arr[i] <= currentSum ) take = countSubsets(i-1, currentSum-arr[i], target, arr, dp);

    return dp[i][currentSum] = take + notTake;

}

int func(int target, vector<int> &arr) {

    int n = arr.size();

    vector<vector<int>> dp ( n+1, vector<int>(target+1, -1) );

    return countSubsets(n,target, target, arr, dp);

}