// Problem LC: 1361

// Approach: childCount array is created to mark if a node has parents or not, node having no parents is the root
//           false is returned if there exist multiple roots / no root at all, dfs is applied starting from the root
//           at the end, if there exists unvisted node, it is not a valid BT

// TC and SC: O(n)

#include<iostream>
#include<vector>

using namespace std;

bool dfs ( int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited ) {

    if ( leftChild[node] != -1 ) {

        if ( visited[leftChild[node]] ) return false;

        visited[leftChild[node]] = true;

        if ( !dfs ( leftChild[node], leftChild, rightChild, visited )) return false;

    }

      if ( rightChild[node] != -1 ) {

        if ( visited[rightChild[node]] ) return false;

        visited[rightChild[node]] = true;

        if ( !dfs ( rightChild[node], leftChild, rightChild, visited )) return false;
        
    }

    return true;
}

bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

    vector<bool> childCount(n,false);

    for ( auto child : leftChild ) {

        if ( child != -1 ) {

            childCount[child] = true;
        }
    }

    for ( auto child : leftChild ) {

        if ( childCount[child] ) return false;

        else childCount[child] = true;

    }

    int root = -1;

    for ( int i = 0; i < n; i++ ) {

        if ( childCount[i] == 0 ) {

            if ( root == -1 ) root = i;

            else return false;
        } 
    }

    if ( root == -1 ) return false;

    vector<bool> visited(n,false);

    visited[root] = true;

    if ( !dfs ( root, leftChild, rightChild, visited )) return false;

    for ( int i = 0; i < n; i++ ) {

        if ( visited[i] == false ) return false;

    }

    return true;
}