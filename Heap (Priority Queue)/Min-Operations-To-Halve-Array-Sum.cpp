// Problem LC: 2208

// Approach: Max-heap is used to retrieve largest element, and it is reduced to half everytime, and is decreased from the sum accordingly

// TC: O(n) + O(nlogn)
// SC: O(n)

#include<bits/stdc++.h>

using namespace std;

int halveArray(vector<int>& nums) {
        
        priority_queue<int> pq(nums.begin(), nums.end());

        int res = 0;
        int sum = 0;

        for ( int& val : nums ) sum += val;

        int halfSum = sum/2;

        while ( !pq.empty() ) {

            int val = pq.top();
            pq.pop();

            pq.push(val/2);
            res++;
            sum -= val/2;

            if ( sum <= halfSum ) return res;
        }
        return 0;
    }