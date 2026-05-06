// Problem: Lc-104

// Approach: Move pointer starting from root , recursive calls for left then right , return 1+max(leftHt , rightHt)

#include<iostream>

using namespace std;

struct Node {

    int val;

    Node* left;
    Node* right;

    Node ( int x ) {

        val = x;

        left = 0;
        right = 0;

    }

};

int maxDepth ( Node* root ) {

     if ( root==NULL ) return 0;  //Base case

    int lh = maxDepth ( root->left ); 

    int rh = maxDepth ( root->right );

    return 1 + max ( lh , rh );

}

int main () {

    struct Node* root = new Node(1);
    root->left = new Node(4);
    root->left = new Node(2);
    root->left->right = new Node(5);
    root->left->right->left = new Node(3);
    root->right->left = new Node(7);

    cout<<"Max-Depth: "<<maxDepth( root )<<endl;

    return 0;

}