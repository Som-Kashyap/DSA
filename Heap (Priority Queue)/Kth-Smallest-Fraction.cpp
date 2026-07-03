// Problem LC: 786

// Approach: Max-heap is used to store fractions, sorted wrt value of fractions, top represents the kth smallest

//  TC: O(n*nlogk)
//  SC: O(k)

//Optimization: Use cross multiplication in the comparator instead of double to avoid floating-point precision issues.

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

 vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        priority_queue<pair<double, pair<int, int>>> maxHeap;
        int n = arr.size();

        for(int i = 0; i < n - 1; i++) {

            for(int j =i + 1; j < n; j++) {

                maxHeap.push({((double) arr[i] / arr[j]), {arr[i], arr[j]}});

                if(maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
            
        }

        auto res = maxHeap.top().second;
        return {res.first, res.second};
    }

    int main () {

        vector<int>arr = {1,2,3,5};
        int k = 3;

        vector<int>ans = kthSmallestPrimeFraction( arr , k );

        for ( int val : ans ) cout<<val<<" "; 
        cout<<endl;

        return 0;
    }