// Problem : LC 124

// Approach: Visit nodes recursively and calc sum of path of that particular node and update maxsum

#include<iostream>
#include<climits>

using namespace std;

struct Node{

    int data;
    Node* left ;
    Node* right ;

    Node( int val ) {

        data = val;
        left = NULL;
        right = NULL;
    }
};

int MaxPathSum( Node* root , int &maxsum ) {

    if ( root == NULL ) return 0;

    int ls = max( 0 , MaxPathSum ( root->left , maxsum )) ; 
    int rs = max ( 0 , MaxPathSum( root->right, maxsum  ));

    maxsum = max( maxsum , (root->data + ls + rs) );

    return root->data + max ( ls , rs );

}

int main () {

    struct Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    int maxsum = INT_MIN;

   MaxPathSum(root, maxsum);

   cout << "Max Path Sum: " << maxsum << endl;

    return 0;

}