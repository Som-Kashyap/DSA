// Problem LC: 3080

// Approach: Min-heap is used to retrive smallest elements, its elements are retrived and k smallest are marked if unmarked (smallest idx first)

// TC: O(n) + O(nlogn) + O(k)(size-of-queries)
// SC: O(n)

#include<bits/stdc++.h>

using namespace std;

vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> marked(nums.size(),0);

        long long sum = 0;

        for ( int& val : nums ) sum += val;

        vector<long long> res;

        for ( int i = 0; i < nums.size(); i++ ) pq.push({nums[i],i});

            for ( auto& it : queries ) {

                int k = 0;

                int idx = it[0];
                int freq = it[1];

                if (!marked[idx]) {
                    marked[idx] = 1;
                    sum -= nums[idx];
                }

                while ( !pq.empty() && k < freq ) {

                    auto it = pq.top();
                    int val = it.first;
                    int index = it.second;
                    pq.pop();
                    
                    if ( !marked[index] ) {
                        marked[index] = 1;
                        k++;
                        sum -= val;
                    }
                
                }
                res.push_back(sum);
            }
            return res;
    }