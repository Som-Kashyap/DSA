// Problem LC: 733

// Approach: The color of the given cell is changed and bfs is apllied starting from the same cell
//           adjacent cells having same original color are assigned the required color and pused to the queue

// SC: O(rows*cols)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void bfs ( int r , int c , int rows, int cols, int original , vector<vector<int>>& image , int color) {

        queue<pair<int,int>>q;
        vector<pair<int,int>>directions = {{-1,0}, {1,0} , {0,1}, {0,-1}};

        if ( r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != original ) return;

        q.push( {r,c} );
        image[r][c] = color;

        while ( !q.empty() ) {

            auto [row , col] = q.front();
            q.pop();

            for ( auto [dr,dc] : directions ) {
                int nr = row + dr;
                int nc = col + dc;

                if ( nr >= 0 && nr < rows && nc >= 0 && nc < cols && image[nr][nc] == original ) {
                    image[nr][nc] = color;
                    q.push({nr , nc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
       int rows = image.size();
       int cols = image[0].size();

       int original = image[sr][sc];

       if ( original == color ) return image;

       bfs ( sr , sc , rows, cols , original , image , color);
       
       return image;
    }

    int main () {

        vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
        int sr,sc = 1;
        int color = 2;

        floodFill(image , sr , sc , color);

        return 0;
    }