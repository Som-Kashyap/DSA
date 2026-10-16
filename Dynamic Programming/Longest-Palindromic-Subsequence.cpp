// Problem LC: 516

// Approach: The same subsequence approach is used, the solution is implemented by comparing string with its reverese order.
//           2 is added to the length if the values match and the idxs are moved, else one of the two is moved at once.

// TC and SC: O(n*n)

#include<bits/stdc++.h>

using namespace std;

int fun ( int n1, int n2, string& s, vector<vector<int>>& memo) {

        if ( n2 > n1 ) return 0;

        if ( n1 == n2 ) return 1;

        if ( memo[n1][n2] != -1 ) return memo[n1][n2];

        if ( s[n1] == s[n2] ) return memo[n1][n2] = 2 + fun ( n1-1, n2+1, s, memo );

        return memo[n1][n2] = max ( fun( n1-1, n2, s, memo ), fun(n1, n2+1, s, memo) );

    }

    int longestPalindromeSubseq(string s) {
        
        int n = s.length();

        vector<vector<int>> memo(n, vector<int>(n,-1));

        return fun (n-1, 0, s, memo);

    }