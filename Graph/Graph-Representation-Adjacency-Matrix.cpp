// TC: O(m)
// SC: O(n*n)

#include<iostream>

using namespace std;

int main () {

    int n , m;

    int graph[n+1][n+1];

    cout<<"Enter n and m: ";
    cin>>n>>m;

    for ( int i = 0 ; i < m; i++ ) {

        int u , v;

        cin>>u>>v;

        graph[u][v] = 1;
        graph[v][u] = 1;

    }
    return 0;
}