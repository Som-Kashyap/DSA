// Problem: Dijkstra's Algorithm

// Approach: Distances of each node from src are initialized as infinity, min-heap of pair<int,int> is used and elements are
//           sorted distance-wise, graph is traversed and distances are assigned where they are less than prev distances.

// TC: ElogV (E -> edges, V->nodes)
// SC: O(N)

#include<iostream>
#include<queue>
#include<vector>
#include<climits>

using namespace std;

vector<int> dijkstra ( int N, vector<vector<int>> adj[], int S ) {

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> distances(N);

    for ( int i = 0; i < N; i++ ) distances[i] = INT_MAX;

    pq.push ( {0, S} );

    while ( !pq.empty() ) {

        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for ( auto it : adj[node] ) {
            int wt = it[1];
            int val = it[0];

            if ( dist + wt < distances[val] ) {
                distances[val] = dist + wt;
                pq.push ( {distances[val], val} );
            }
        }
    }

    return distances;
}