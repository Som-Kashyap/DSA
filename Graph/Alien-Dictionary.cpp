// Problem: Alien Dictionary

// Approach: Adjacent strings are compared to find distinct char, once found it is pushed to adj-list
//           Topological sort is then used for obtaining the required order of words

// TC: O(V+e) for topological sort and O(N) + O(K)
// SC: O(N) and O(N) + O(K)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> topologicalSort ( vector<int> adj[], int N ) {

    queue<int>q;
    vector<int> indegree(N,0);

    for ( int i = 0; i < N; i++ ) {

        for ( auto& it : adj[i] ) indegree[it]++;

    }

    vector<int> topo;

    for ( int i = 0; i < N; i++ ) {
        if ( indegree[i] == 0 ) q.push(i);
    }

    while ( !q.empty() ) {

        int node = q.front();
        q.pop();

        topo.push_back(node);

        for ( auto& it : adj[node] ) {
            indegree[it]--;
            if ( indegree[it] == 0 ) q.push(it);
        }
    }

    return topo;
}

string findOrder( string dict[], int N, int K ) {

    string order = "";
    vector<int> adj[K];

    for ( int i = 0; i < N-1; i++ ) {

    string s1 = dict[i];
    string s2 = dict[i+1];

    int len = min(s1.length() , s2.length());

    int ptr = 0;

    while ( ptr < len ) {

        if ( s1[ptr] != s2[ptr] ){
            adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
            break;
        }

        ptr++;
    }
}
    vector<int> res = topologicalSort( adj, K );

    string ans = "";

    for ( auto it : res ) {
        ans = ans + char( it + 'a' );
    }

    return ans;
}