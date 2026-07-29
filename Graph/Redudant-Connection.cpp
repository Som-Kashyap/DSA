// Problem LC: 684

// Approach: DSU is used and the given edges vector is traversed, nodes belonging to same component are returned as answer
//           (As the aim is to make it a tree by removing unnecessary edges)

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

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        DisjointSet ds(n);

        vector<int> res;

        for ( auto it : edges ) {

            int u = it[0];
            int v = it[1];

            if ( ds.FindUltimateParent (u) == ds.FindUltimateParent (v) ) {
                return {u,v};
            }

            else {
                ds.UnionBySize ( u , v );
            }
        }
        return {};
    }