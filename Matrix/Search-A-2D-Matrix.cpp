// Problem LC: 74

// Approach: The given matrix is considered as a plane array of m*n elements and a simple Binary-Search is applied.
//           row idx = mid/n and each row holds exactly n elements, col idx = mid%n (gives the location of mid in the row)

// TC: O(logm*n)
// SC: O(1)

#include<bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
       int rows = matrix.size();
       int cols = matrix[0].size();

       int st = 0, end = rows*cols-1;

       while ( st <= end ) {

        int mid = (st + ( end - st )/2 );

        if ( matrix[mid/cols][mid%cols] == target ) return true;

        else if ( matrix[mid/cols][mid%cols] < target ) st = mid+1;

        else end = mid-1;

       }
       
       return false;
    }