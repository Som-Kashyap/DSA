// Problem: Detect Cycle in a Directed Graph

// Approach: Topological sort is used and and a count of nodes is maintained, if it is less than number of nodes, there is a cycle

// TC: O(V+e)
// SC: O(N)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool detectCycle (int V, vector<int>adj[] ) {

    vector<int>indegree(V,0);

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

    int count = 0;

    while ( !q.empty() ) {

        int node = q.front();
        q.pop();
        count++;

        for ( auto it : adj[node] ) {
            indegree[it]--;
            if ( indegree[it] == 0 ) q.push(it);
        }
    }

    if ( count == V ) return false;

    return true;
    
}