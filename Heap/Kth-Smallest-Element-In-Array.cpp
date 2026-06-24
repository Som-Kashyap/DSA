//  Problem: Kth smallest in an array

// Approach: First k elements are pushed into a priority_queue and the rest are compared with the top and pushed if < pq.top(). The top element is the kth smallest.

// TC: O(klogk) for inserting in pq and O((n-k)logk) for comparing and heapifying
// SC: O(1)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int KthSmallest( vector<int>& nums , int k ) {

    priority_queue<int>pq;

    for ( int i = 0; i < k; i++ ) pq.push(nums[i]);

    for ( int i = k; i < nums.size(); i++ ) {

        if( nums[i] < pq.top() ) {
            pq.pop();
            pq.push(nums[i]);
        }

    }

    int ans = pq.top();

    return ans;

}

int main () {

    vector<int>nums = {7,10,4,20,15};
    int k = 4;

    int res = KthSmallest( nums , k );

    cout<<k<<"th smallest is: "<<res<<endl;

    return 0;

}