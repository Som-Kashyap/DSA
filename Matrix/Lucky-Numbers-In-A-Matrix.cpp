// Problem LC: 1380

// Approach: The matrix is traversed to store rowMin and colMax of each row and col respectively, then traversed again to find the elements.

// TC: O(m*n)
// SC: O(1) - generalized

#include<bits/stdc++.h>

using namespace std;

 vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> rowMin(rows,INT_MAX);
        vector<int> colMax(cols,INT_MIN);

        for ( int row = 0; row < rows; row++ ) {

            for ( int col = 0; col < cols; col++ ) {

                rowMin[row] = min(rowMin[row], matrix[row][col]);
                colMax[col] = max(colMax[col], matrix[row][col]);

            }

        }

        vector<int> res;

        for ( int row = 0; row < rows; row++ ) {

            for ( int col = 0; col < cols; col++ ) {

                if ( matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col] ) res.push_back(matrix[row][col]);

            }
        }
        return res;
    }