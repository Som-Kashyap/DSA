//Problem LC: 904

// Approach: Sliding-window is used, the array is traversed while updating freq in map, as size > 2, 1st element is removed
//           length of max subarray is maintained.

// TC: O(n)
// SC: O(u), u is the number of uniques

#include<bits/stdc++.h>

using namespace std;

int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> mp; 

        int st = 0;
        int maxLength = 0;

        for ( int end = 0; end < fruits.size(); end++ ) {

            mp[fruits[end]]++;

            while ( mp.size() > 2 ) {

                mp[fruits[st]]--;

                if ( mp[fruits[st]] == 0 ) mp.erase(fruits[st]);

                st++;
            }
            maxLength = max(maxLength, end-st+1);
        }
       return maxLength;
    }