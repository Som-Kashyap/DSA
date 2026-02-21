#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int> &nums,int st , int end)
{

    if ( st <= end)
    {

        cout << nums[end] << endl;

        Reverse(nums, 0 ,end-1);
    }

    return;
}
int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};

    Reverse(nums, 0 , nums.size());

    return 0;
}