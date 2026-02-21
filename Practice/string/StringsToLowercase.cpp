#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main()
{
    int ans = 0;

    string s;

    cout << "Enter string 1:- " << endl;
    getline(cin, s);

    int st = 0;
    int end = s.length();

    while (st < end)
    {

        if (!isalnum(s[st]))
            st++;

        else if (!isalnum(s[end]))
            end--;

        if (tolower(s[st]) != tolower(s[end]))
        {

            ans = 1;
            return ans;
        }
        else
        {
            st++;
            end--;
        }
    }
    return ans;
}