#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int FirstUnique(string s)
{

    int ans=0;

    unordered_set<char> set;

    for (int i = 0; i < s.length(); i++)
    {

        if (set.find(s[i]) == set.end())
        {

            ans += i;
            return ans;
            break;
        }
        else
        {

            set.insert(s[i]);
            continue;
        }
    }

    return ans;
}

int main()
{

    string s = "";

    cout << FirstUnique(s) << endl;

    return 0;
}