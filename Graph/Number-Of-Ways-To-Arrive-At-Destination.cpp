// Problem LC: 1976

// Approach: A pq is maintained that stores dist of curr node from src and the val of that node, a ways array is used to track
//           no. of ways to reach a particular node by shortest distance. If new-dist is the same, number of ways is incremented
//           If new-dist is less, number of ways to reach = ways to reach prev node.

// TC: O((E+V)logV)
// SC: O(V+E)

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
        
        int MOD = 1e9 + 7;
        vector<pair<int,int>> adj[n];

        for ( auto it : roads ) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<long long> distances(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        pq.push({0,0});
        distances[0] = 0;
        ways[0] = 1;

        while ( !pq.empty() ) {

            auto it = pq.top();
            pq.pop();

            int node = it.second;
            long long dist = it.first;

            if ( dist > distances[node] ) continue;
            
            for ( auto x : adj[node] ) {
                int edgw = x.second;
                int val = x.first;

                if ( dist + edgw < distances[x.first] ) {
                    distances[x.first] = dist + edgw;
                    ways[val] = ways[node];
                    pq.push({distances[val], val});
                }
                else if ( dist + edgw == distances[val] ) {
                    ways[val] = (ways[val] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }