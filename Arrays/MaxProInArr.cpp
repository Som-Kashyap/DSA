#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxPro(vector<int> &arr)
{
    int MaxPro = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int pro = arr[i] * arr[j];
            MaxPro = max(pro, MaxPro);
        }
    }
    return MaxPro;
}
int main()
{
    vector<int> arr = {5, 6, 1, 4, 7};
    cout << "Max product: " << MaxPro(arr) << endl;
    return 0;
}