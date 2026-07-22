// Problem: Prim's Algorithm

// Approach: Min-heap is used to traverse and store adj nodes starting from 0, visited and parent array are maintained for every
//           node, edges are sorted in terms of edge-wt so the resulting tree is MST.

// TC: O(ElogE) {pop} + O(ElogE) {traversal + push
// SC: O(E)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int,int>> MST ( int n, vector<vector<int>> adj[] ) {

    vector<int> visited(n,0);

    priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

    vector<pair<int,int>> mstEdges;

    pq.push( {0,{0,-1}} );

    while ( !pq.empty() ) {

        auto it = pq.top();
        pq.pop();

        int node = it.second.first;
        int wt = it.first;
        int parent = it.second.second;

        visited[node] = 1;
        mstEdges.push_back( {parent, node} );

        for ( auto x : adj[node] ) {

            if ( !visited[x[1]] ) {
                pq.push ( {x[2], {x[1], node}} );

            }
        }
    }
    return mstEdges;
}