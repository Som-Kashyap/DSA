// Problem LC: 1091

// Approach: Dijkstra's procedure is used, shortest distances to each cell are stored and updated when applicable
//           Only the cells containing '1' are considered. -1 is returned if last cell can't be reached.

// TC and SC: O(n*n)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int n = grid.size();

    if ( n == 1 ) {
        if ( grid[n-1][n-1] == 1 ) return -1;
        else return 1;
    }

    if ( grid[0][0] == 1 || grid[n-1][n-1] == 0 ) return -1;

    vector<vector<int>> distances (n, vector<int>(n,1e9));

    queue<pair<int,pair<int,int>>> q;
    q.push( {1, {0,0}} );
    distances[0][0] = 1; 

    vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };

    while ( !q.empty() ) {

        int dist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;

        for ( auto[dr,dc] : directions ) {

            int nr = row + dr;
            int nc = col + dc;

            if ( nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist + 1 < distances[nr][nc] ) {
                distances[nr][nc] = dist + 1;
                
                if ( nr == n-1 && nc == n-1 ) return dist + 1;

                q.push ( {distances[nr][nc], {nr,nc}} );
            }
        }
    }
    return -1;
}