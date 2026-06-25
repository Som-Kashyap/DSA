// Problem LC:451

// Approach: Max heap is implemented to pass frequencies of all characters from hash-map, then characters are appended to the ans string

// TC: O(N) + O(KlogK) + O(Klogk) + O(N)
// SC: O(K)

#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

string SortCharacters ( string s ) {

    unordered_map<int,char>freq;

    for ( char c : s ) freq[c]++;

    priority_queue<pair<int,char>>pq;

    for ( auto it : freq ) pq.push( {it.first , it.second} );

    string res ="";

    while ( !pq.empty() ) {

        auto [f,c] = pq.top();

        res.append( f , c );

        pq.pop();

    }
    return res;
}

int main () {

    string s = "tree";

    SortCharacters();

    return 0;

}