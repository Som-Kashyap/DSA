#include<bits/stdc++.h>

using namespace std;

class DisjointSet{

    vector<int> parent; vector<int> rank;

    public:

    DisjointSet(int n) {

        parent.resize(n,0);
        rank.resize(n,0);

        for ( int i = 0; i <= n; i++ ) parent[i] = i;

    }

    int FindUltimateParent (int node) {

        if ( parent[node] == node ) return node;

        int par;

        return parent[node] = FindUltimateParent(parent[node]); //Path Compression
    }

    void UnionByRank ( int u, int v ) {

        int ult_u = FindUltimateParent (u);
        int ult_v = FindUltimateParent (v);

       if ( ult_u == ult_v ) return;

       if ( rank[u] < rank[v] ) parent[u] = v;

       else if ( rank[v] > rank[u] ) parent[v] = u;

       else {
        parent[v] = u;
        rank[u]++;
       }
    }

};