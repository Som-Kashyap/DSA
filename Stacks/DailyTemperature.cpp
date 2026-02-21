#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int>& temperature ( vector<int>& temp ) {

    int n = temp.size();
    vector<int>ans;
    stack<int>st;

    for ( int i = 0; i < n ; i++ ) {

        while ( !st.empty() && temp[i] > temp[st.top()] ) {

            st.pop();

            ans[st.top()] = i - st.top();

            

        }
        st.push(i);
    }
    return ans;
}