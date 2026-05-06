#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node( int val ) {

        data = val;
        left = NULL;
        right = NULL;
        
    }
};