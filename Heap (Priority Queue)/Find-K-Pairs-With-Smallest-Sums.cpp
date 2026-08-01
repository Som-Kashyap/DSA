// Problem LC: 373

// Approach: A min-heap is maintained and the arrays are traversed to populate the heap till size < k, else the sum is compared
//           with the top and only smaller values are pushed, then it is iterated to return the required pairs

// TC: O (m*n*logk)
// SC: O (k)

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;


    pq.push ( {nums1[0]+nums2[0],{0,0}} );

    for ( int i = 0; i < nums1.size(); i++ ) {

        for ( int j = 0; j < nums2.size(); j++ ) {

            int sum = nums1[i] + nums2[j];

            if ( pq.size() < k ) {

                pq.push ( { sum, {i,j}} );

            }

            else if ( sum < pq.top().first ) {

                    pq.pop();
                    pq.push({sum, {i,j}});

                }

            else {
                break;
            }
        }
    }

    vector<vector<int>> res;

    while ( !pq.empty() ) {

        res.push_back( {pq.top().second.first, pq.top().second.second} );
        pq.pop();

    }

    reverse( res.begin(), res.end() );

    return res;

}