// Problem LC: 70

// Approach: Memorization is used to omit the extra recursive steps for repeating cases, ways to reach steps n = sum of ways to reach the
//           prev two

// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>

using namespace std;

int climbingStairs ( int n, unordered_map<int,long long> &memo ) {

    if ( n <= 1 ) return 1;

    if ( memo.count(n) ) return memo[n];

    memo[n] = climbingStairs(n-1, memo) + climbingStairs(n-2,memo);

}

int climbingStairs(int n) {

    unordered_map<int,long long> memo;

    return climbingStairs(n,memo);

}