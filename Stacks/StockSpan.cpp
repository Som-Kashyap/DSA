#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int>& StockSpan ( vector<int>& price ) {

    int n = price.size();

    vector<int>ans; // ans vector to store stock span of each index

    stack<int>st; //stack of int to store elements for which next greater has not been found yet

    for ( int i = 0; i < n ; i++ ) { //iterate through the prices vector to find next greater price for every index and to return span

        while ( !st.empty() && price[i] >= price[ st.top() ] ) {

                st.pop(); // since next greater for that element has been found and it is no longer needed since the NGE dominates others present on the right

        }

        if ( st.empty() ) {

            ans[i] = i+1; // since stock is empty so there is no greater element on the left so span is index i plus 1

        }
        else {

            ans [i] = i - st.top();

        }
        st.push(i);
    }

    return ans;

}