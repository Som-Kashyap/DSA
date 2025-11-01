#include <iostream>
#include <string>

using namespace std;

int FindIndex(string str, string s)
{

    int index = str.find(s);

    return index;
}
int main()
{

    string str = "ThisIsAString";
    string s;

    cout << "Enter string to search: " << endl;
    cin >> s;

    cout << "Index is : " << FindIndex(str, s) << endl;

    return 0;
}