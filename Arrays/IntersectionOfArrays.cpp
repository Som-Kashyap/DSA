#include <iostream>
#include <vector>
#include <unordered_set>
#include<algorithm>

using namespace std;

vector<int> &Intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int>ans;

    // sorting to prevent traversing whole array for each element
    sort ( nums1.begin() , nums1.end());
    sort ( nums2.begin() , nums2.end());

    int i , j = 0;

    while ( i < nums1.size() && j < nums2.size() ) {

        if ( nums1[i]==nums2[j] ) {
            ans.push_back(nums1[i]);
            i++ ; j++ ;
        }
         if ( nums1[i] > nums2[j] ) {
            j++ ;
         }
         else {
            i++;
         }
    }

    for ( int val : ans ) {

        cout<<val<<" ";
    
    }
    cout<<endl;

}
int main () {

    vector<int>nums1 = {1,2,2,1};
    vector<int>nums2 = {2,2};

    Intersection ( nums1 , nums2) ;

    return 0;
}