#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int>& NGE ( vector<int>& nums ) {

    int n = nums.size();
    stack<int>st;
    vector<int>ans;
    

    for ( int i = 0; i < 2*n; i++ ) {

       int idx = i%n;

       while ( nums[idx] > nums[st.top()] ) {

        ans[st.top()] = nums[idx];
        st.pop();

       }

       if ( i < n ) {
       st.push(nums[idx]);
   } }

   return ans;
}