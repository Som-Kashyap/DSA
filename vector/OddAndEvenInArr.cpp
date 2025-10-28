#include <iostream>
#include <vector>

using namespace std;

pair<int,int> OddAndEvenInArr(vector<int> arr, int n)
{

    int odd=0, even=0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
   
    return {odd,even};
}
int main()
{

    vector<int> arr = {2, 3, 4, 5, 6};
    int n = arr.size();
    pair<int ,int>ans = OddAndEvenInArr(arr,n);

   cout<<ans.first<<" "<<ans.second;

    return 0;
}