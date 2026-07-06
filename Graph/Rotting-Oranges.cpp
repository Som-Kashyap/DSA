// Problem LC: 994

// Approach: Rotten oranges are pushed to a queue and bfs is applied, fresh neighbours are marked as rotten

// TC and SC: O(rows*cols)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

 int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int rows = grid.size();
        int cols = grid[0].size();

        int freshOranges = 0;
        int minutes = 0;

        for ( int row = 0; row < rows; row++ ) {
            for ( int col = 0; col < cols; col++ ) {
                if ( grid[row][col] == 1 ) {
                    freshOranges++;
                }
                if ( grid[row][col] == 2 ) {
                    q.push( {row,col});
                }
            }
        }

        while ( !q.empty() && freshOranges > 0 ) {

            int size = q.size();

            while ( size-- ) {
                auto[r,c] = q.front();
                q.pop();

                for ( auto [dr,dc] : directions ) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if ( nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1 ) {
                        grid[nr][nc] = 2;
                        freshOranges--;
                        q.push({nr,nc});
                    }
                }
            }
            minutes++;
        }
        if ( freshOranges == 0 ) return minutes;
        else return -1;
    }

    int main () {

        vector<vector<int>>grid = {{2,1,1}, {1,1,0},{0,1,1}};

        int res = orangesRotting(grid);

        cout<<res<<endl;

        return 0;
    }