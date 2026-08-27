// Problem LC: 2593

// Approach: Elements are stored in a min-heap, visited array is maintained, unvisited smallest elements are marked along with adjacents

// TC: O(n) - iterating + O(nlogn) - heapify 
// SC: O(n)

#include<bits/stdc++.h>

using namespace std;

 long long findScore(vector<int>& nums) {
        
        long long score = 0;

        vector<int> visit(nums.size(),0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for ( int i = 0; i < nums.size(); i++ ) pq.push({nums[i],i}); 

        while (!pq.empty() ) {

            auto it = pq.top();
            pq.pop();

            int val = it.first;
            int idx = it.second;

            if ( !visit[idx] ) {

                score += val;
                visit[idx] = 1;

                if ( idx-1 >= 0 ) visit[idx-1] = 1;
                if ( idx+1 < nums.size() ) visit[idx+1] = 1;
            }

        }
        return score;
    }