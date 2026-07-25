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