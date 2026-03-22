#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int ShortestSubarray ( vector<int>&nums ) {

    int left = 0, right = nums.size()-1; int n = nums.size();

    while ( left < nums.size() && nums[left]<=nums[left+1] ) {
        left++;
    }
    while ( right > 0 && nums[right]>=nums[right-1] ) {
        right--;
    }

    if ( left == nums.size() - 1 ) return 0; //whole array is sorted

    int length = min( n - left - 1 , right); //if middile has to be removed

    int i = 0 , j = right;

    while ( i <= left && j < n ) {

        if ( nums[i]<=nums[j] ){
        length = min ( j-i-1, length );
        i++;
        }
        j++;
        
    }
    return length;

}

int main () {

    vector<int>nums{5,6,7,1,9,2,3,4,10};

    cout<<ShortestSubarray ( nums )<<endl;

    return 0;
}