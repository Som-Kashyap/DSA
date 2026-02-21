#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// The stack stores those elements which can act as possible answers for future candidates!

vector<int> PreviousSmaller ( vector<int> nums ) {
    
    vector<int> ans(nums.size(), 0);
    stack<int>st;

    for ( int i = 0; i < nums.size(); i++ ) {

        while ( !st.empty() && st.top() >= nums[i] ) {

            st.pop();

        }

            if ( st.empty() ) {
                ans[i] = -1;
            }

            else{
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
    

    return ans;
}
int main () {

    vector<int>nums = { 2,3,1,0,6,9};

    PreviousSmaller ( nums );

    return 0;
}