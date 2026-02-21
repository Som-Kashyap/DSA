#include <iostream>
#include <vector>
#include<climits>

using namespace std;

int MoveZeroes(vector<int> &nums , int target)
{
     int ans=0;
        int smallest = INT_MAX;
        int diff = 0;

        for  ( int i = 0; i<nums.size() ; i++ ){

            if ( nums[i]<target ){

                diff = abs(target-nums[i]);

                if ( diff<smallest ){
                    smallest = diff;
                    ans = (i+1);
                }
            }
            if (nums[i]==target ){
                ans = i;
            }
        }
        return ans;
    

   

}
int main()
{

    vector<int> nums = {1,3,5,5,6};
    int target = 7;
    MoveZeroes(nums,target);

    return 0;
}