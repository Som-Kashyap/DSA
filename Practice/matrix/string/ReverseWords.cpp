#include <iostream>
#include <string>

using namespace std;

string Reverse(string str)
{

    int st = 0, end = str.length() - 1;

    while (st < end)
    {
        if (str[st] != '.')
        {
            st++;
        }
        else
        {
            if (end == '.')
            {
                swap(str[st--], str[end--]);
            }
            else
            {
                end--;
            }
        }
    }

    return str;
}
int main()
{

    string str;
    cout << "Enter a string with words separated by fullstops: " << endl;
    getline(cin, str);

    cout << "Resulting string is: " <<Reverse(str)<< endl;

    return 0;
}