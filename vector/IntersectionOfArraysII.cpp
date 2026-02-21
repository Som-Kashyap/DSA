#include <iostream>
#include <vector>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> ans;

    int st = 0;
    int end = nums2.size() - 1;

    while (st < nums1.size() && end >= 0)
    {

        if (nums1[st] == nums2[end])
        {
            ans.push_back(nums1[st]);
            st++;
            end = nums2.size() - 1;
        }

        else
        {

            end--;

            if (end == 0 && (nums1[st] != nums2[end]))
            {
                st++;
                end = nums2.size() - 1;
            }
            continue;
        }
    }
    return ans;
}

int main()
{

    vector<int> nums1 = {0, 1, 4, 5, 1, 1, 0};
    vector<int> nums2 = {9, 0, 1, 0, 4};

    intersect(nums1, nums2);

    return 0;
}