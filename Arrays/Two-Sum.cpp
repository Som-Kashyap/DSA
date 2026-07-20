// Problem LC: 1

// Approach: A hash-map is used to store indices of all the elements, array is iterated and complement is searched in the map
//           for a specific index, if found, indices are returned

// TC: O(n)
// SC: O(n)

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> twoSum ( vector<int> &nums, int target ) {

    int n = nums.size();

    unordered_map<int,int> mp;

    for ( int i = 0; i < n; i++ ) mp[nums[i]] = i;

    for ( int i = 0; i < n; i++ ) {

        int complement = target - nums[i];

        if ( mp.count( complement ) && mp[complement] != i ) return {i,mp[complement]};

    }

    return {};

}