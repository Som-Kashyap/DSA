// Problem LC: 2462

// Approach: Two heaps are maintained one for front (candidates) elements and other for last, for k iterations, smallest num is
//           added to ans and popped, next element if available is added to the heap

#include<bits/stdc++.h>

using namespace std;

long long totalCost(vector<int>& costs, int k, int candidates) {

    priority_queue< int, vector<int>, greater<int>> pq1;
    priority_queue< int, vector<int>, greater<int>> pq2;

    long long cost = 0;

    int i = 0;
    int j = costs.size() - 1;

    while ( k-- ) {

        while ( pq1.size() < candidates && i <= j ) {
            pq1.push( costs[i++] );
        }

        while ( pq2.size() < candidates && i <= j ) {
            pq2.push( costs[j--] );
        }

        int t1 = ( pq1.size() > 0 ) ? pq1.top() : INT_MAX;
        int t2 = ( pq2.size() > 0 ) ? pq2.top() : INT_MAX;

        if ( t1 <= t2 ) {

            cost += t1;
            pq1.pop();

        }

        else {

            cost += t2;
            pq2.pop();

        }
    }

    return cost;

}