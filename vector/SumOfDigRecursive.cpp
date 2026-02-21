#include <iostream>
#include <vector>

using namespace std;

int DigSum(int num)
{

    vector<int> digits;
    int sum = 0;

    while (num > 0)
    {

        int digit = num % 10;
        digits.push_back(digit);

        DigSum(num / 10);
    }

    for (int val : digits)
    {
        sum += val;
    }

    return sum;
}
int main()
{

    int num = 123;

    DigSum(num);

    return 0;
}