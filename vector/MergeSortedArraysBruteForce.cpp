#include <iostream>
#include <vector>

using namespace std;

vector<int> &Merge(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < nums1.size() && j < nums2.size())
    {

        if (nums1[i] < nums2[j])
        {

            ans.push_back(nums1[i]);
            i++;
        }
        else if (nums1[i] > nums2[j])
        {

            ans.push_back(nums2[j]);
            j++;
        }
        else
        {
            ans.push_back(nums1[i]);
            i++;
        }
    }
    
    for ( int val : ans ) {

        cout<<val<<" ";

    }
    cout<<endl;
}
int main()
{

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 2, 3, 4};

    Merge(nums1, nums2);

    return 0;
}