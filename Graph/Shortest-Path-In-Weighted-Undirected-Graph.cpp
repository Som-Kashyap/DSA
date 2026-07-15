// Problem: Shortest-Path-In-Weighted-Undirected-Graph

// Approach: Dijkstra's algorithm is modified by using a parent array that stores curr parents of nodes visited,
//           Which is then used to store the path by traversing the array backward and moving to parent of curr node and so on.

// TC: O(ElogV) + O(N)
// SC: O(N)


#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

vector<int> shortestPath ( int n, int m, vector<vector<int>>& edges ) {

    vector<pair<int,int>> adj[n+1];
    vector<int> distances(n, 1e9);

    for ( auto it : edges ) {
        
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0], it[2]});

    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push( {0, 1});
    distances[1] = 0;

    vector<int> parent(n);

    for ( int i = 1; i <= n; i++ ) parent[i] = i;

    while ( !pq.empty() ) {

        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        for ( auto it : adj[node] ) {
            int val = it.first;
            int wt = it.second;

            if ( dist + wt < distances[val] ) {
                distances[val] = dist + wt;
                parent[val] = node;
                pq.push( {distances[val], val} );
            }
        }
    }
    
    if (distances[n] = 1e9) return {-1};

    vector<int> path(n);
    int node = n;

    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

    return path;
}