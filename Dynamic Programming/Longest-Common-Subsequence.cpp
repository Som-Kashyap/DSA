// Problem LC: 1143

// Approach: Strings are compared idx wise, if they are same, both idx are decremented recursively and returned as 1 + recurse, else, 
//           both are decremented separately, max of the two cases is returned

// TC and SC: O(n*m)

#include<bits/stdc++.h>

using namespace std;

int fun (int n1, int n2, string& text1, string& text2, vector<vector<int>>& memo) {

    if ( n1 < 0 || n2 < 0 ) return 0;

    if ( memo[n1][n2] != -1 ) return memo[n1][n2];

    if ( text1[n1] == text2[n2] ) return 1 + fun(n1-1, n2-1, text1, text2, memo);

    return max( fun(n1-1, n2, text1, text2, memo), fun(n1, n2-1, text1, text2, memo));

}

   int longestCommonSubsequence(string& text1, string& text2) {
        
        int s1 = text1.length();
        int s2 = text2.length();

        vector<vector<int>> memo( s1, vector<int>(s2,-1));

        return fun (s1-1, s2-1, text1, text2, memo);

    }