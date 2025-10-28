#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Reverse(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i >= j)
    {
        swap(arr[i], arr[j]);
        i++;j--;
    }
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {9, 8, 7, 6, 5};
    Reverse(arr);
    return 0;
}