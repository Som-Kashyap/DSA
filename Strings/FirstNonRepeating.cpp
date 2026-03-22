#include <iostream>
#include <string>

using namespace std;

// if str[st]!=str[end] for any index , ans = that char.

char NonRepeating(string str)
{

    char ans;

    int st = 0, end = str.length() - 1;

    while (st < end)
    {

        if (str[st] != str[end])
        {
            end--;
            ans = 'str[st]';
        }
        else
        {
            st++;
            end = str.length() - 1;
        }
    }

    return ans;
}
int main()
{

    string str;
    cout << "Enter a repeating string : " << endl;
    getline(cin, str);

    cout << "First non-repeating character is : " << NonRepeating(str) << endl;

    return 0;
}