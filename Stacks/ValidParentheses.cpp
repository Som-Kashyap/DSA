#include<iostream>
#include<stack>

using namespace std;

bool ValidParentheses ( string s ) {

    stack<char>st;

    for ( int i = 0; i < s.length(); i++ ) {

        if ( s[i]=='[' || s[i]=='{' || s[i]=='(' ){
            st.push(s[i]);
        }
        else {

            while ( !st.empty() ) {

            if ( s[i]==')' && st.top()=='(' ) {
                st.pop();
                
            }

            else if ( s[i]==']' && st.top()=='['){
                st.pop();
            }

            else if ( s[i]=='}' && st.top()=='{' ) {
                st.pop();
            }
            else{
                return false;
                break;
            }
        }

        
    }
}
        return true;
}