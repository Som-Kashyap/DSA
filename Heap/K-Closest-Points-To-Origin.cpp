//  Problem LC:973

//  Approach: Max heap is used to score a pair of {a , {b,c}}, a=b*b+c*c. In the end, k closest points remain in the heap.

// TC: O(N) + O(NlogK) + O(K) => O(N)+O(K) approx
// SC: O(K)

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> KClosestPoints ( vector<vector<int>> &points , int k ) {

    priority_queue<pair<int,pair<int,int>>> pq;

    for ( auto &point : points ) {

        int a = point[0];
        int b = point[1];

        pq.push( {(a*a+b*b) , {a,b}} );

        if ( pq.size() > k ) pq.pop();

    }

    vector<vector<int>>res(k);

    for ( int i = 0; i < k; i++ ) {

        auto[x,y] = pq.top();
        res[i] = {y.first , y.second};

        pq.pop();

    }
    return res;
}

int main () {

    vector<vector<int>>points = { {1,3} , {-2,2}};
    int k = 1;

    KClosestPoints(points,k);

    return 0;
}