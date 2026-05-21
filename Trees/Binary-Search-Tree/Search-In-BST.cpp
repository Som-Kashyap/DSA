// Problem: LC 700

// Approach: Tree is traversed by comparing val of node with the target value , left if it is smaller and right otherwise

#include<iostream>

using namespace std;


struct Node {

    int val;
    Node* left;
    Node* right;

    Node( int data ) {

        val = data;
        left = NULL;
        right = NULL;

    }
};

Node* searchBST ( Node* root , int target ) {

    if ( !root ) return NULL;

    if ( root->val == target ) return root;

    if ( root->val > target )  return searchBST( root->left , target );

    else return searchBST( root->right , target );

}

int main () {

    struct Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    int target = 5;

    searchBST ( root , target );

    return 0;

}