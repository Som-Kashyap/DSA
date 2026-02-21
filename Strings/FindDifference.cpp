#include <iostream>
#include <string>

using namespace std;

char Difference(string s, string t)
{

    int m = s.length();
    int n = t.length();
    char ans;

    if (m > n)
    {
        ans = s[m - 1];
    }
    else if (m < n)
    {
        ans = t[n - 1];
    }

    return ans;
}
int main()
{

    string s = "abcde";
    string t = "abcdef0";

    cout << "Difference= " << Difference(s, t) << endl;

    return 0;
}