// Problem LC: 167

// Approach: Two-pointers are used, since array is sorted, if sum < tar, st++ else end--.

// TC: O (logn)
// SC: O(1)

#include<bits/stdc++.h>

using namespace std;

 vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();

        int st = 0, end = n-1;

        int sum = 0;

        while ( st < end ) {

            sum = numbers[st] + numbers[end];

            if ( sum == target ) return {st+1,end+1};

            else if ( sum < target ) st++;

            else end--;
        }
        return {};
    }