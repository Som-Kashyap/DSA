// Problem LC: 2099

// Approach: Min-heap is used to store values and indices, the last k elements belong to the rquired subsequence.
//           indices are pushed to res vector and sorted to maintain the correct order of elements as per nums vector

// TC: O(n)+O(nlogk)+(klogk)+O(k)
// SC: O(k)

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for ( int i = 0; i < nums.size(); i++ ) {

            pq.push ( { nums[i] , i } );

            if ( pq.size() > k ) pq.pop();

        }

        vector<int>res(k);

        for ( int i = 0; i < k; i++ ) {

            res[i] = pq.top().second;
            pq.pop();

        }

        sort ( res.begin() , res.end() );

        for ( int i = 0; i < res.size(); i++ ) res[i] = nums[res[i]]; 
            
        return res;
    }

    int main () {

        vector<int>nums = {2,1,3,3};
        int k = 2;

        vector<int>ans = maxSubsequence( nums , k );

        for ( int val : ans ) cout<<val<<" ";
        cout<<endl;

        return 0;

    }