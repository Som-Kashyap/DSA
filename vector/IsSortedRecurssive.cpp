#include<iostream>
#include<vector>

using namespace std;

bool IsSorted ( vector<int>& nums , int m) {


    for ( int i = m; i>=0; i-- ) {

        if ( nums[i-1]<=nums[i]) {

            return IsSorted(nums , m-1);

        }

        return false;
    }

}