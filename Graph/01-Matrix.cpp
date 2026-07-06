// Problem LC: 542

// Approach: distance matrix is used to store distance of the elements, 0 for 0s and initialized as -1 for 1s
//           0s are pushed into the queue and bfs is applied for each of them, if their memebers haven't been assigned distance
//           they are assigned disance as d+1 (d is the distance of the element at the cell) and pushed into the queue

//  TC and SC: O(rows*cols)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>>distance(rows , vector<int>(cols));
        queue<pair<int,int>>q;

        for ( int row = 0; row < rows; row++ ) {

            for ( int col = 0 ; col < cols; col++ ) {

                if ( mat[row][col] == 0 ) {
                    distance[row][col] = 0;
                    q.push({row,col});
                }
                else distance[row][col] = -1;
            }
        }

        while ( !q.empty() ) {

            auto [r,c] = q.front();
            q.pop();

            for ( auto[dr,dc] : directions ) {
                int nr = r + dr;
                int nc = c + dc;
                if ( nr >= 0 && nr < rows && nc >= 0 && nc < cols ) {
                    if ( distance[nr][nc] == -1 ) {
                        distance[nr][nc] = distance[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return distance;
    }

    int main () {

        vector<vector<int>>mat = {{0,0,0},{0,1,0},{0,0,0}};

        updateMatrix(mat);

        return 0;

    }