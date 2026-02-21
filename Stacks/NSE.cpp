#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

vector<int>& NextSmaller ( vector<int>& nums ) {

    vector<int>ans;
    stack<int>st;
    unordered_map<int,int>nse;
    

    for ( int i = 0; i < nums.size(); i++ ) {

        while ( !st.empty() && nums[i] <= nums[st.top()]) {

            int idx = st.top();

            nse[idx] = nums[i];

            st.pop();

        }
        st.push(nums[i]);
    }

    for ( int val : nums ) {

        ans.push_back ( nse.count(val) ? nse[val] : -1 );

    }
    return ans;
}