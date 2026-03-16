#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string RemoveAllDupilcates(string s)
{
    stack<int> st;
    string ans;

    int i = 0;

    while (i < s.length())
    {

        if (!st.empty() && s[i] == s[st.top()])
        {

            st.pop();
            i++;
        }
        else
        {
            st.push(i);
            i++;
        }
    }

    while (!st.empty())
    {
        ans.push_back(s[st.top()]);
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    string s = "abbaca";

    RemoveAllDupilcates(s);

    return 0;
}