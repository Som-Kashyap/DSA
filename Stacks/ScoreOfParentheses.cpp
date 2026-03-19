#include<iostream>
#include<stack>

using namespace std;

int ScoreOfParentheses ( string s ){

    int score = 0;

    stack<char>st;
    
    for ( int i = 0; i < s.length(); i++ ) {

        if ( s[i] == '(' ) {

            st.push( score );
            score = 0;

        }

        score = st.top() + ( 2*score , 1 );
        st.pop();
    }
    
    return score;
}
int main () {

    string s = "(())";

    cout<<ScoreOfParentheses(s)<<endl;

    return 0;

}