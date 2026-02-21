#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

vector<int>& NGE ( vector<int>& nums1 , vector<int>& nums2 ) {

    vector<int>ans;
    unordered_map<int , int>nge; // stores NGE of each element present in nums2
    stack<int>st;  // stores those elements of nums1 whose NGE has not been found

    for ( int val : nums2 ) {

        while ( !st.empty() && st.top() < val ) {

            nge[st.top()] = val; // storing NGE of that particular element
            
            st.pop();
         

        }
        st.push ( val );
    }

    for ( int x : nums1 ) {
        ans.push_back( nge.count(x) ? nge[x] : -1);
    }
    return ans;
}