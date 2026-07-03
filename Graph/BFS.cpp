// Problem : Graph BFS (undirected)

// Approach: a vis array is maintained to keep a track of elements that have been visited, elements are popped from the queue
//           and pushed to the result vector whilw pushing their neighbours if they haven't been visited

// TC: O(n) + O(2E)
// SC: O(n)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> bfs ( int V , vector<int> adj[] ) {

    int vis[V] = {0};
    vector<int>BFS;
    queue<int>q;

    vis[0] = 1;
    q.push(0);

    while ( !q.empty() ) {

        int node = q.front();
        q.pop();

        BFS.push_back(node);

        for ( auto it : adj[node] ) {

            if ( !vis[it] ) {
                q.push(it);
                vis[it] = 1;
            }

        }
    }

    return BFS;
}