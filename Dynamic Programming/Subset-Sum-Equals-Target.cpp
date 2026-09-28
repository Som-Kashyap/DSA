// Problem: Subset Sum Equal To Target

// Approach: DP is used with memoization, array is traversed backward recursively and all subsets are considered following take/notTake
//           approach, OR of the two is returned

// TC and SC: O(sum*n)

#include<bits/stdc++.h>

using namespace std;

bool fun (vector<int>& arr, int idx, int sum, vector<vector<int>>& dp) {

    if ( sum == 0 ) return 1;

    if ( idx == 0 ) return arr[0] = sum;

    if ( dp[idx][sum] != -1 ) return dp[idx][sum];

    int notTake = fun ( arr, idx-1, sum, dp );

    bool take = false;

    if (arr[idx] >= sum) int take = fun ( arr, idx-1, sum-arr[idx], dp );

    return dp[idx][sum] = take | notTake;
}

 bool isSubsetSum(vector<int>& arr, int sum) {

    int n = arr.size();

    vector<vector<int>> dp ( n, vector<int>(n,-1) );

    return fun ( arr, n-1, sum, dp );

}