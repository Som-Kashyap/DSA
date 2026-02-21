#include<iostream>
#include<vector>
#include<climits>

using namespace std;

 int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int freq = 1;
        int MaxFreq = INT_MIN ;

        for ( int i = 0 ; i<nums.size() ; i++ ) {

            if ( (nums[i]==1) ) {
                if ( nums[i+1]==1 ){
                freq++;
                }
                    else {
                freq=1;
            }
            } 
            if ( freq>MaxFreq ) {
                MaxFreq = freq;
            }
         }
         return MaxFreq;
    }

    int main () {

        vector<int>nums={0,1,0,1,1,1,1 ,0,1};

        cout<<findMaxConsecutiveOnes(nums)<<endl;

        return 0;
    }