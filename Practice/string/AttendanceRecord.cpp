#include <iostream>
#include <string>

using namespace std;

bool Attendance(string s)
{

    int A = 0;
    int L = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] = 'A')
        {
            A++;
            L = 0;
        }
        else if (s[i] = 'L')
        {
            L++;
        }
    }

    if (A < 2 && L < 3){

        return true;
    }
    else{

        return false;
    }

}
int main()
{

    string s = "PPALLL";

    Attendance(s);

    return 0;
}