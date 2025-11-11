#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int KthDigit(int a, int b, int k)
{

    vector<int> digits;

    int num = pow(a, b);

    while (num > 0)
    {
        int digit = num % 10;
        digits.push_back(digit);
        digit /= 10;
    }

    return digits[k];
}
int main()
{

    int a, b, k;

    cout << "Enter base: " << endl;
    cin >> a;

    cout << "Enter pow: " << endl;
    cin >> b;

    cout << "Enter k: " << endl;
    cin >> k;

    cout << "Number at Kth position :  " <<KthDigit(a,b,k) <<endl;

    return 0;
}