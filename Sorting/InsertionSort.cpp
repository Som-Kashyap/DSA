#include<iostream>
#include<vector>

using namespace std;

void InsertionSort ( vector<int> &nums ) {

    int n = nums.size();

    int key;
    int j;

    for ( int i = 1; i < n; i++ ) {

        key = nums[i];

        j = i-1;

        while ( j >= 0 && nums[j] > key ) {

            nums[j+1] = nums[j];

            j--;

        }

        swap ( nums[j+1] , key );

    }
}

int main () {

    vector<int>nums = {0,5,3,2,4};

    InsertionSort ( nums );

    for ( int val : nums ) cout<<val<<" ";

    return 0;
    
}