#include <iostream>
#include <vector>

using namespace std;

int Pow(int num, int x)
{

    int ans = 1;

    if (x == 1)
    {
        return num;
    }
    else if (x == 0)
    {
        return 1;
    }
    else
    {

            ans = num * Pow(num, x-1);
        
    }
    return ans;
}
int main()
{

    int num = 2;
    int x = 2;

    Pow(num, x);

    return 0;
}
