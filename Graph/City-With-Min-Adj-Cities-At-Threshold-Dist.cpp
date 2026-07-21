// Problem LC: 1334

// Approach: Floyd Warshall Algorithm is used to find shortest distances to each city, count of no of adj cities within threshold
//           to each city is kept, if count is within threshold, it is updated along with the city number.

// TC: O(n*n*n)
// SC: O(n*n)

#include<iostream>
#include<vector>

using namespace std;

int findTheCity ( int n, vector<vector<int>>& edges, int distanceThreshold ) {

    vector<vector<int>> distances (n, vector<int>(n,1e9));

    for ( auto it : edges ) {

        distances[it[0]][it[1]] = it[2];
        distances[it[1]][it[0]] = it[2];

    }

    for ( int i = 0; i < n; i++ ) distances[i][i] = 0;

    for ( int k = 0; k < n; k++ ) {
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {

                if ( distances[i][k] == 1e9 || distances[k][j] == 1e9 ) continue;

                distances[i][j] = min ( distances[i][j], distances[i][k] + distances[k][j] );

            }
        }
    }

    int cityCount = n;
    int cityNo = -1;

    for ( int city = 0; city < n; city++ ) {
        int count = 0;
        for ( int adj = 0; adj < n; adj++ ) {

            if ( distances[city][adj] <= distanceThreshold ) count++;
        }

        if ( count <= cityCount ) {
            cityCount = count;
            cityNo = city;
        }
    }
    
    return cityNo;
}