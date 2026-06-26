// Problem LC: 692

// Approach: min-heap is used to find top-k freq words, hash-map is used to track freq which is then passed to the heap
//           comparator is formed to sort lexicographically

// TC: O(n) + O(nlogu) + O(klogk) + O(k) => O(n+ulogk)
// SC: O(n)

#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

struct Compare{

    bool operator() ( const pair<int,string> &a , const pair<int,string> &b ) {

        if ( a.first == b.first ) return a.second < b.second;

        else return a.first>b.first;

    } 
};

vector<string> TopKFrequent ( vector<string> &words , int k ) {

    unordered_map<string,int>freq;

    for ( string s : words ) freq[s]++;

    priority_queue< pair<int,string> , vector<pair<int,string>>, Compare > pq;

    for ( auto[ w , f] : freq ) {

        pq.push ( {f , w} );

        if ( pq.size() > k ) pq.pop();

    }

    vector<string>res;

    while ( !pq.empty() ) {

        res.push_back( pq.top().second );
        pq.pop();

    }
    reverse ( res.begin() , res.end() );
    return res;
}

int main () {

    vector<string>words = {"i","love","leetcode","i","love","coding"};
    int k = 2;

    TopKFrequent(words,k);

    return 0;
}