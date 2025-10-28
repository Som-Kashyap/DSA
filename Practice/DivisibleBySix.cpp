#include <iostream>
#include <vector>

using namespace std;

bool IsDivisible(long num)
{

    vector<int> digits;
    int sum = 0;

    while (num > 0)
    {
        int digit = num % 10;
        digits.push_back(digit);
        num /= 10;
    }

    for (int i = 0; i < digits.size(); i++)
    {
        sum += digits[i];
    }

    if ((digits[0] % 2 == 0) && sum % 3 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
    int main()
    {
        long num = 36;

        IsDivisible(num);

        return 0;
    }