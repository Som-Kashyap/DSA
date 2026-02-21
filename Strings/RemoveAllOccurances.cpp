#include <iostream>
#include <string>

using namespace std;

string Remove(string str, string part)
{

    while (part.length() < str.length())
    {
        str.erase(str.find(part), part.length());
    }

    return str;
}
int main()
{

    string str = "ThisIsAString";
    string part;
    cout << "Enter part to be removed: " << endl;
    cin>>part;
    cout << "Resulting string : " << Remove(str, part) << endl;

    return 0;
}