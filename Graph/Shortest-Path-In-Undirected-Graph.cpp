// Problem: Shortest path in undirected graph with unit weights

// Approach: BFS is used to check and assign distances if curr distance < prev assigned distance.
//           If a node cannot be assigned distance, it is assigned -1

// TC: O(V+e), V is number of nodes and e the number of edges
// SC: O(N)

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<int> shortestPath ( vector<vector<int>>& edges, int N, int M, int src ) {

    vector<int> distances(N);
    vector<int> adj[N];

    for ( auto it : edges ) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    for ( int i = 0; i < N; i++ ) distances[i] = INT_MAX;

    distances[src] = 0;

    queue<int> q;

    q.push ( src );

    while ( !q.empty() ) {

        int node = q.front();
        q.pop();

        for ( auto it : adj[node] ) {

            if ( distances[node] + 1 < distances[it] ) {
                distances[it] = distances[node] + 1;
                q.push(it);
            }

        }
    }

    for ( int i = 0; i < N; i++ ) {

        if ( distances[i] == INT_MAX ) distances[i] = -1;

    }

    return distances;
}