// Problem: DFS (undirected)

// Approach: Node is pushed to the vector and the neighbours are traversed recursively if they haven't been visited

// TC: O(n) + O(2*E)
// SC: O(n)
#include<iostream>
#include<vector>

using namespace std;

void traversal ( int node, int vis[] , vector<int> adj[] , vector<int> &DFS ){

    vis[node] = 1;
    DFS.push_back(node);

    for ( auto nodes : adj[node] ) {

        if ( !vis[nodes] ) {
            vis[nodes] = 1;
            
            traversal( nodes , vis , adj , DFS );

        }
    }
}

vector<int> dfs( int V , vector<int> adj[] ) {

    int vis[V] = {0};
    vector<int>DFS;
    int start = 0;

    traversal( start , vis , adj , DFS );

    return DFS;

}