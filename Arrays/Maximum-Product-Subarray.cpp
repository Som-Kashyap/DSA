// Problem LC: 152

// Approach: res is initialized with max element, currMax and currMin are maintained as min*n > max*n for negative n so we need both
//           array is traversed and max of the pro with currMax, currMin and n is taken as currMin, min of the same as currMin
//           n being max means the prev subarray is omitted

// TC: O(N)
// SC: O(1)

#include<bits/stdc++.h>

using namespace std;

int maxPro ( vector<int> &nums ) {

    int res = *max_element(nums.begin(), nums.end());

    int currMax = 1, currMin = 1;

    for ( int n : nums ) {

        int temp1 = currMax*n;
        int temp2 = currMin*n;

        currMax = max( {n, temp1, temp2} );
        currMin = min( {n, temp1, temp2} );

        res = max( res, currMax );
    }

    return res;
}