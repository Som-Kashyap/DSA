// Problem LC: 73

// Approach: 1st row and col are treated as marker arrays, the matrix is traversed and corresponding cells in 1st row and col are
//           marked zero as zero is found. All required cells are marked zero in the next iteration.
//           flags are maintained to check if the marker row/col have zeros initially, then they are marked zero in the end.

// TC: O(m*n)
// SC: O(1)

#include<bits/stdc++.h>

using namespace std;

void setMatrixZeros ( vector<vector<int>>& matrix ) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    bool doesFirstRowHaveZero = false;
    bool doesFirstColHaveZero = false;
    
    for ( int row = 0; row < rows; row++ ) {

        if ( matrix[row][0] == 0 ) {

            doesFirstColHaveZero = true;
            break;

        }

    }

    for ( int col = 0; col < cols; col++ ) {

        if ( matrix[0][col] == 0 ) {

            doesFirstRowHaveZero = true;
            break;

        }
    }

    for ( int row = 0; row < rows; row++ ) {

        for ( int col = 0; col < cols; col++ ) {

            if ( matrix[row][col] == 0 ) {

                matrix[row][0] = 0;
                matrix[0][col] = 0;

            }
        }
    }

    for ( int row = 1; row < rows; row++ ) {

        if ( matrix[row][0] == 0 ) {

            for ( int col = 1; col < cols; col++ ) matrix[row][col] = 0;
        }
    }

    for ( int col = 1; col < cols; col++ ) {

        if ( matrix[0][col] == 0 ) {

            for ( int row = 1; row < rows; row++ ) matrix[row][col] = 0;
        }
    }

    if ( doesFirstRowHaveZero ) {

        for ( int col = 0 ; col < cols; col++ ) matrix[0][col] = 0;

    }

    if ( doesFirstColHaveZero ) {

        for ( int row = 0; row < rows; row++ ) matrix[row][0] = 0;

    }
}