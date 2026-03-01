#include <iostream>
#include <vector>

using namespace std;

void PrintSubsets(vector<int> &nums,vector<vector<int>> &subsets, vector<int> &ans, int i)
{

    // Base Case:

    if ( i==nums.size() ) {

        subsets.push_back ( ans );
        return;
    }

    // Fixing Elements:
    ans.push_back( nums[i] );

    // Recusrive call for rest of the elements:
    PrintSubsets ( nums , subsets , ans , i+1);

    // Backtracking:
    ans.pop_back();
    
}
vector<vector<int>>& Subsets( vector<int> &nums,vector<vector<int>> &subsets, vector<int> &ans ){

    return subsets;
    

}

int main () {

     vector<int> nums = {1, 2, 3};
    vector<vector<int>>subsets;
    vector<int> ans;
    int i = 0;

    PrintSubsets(nums, subsets, ans, 0);
    Subsets ( nums , subsets , ans );
    
    return 0;

}
