// Problem LC: 2685

// Approach: DSU is used to connect the nodes, degree array is maintained to find no of edges to/from every node.
//           unordered_map is used to store components of all the ult parents
//           It is a connected comp if for every node there are size-1 edges, so loop is run on map and for each of the comp,
//           if degree of any of the nodes isn't satisfied, it isn't a proper comp

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
            size[i] = 1;
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

       if(rank[ult_u] < rank[ult_v]) parent[ult_u] = ult_v;

       else if(rank[ult_v] < rank[ult_u]) parent[ult_v] = ult_u;

       else{
    parent[ult_v] = ult_u;
    rank[ult_u]++;
}
    }

    void UnionBySize(int u, int v) {

    int ult_u = FindUltimateParent(u);
    int ult_v = FindUltimateParent(v);

    if (ult_u == ult_v) return;  

    if(size[ult_u] < size[ult_v]) {
        parent[ult_u] = ult_v;
        size[ult_v] += size[ult_u];
    }
    else {
        parent[ult_v] = ult_u;
        size[ult_u] += size[ult_v];
    }
}

     int getSize(int u) {
        return size[FindUltimateParent(u)];
    }
};

int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        DisjointSet ds(n);
        vector<int> degree(n,0); //SC: O(n)

        for ( auto& it : edges ) { //TC: O(E)

            ds.UnionBySize(it[0], it[1]); //TC: O(4*alpha)

            degree[it[0]]++;
            degree[it[1]]++;

        }

        unordered_map<int,vector<int>> mp; //SC: O(C), C = components

        for ( int i = 0; i < n; i++ ) {  // TC: O(n)

            mp[ds.FindUltimateParent(i)].push_back(i);

        }

        int res = mp.size();

        for ( auto& it : mp ) {

            int sz = ds.getSize(it.first);

            bool isConnected = true;

            for ( int node : it.second ) {

                if ( degree[node] != sz-1 ) {
                    isConnected = false;
                    break;
                }
            }

            if ( !isConnected ) res--;
            
        }
        return res;
    }