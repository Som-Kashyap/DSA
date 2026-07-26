// Problem LC: 389

// Approach: Different char is the difference bw sum of ascii values of characters of the two strings.

// TC: O(n)
// SC: O(1)

#include<bits/stdc++.h>

using namespace std;

char findTheDifference(string s, string t) {
        
        int sum1 = 0;
        int sum2 = 0;

        for ( char c : s ) sum1 += c;

        for ( char c : t ) sum2 += c;

        return sum2-sum1;
      
    }