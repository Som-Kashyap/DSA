// TC: O(m)
// SC: O(2*E) , E is the number of edges

#include<iostream>
#include<vector>

using namespace std;

int main () {

    int n , m;

    vector<int>graph[n+1];

    for ( int i = 0; i < m; i++ ) {

        int u , v;

        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    return 0;
}