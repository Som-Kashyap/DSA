// /Problem LC: 14

// Approach: String is sorted lexicographically,1st and last strings are compared since it has been asked for longest prefix common to all

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        
        sort( strs.begin(), strs.end() );
        
        int n = strs.size();

        string res = "";

        string s1 = strs[0];
        string s2 = strs[n-1];

        for ( int i = 0; i < min (s1.length(), s2.length()); i++ ) {

            if ( s1[i] != s2[i] ) return res;
            else res += s1[i];
            
        }
        return res;
    }