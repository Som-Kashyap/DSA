#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int IsLargest ( vector<int>& nums ) {

    int largest = INT_MIN ;
    int IdxLargest;
    int ans = -1 ;

    for ( int i = 0; i < nums.size() ; i++ ) {

        if ( nums[i]>largest ) {

            largest = nums[i];
            IdxLargest = (i) ;
            ans = IdxLargest ;
        }
    }

    for ( int j = 0 ; j<nums.size()-1; j++ ) {

        if ( 2*(nums[j])>largest ) 
        {
            ans = -1;
            
            break;

        }
        else {
        ans = IdxLargest ;
        }
        
    }
    return ans;
}

int main () {

    vector<int>nums = {3,6,1,0};

    cout<<IsLargest(nums)<<endl;

    return 0;

}