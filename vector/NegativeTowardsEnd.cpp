#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NegativeTowardsEnd(vector<int> &arr)
{
    int n = arr.size();
    int st = 0, end = n - 1;
    while (st <= end)
    {
        if (arr[st] < 0 && arr[end] >= 0)
        {
            swap(arr[st], arr[end]);
            st++;
           
        }
        else if (arr[st] >= 0 && arr[end] < 0)
        {
            end--;
            st++;
        }
        else if (arr[st] < 0 && arr[end] < 0)
        {
            end--;
        }
        else if (arr[st] >= 0 && arr[end] >=0)
        {
            st++;
            
        }
    }
    for (int val : arr)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr = {0, -4, -3, 2, 1, -9,10};
    NegativeTowardsEnd(arr);
    
    return 0;
}