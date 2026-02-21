#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string ReverseVowels(string s)
{

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    int st = 0;
    int end = s.length() - 1;

    while (st < end)
    {

        if (vowels.find(s[end]) == vowels.end())
        {
            end--;
        }
        else if (vowels.find(s[st]) == vowels.end())
        {
            st++;
        }
        if (vowels.find(s[st]) != vowels.end() && vowels.find(s[end]) != vowels.end())
        {
            swap(s[st], s[end]);
            st++;
            end--;
        }
    }

    return s;
}
int main()
{

    string s = "SomKashyAp";

    ReverseVowels(s);

    return 0;
}