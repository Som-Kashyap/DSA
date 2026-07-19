// Problem LC: 787

// Approach: A queue is maintained that stores (stops,node,edgewt), a distance array is maintained that stores cheapest cost
//           required to reach a particular node, it is updated if currdist + edgewt is less than that assigned previously,
//           at the end, distances[dst] is returned.

// TC: O(E)
// SC: O(n)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];

        for ( auto it : flights ) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int,pair<int,int>>> q;
        
        q.push ({0, {src, 0}});

        vector<int> distances(n, 1e9);
        distances[src] = 0;

        while ( !q.empty() ) {

            auto it = q.front();
            int dist = it.second.second;
            int node = it.second.first;
            int stops = it.first;
            q.pop();

            if ( stops > k ) continue;

            for ( auto x : adj[node] ) {
                int val = x.first;
                int edgeWt = x.second;

                if ( dist + edgeWt < distances[val] && stops <= k ) {
                    distances[val] = dist + edgeWt;
                    q.push( {stops+1, {val, distances[val]}});
                }
            }
        }
        if ( distances[dst] != 1e9 ) return distances[dst];
        else return -1;
    }