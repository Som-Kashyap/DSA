//  Problem LC: 1985

// Approach: pq of pair is used to store { s.size() , s } and compares lexicographically if the length is same.

// TC: O(nlogk)
// SC: O(k)

#include<iostream>
#include<queue>

using namespace std;

string kthlargest ( vector<string> &nums , int k ) {

    priority_queue<pair<int,string> , vector<pair<int,string>> , greater<pair<int,string>>> pq; 

     for ( string s : nums) {   //O(nlogk) 

        pq.push( { s.size() , s } );

        if ( pq.size() > k ) pq.pop();

     }

     string res = ( pq.top().second );

     return res;
}

int main () {

    vector<string>nums = {"3","6","7","10"};
    int k = 4;

    string ans = kthlargest( nums , k );

    cout<<k<<"th largest: "<<ans<<endl;

    return 0;

}