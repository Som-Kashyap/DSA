#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string TypeOfTraingle(vector<int> &sides)
{

    string ans;
    int EqualSides;

    sort(sides.begin(), sides.end());

    for (int i = 0; i < sides.size(); i++)
    {

        if ((sides[0] + sides[1]) < sides[2])
        {
            ans = "none";
        }
        if (sides[i] == sides[i + 1])
        {

            EqualSides++;
        }
    }

    if (EqualSides == 3)
    {
        ans = "equilateral";
    }
    else if (EqualSides == 2)
    {
        ans = "isosceles";
    }
    else
    {
        ans = "scalene";
    }

    return ans;
}
int main() {

    vector<int>sides={3,3,3};

    TypeOfTraingle(sides);

    return 0;
}