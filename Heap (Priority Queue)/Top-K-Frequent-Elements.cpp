// Problem LC: 347

// Approach: unordered_map is used to store the frequencies and a min-heap is implemented and pair is passed to it
// if size exceeds k it is popped, in the end the queue has top k frequent elements 

// TC: O(n+klogk)
// SC: O(d) , d is no of distinct elements

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        
         priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
    unordered_map<int,int>freq;

    for ( int val : nums ) freq[val] ++;

    for ( pair<int,int> val : freq ) {

        pq.push( {val.second , val.first} );

        if ( pq.size() > k ) pq.pop();

    }
    
    vector<int>res(k);

    for ( int i = k-1; i >= 0; i-- ) {
        
        res[i] = pq.top().second;
        pq.pop();

    }

    return res;
}

int main () {

    vector<int>nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int>res = topKFrequent(nums,k);

    cout<<"Top k frequent: ";

    for ( int val : res ) cout<<val<<" ";
    cout<<endl;
    
    return 0;
}