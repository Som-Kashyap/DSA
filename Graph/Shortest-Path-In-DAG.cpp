// Problem : Shortest Path in a DAG

// Approach: adj-list of vector of pair is used to store adj node and the edge wt, topological sort (dfs) is used

// TC and SC: O(v+e)

#include<iostream>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

void topologicalSort (int node, int N,vector<pair<int,int>> adj[], vector<int>& visited, stack<int>& st ) {

    visited[node]++;

    for ( auto it : adj[node] ) {

         int v = it.first;

        if ( !visited[v] ) {
            topologicalSort( v , N, adj, visited, st);
        }
    }

    st.push(node);

}

vector<int> shortestPath ( int N, int M, vector<int> edges[] ) {

    stack<int>st;

    vector<int>visited (N,0);
    vector<pair<int,int>> adj[N];

    for ( int i = 0; i < N; i++ ) {
         int u = edges[i][0];
         int v = edges[i][1];
         int wt = edges[i][2];

         adj[u].push_back({v,wt});
    }

    for ( int i = 0; i < N; i++ ) {

        if ( !visited[i] ) {
            topologicalSort( i, N, adj, visited, st);
        }
    }

    vector<int> distances(N);

    for ( int i = 0; i < N; i++ ) distances[i] = INT_MAX;

    distances[0] = 0;

    while ( !st.empty() ) {
        
        int node = st.top();
        st.pop();

        for ( auto it : adj[node] ) {

            int v = it.first;
            int wt = it.second;

            if ( distances[node] + wt < distances[v] ) distances[v] = distances[node] + wt; 

        }
        
    }
    return distances;
}