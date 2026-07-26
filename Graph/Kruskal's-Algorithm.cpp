#include<bits/stdc++.h>

using namespace std;

class DisjointSet{

    vector<int> parent; vector<int> rank;
    vector<int> size;

    public:

    DisjointSet(int n) {

        parent.resize(n+1,0);
        rank.resize(n+1,0);
        size.resize(n+1,0);

        for ( int i = 0; i <= n; i++ ) {
            parent[i] = i;
            size[i] = i;
        }

    }

    int FindUltimateParent (int node) {

        if ( parent[node] == node ) return node;

        int par;

        return parent[node] = FindUltimateParent(parent[node]); //Path Compression
    }

     void UnionByRank ( int u, int v ) { //TC: O(4*alpha)

        int ult_u = FindUltimateParent (u);
        int ult_v = FindUltimateParent (v);

       if ( ult_u == ult_v ) return;

       if ( rank[u] < rank[v] ) parent[ult_u] = ult_v;

       else if ( rank[v] > rank[u] ) parent[ult_v] = ult_u;

       else {
        parent[ult_v] = ult_u;
        rank[u]++;
       }
    }

    void UnionBySize ( int u, int v ) { //TC: O(4*alpha)

        int ult_u = FindUltimateParent (u);
        int ult_v = FindUltimateParent (v);

        if ( size[ult_u] < size[ult_v] ) {

            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];

        }

        else {

            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v]; 
        }
    }

};

int spanningTree ( int V, vector<vector<int>> adj[] ) {

    vector<pair<int,pair<int,int>>> edges;

    // TC: O(N+E)
    for ( int i = 0; i < V; i++ ) {

        for ( auto it : adj[i] ) {

            int v = it[0];
            int wt = it[1];
            int u = i;

            edges.push_back({wt,{u,v}});

        }
    }

    int mstWt = 0;

    // TC: O(MlogM)
    sort (edges.begin(), edges.end());

    DisjointSet ds(V);

    // TC: O(M*4*alpha)
    for ( auto it : edges ) {

        int wt = it.first;
        int node = it.second.first;
        int adj = it.second.second;

        if ( ds.FindUltimateParent(node) != ds.FindUltimateParent(adj) ) {

            ds.UnionBySize( node, adj );
            mstWt += wt;
        }
    }
    return mstWt;
}