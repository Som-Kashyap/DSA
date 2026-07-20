// Problem: Floyd Warshall Algorithm

// Approach: Each cell is iterated considering all of the numbers from 0 to n-1, shortest distance to each cell from other cell  
//            is calculated via every other cell.

// TC: O(n*n*n)
// SC: O(n)

#include<iostream>
#include<vector>

using namespace std;

void shortest_distance( vector<vector<int>>& matrix ) {

    int n = matrix.size();

    for ( int k = 0; k < n; k++ ) {

        for ( int i = 0; i < n; i++ ) {

            for ( int j = 0; j < n; j++ ) {

                if ( matrix[i][k] != 1e9 && matrix[k][j] != 1e9 ) {

                    matrix[i][j] = min ( matrix[i][j], matrix[i][k] + matrix[k][j] );

                }
            }
        }
     }

}