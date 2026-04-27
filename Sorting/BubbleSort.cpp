#include<iostream>
#include<vector>

using namespace std;

void BubbleSort ( vector<int> &nums ) {

    int n = nums.size();

    for ( int i = 0; i < n-1; i++ ) {

        for ( int j = 0; j < n-i-1; j++ ) {

            if ( nums[j] > nums[j+1] ) {

                swap ( nums[j] , nums[j+1] );

            }
        }
    }
}

int main () {

    vector<int>nums = {1,0,5,3,2};

    BubbleSort ( nums );

    for ( int val : nums ) cout<<val<<" ";

    return 0;

}