// Problem : Ninja's Training

// Approach: For each day, activities are performed recursively and max points earned are update accordingly

// TC: O(4*n)*3
// SC: O(n) + O(4*n)*3

#include<bits/stdc++.h>

using namespace std;

int maximumPoints( int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {

    if ( dp[day][last] != -1 ) return dp[day][last];

    if ( day == 0 ) {

        int maxi = 0;

            for ( int i = 0; i < 3; i++ ) {

                if ( day != last ) {
                    maxi = max(maxi, points[0][i]);
                }
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;

    for ( int i = 0; i < 3; i++ ) {

        if ( i != last ) {

            int activity = points[day][i] + maximumPoints(day-1,i,points,dp);
            maxi = max(maxi, activity);
        }
    }

    return dp[day][last] = maxi;
}

int function(vector<vector<int>>& points, int n) {

    vector<vector<int>> dp(n, vector<int>(4,-1));

    return maximumPoints(n-1, 3,points, dp);
}