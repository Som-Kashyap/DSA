#include<iostream>
#include<stack>

using namespace std;

int monotone ( string s ) {

    stack<int>st;
    int count = 0;

    for ( int i = 0 ;i < s.length() ; i++ ) {
        
        if ( s[i]=='1' ){

            st.push( s[i] );

        }
        if ( !st.empty() && s[i]=='0' ) {
            st.pop();
            count++;
        }
    }
    return count;
}

int main () {

    string s = "0001000";

    cout<<"Min deletions:"<<monotone(s)<<endl;

    return 0;
}