// Problem LC:912

// Approach: Heap sort is implemented, elements are pushed into a min-heap, 
//           then the values are assigned to the array indices as per the order of elements in the heap

// TC: O(nlogn)+O(nlogn), (logn for each element, logk for building heap where k is current size) 
// SC: O(n)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> SortArray ( vector<int> &nums ) {

    priority_queue<int,vector<int>,greater<int>> pq;

    for ( int val : nums ) pq.push(val);

    for ( int i = 0; i < nums.size(); i++ ) {

        nums[i] = pq.top();
        pq.pop();

    }
    return nums;
}

int main () {

    vector<int>nums = {5,2,3,1};

    vector<int>res = SortArray(nums);

    for ( int val : res ) cout<<val<<" ";
    cout<<endl;

    return 0;

}