// Problem LC: 802

// Approach: Edges are reversed and adj list is created following the reverse order and indegree is tracked
//           Topological sort is used to find safe states

// TC: O(V + e) + O(NlogN)
// SC: O(V) + O(N)

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> safeStates ( vector<vector<int>>& graph ) {

    int n = graph.size();

    vector<int> reverseAdj[n];
    int indegree[n] = {0};

    for ( int i = 0; i < n; i++ ) {

        for ( auto& it : graph[i] ) {
            reverseAdj[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int>q;

    for ( int i = 0; i < n; i++ ) if ( indegree[i] == 0 ) q.push(i); 
        
    vector<int>safeStates;

    while ( !q.empty() ) {

        int node = q.front();
        q.pop();

        safeStates.push_back(node);

        for ( auto& it : reverseAdj[node] ) {
            indegree[it]--;

            if (indegree[it] == 0) q.push(it);
        }
    }

    sort(safeStates.begin(), safeStates.end());

    return safeStates;
}