#include<iostream>
#include<vector>
#include<set>
#include<climits>

using namespace std;

vector<int> dijkstra ( int N, vector<vector<int>> adj[], int S ) {

    vector<int> distances(N);

    for ( int i = 0; i < N; i++ ) distances[i] = INT_MAX;

    set<pair<int,int>> s;

    s.insert ( {0,S} );
    distances[S] = 0;

    while ( !s.empty() ) {

        auto it = *(s.begin());

        int node = it.second;
        int dist = it.first;
        s.erase(it);

        for ( auto nbr : adj[node] ) {

            int val = nbr[1];
            int edgeWt = nbr[0];

            if ( dist + edgeWt < distances[val] ) {

                if ( distances[val] != INT_MAX ) s.erase( {distances[val], val} );

                 distances[val] = dist + edgeWt;
                 s.insert( {distances[val], val} );
            }
        }
    }

   return distances;

}