#include <iostream>
#include <string>

using namespace std;

string reverse(string str)
{

    int st = 0, end = str.length() - 1;

    while (st < end)
    {
        swap(str[st], str[end]);
        st++;end--;
    }

    return str;
}
int main()
{

    string str;
    cout << "Enter string to be reversed: " << endl;
    getline(cin,str);

    cout<<"Reversed string : "<<reverse(str)<<endl;

    return 0;
}