// Problem: Topological Sort

// Approach: indegree of all the nodes is stored, nodes having 0 indgeree are pushed to a queue, then they are popped and stored
//           to res vector and the indegree of thier neigbors is decreased by one, if it is 0 then they are pushed

//  TC: O(V+e)
//  SC: O(N)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> TopologicalSort( int V, vector<int> adj[] ) {

    vector<int> indegree(V, 0);

    for ( int i = 0; i < V; i++ ) {

        for ( auto it : adj[i] ) {
            indegree[it]++;
        }
    }

    queue<int>q;

    for ( int i = 0; i < V; i++ ) {

        if ( indegree[i] == 0 ) {
            q.push(i);
        }
    }

    vector<int>res;

    while ( !q.empty() ) {

        int node = q.front();
        q.pop();

        res.push_back(node);

        for ( auto it : adj[node] ) {
            indegree[it]--;
            if ( indegree[it] == 0 ) q.push(it);
        }
    }

    return res;
}