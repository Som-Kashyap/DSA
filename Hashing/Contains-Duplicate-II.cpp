// Problem LC: 219

// Approach: Sliding Window of length k is maintained and if the curr element is there in the set, duplicate is found within k.
//           kth element from curr index is removed is the window overflows.

// TC: O(n)
// SC: O(k)

#include<bits/stdc++.h>

using namespace std;

bool containsDuplicate ( vector<int>& nums, int k ) {

    unordered_set<int>s;

    for ( int i = 0; i < nums.size(); i++ ) {

        if ( i > k ) {

            s.erase( nums[i-k-1] );

        }

        if ( s.count( nums[i] ) ) return true;

        s.insert( nums[i] );
    }

    return false;

}