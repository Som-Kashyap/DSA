#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void FindDuplicates(string str)
{

    int count = 1;

    int i = 0;

    while (str[i] + count < str.length())
    {

        if (str[i] == str[i + count])
        {
            count++;
        }
        if (count > 1)
        {
            cout << "['" << str[i] << "'," << count << "]," << endl;
        }

        i += count;
    }
}
int main()
{

    string str;
    cout << "Enter a string having duplicates: " << endl;
    cin >> str;

    FindDuplicates(str);

    return 0;
}