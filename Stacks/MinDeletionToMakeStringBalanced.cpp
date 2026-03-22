#include<iostream>
#include<stack>

using namespace std;

int deletions ( string s ) {

    int n = s.length();
    stack<int>st;
    int count = 0;

    int i = 0;

    for( i; i < n; i++ ){

        if ( s[i]=='b' ) {
            st.push( s[i] );
         
        }
        if ( !st.empty() && s[i]=='a' && st.top()=='b' ) {
            st.pop();
            count++;
        }
    }

    return count;
}

int main () {

    string s = "aaaaabbbbbbaaaa";

    cout<<"Min deletions: "<<deletions(s)<<endl;

    return 0;
}