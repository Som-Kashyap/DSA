#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

string removeStars ( string s ) {

   stack<char> st;

        for (char c : s) {
           
            if (c == '*' && !st.empty()) {
                st.pop();
            } else {
                st.push(c);
            }
        }
     
        string ans;
        
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
}

int main () {

    string s = "watch*this*happen***";

    string res = removeStars (s);

    cout<<res<<endl;
    
    return 0;
}