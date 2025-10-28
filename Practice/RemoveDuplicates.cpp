#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void RemoveDuplicates(vector<int> &arr)
{
    int n = arr.size();
    int st = 0, end = n - 1;
    vector<int> ans;
    while (st < end)
    {
        if (arr[st] == arr[end])
        {
            ans.push_back(arr[st]);
        }
    }
     for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
    
}
int main()
{
    vector<int> arr = {0, 0, 1, 2, 2, 3, 4, 4};
    RemoveDuplicates(arr);
   
    return 0;
}