// Problem: Bellman Ford Algorithm

// Approach: Distances array is initialized, shortest distances are alloted in n-1 iterations

// TC: O(V*E)
// SC: O(V)

#include<iostream>
#include<vector>

using namespace std;

vector<int> bellman_ford ( int V, vector<vector<int>>& edges, int S ) {

    vector<int> distances(V,1e8);

    for ( int i = 0; i < V-1; i++ ) {

        for ( auto it : edges ) {

            int u = it[0];
            int v = it[1];
            int w = it[2];

            if ( distances[u] != 1e8 && distances[u] + w < distances[v] ) {

                distances[v] = distances[u] + w;
            }
        }
    }
    return distances;
}