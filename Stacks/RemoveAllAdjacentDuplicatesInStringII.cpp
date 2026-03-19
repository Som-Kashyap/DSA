#include<iostream>
#include<algorithm>
#include<stack>
#include<utility>

using namespace std;

void RemoveAdjacentDuplicates ( string s , int k , int n ) {

    int count = 1;
    int i = 0;
    stack<int>st;
    pair<char,int>freq;
    string ans;

    

    while ( i < s.length() ){

        if ( !st.empty() && (s[i]==st.top() )) {

            count++;

            if ( count==k ){
                st.pop();
                i++;
                count = 1;
            }
            else{
            i++;
            }
        }
        count = 1;
        st.push( s[i] );
        i++;
    }
    
    while ( !st.empty() ) {
        ans.push_back ( st.top() );
        st.pop();
    }

    reverse ( ans.begin() , ans.end() );

    cout<<ans<<endl;
}
int main () {

    string s = "deeedbbcccbdaa";
    int k = 3;
    int n = s.length();

    RemoveAdjacentDuplicates ( s , k , n );

    return 0;
}