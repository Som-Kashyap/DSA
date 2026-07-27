// Problem LC: 1207

// Approach: Hash-map is used to store frequencies of elements, it is then iterated and checked for duplicate freq using set.

// TC: O(n)
// SC: O(n)

#include<bits/stdc++.h>

using namespace std;

 bool uniqueOccurrences(vector<int>& arr) {
      
      unordered_map<int,int> freq;
      unordered_set<int>s;

      for ( int val : arr ) freq[val]++;

      for ( auto it = freq.begin(); it != freq.end(); it++ ) {

            if ( s.count(it->second) ) return false;

            else s.insert(it->second);

      }
      return true;
    }