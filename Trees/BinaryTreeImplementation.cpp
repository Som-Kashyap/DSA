#include<iostream>
#include<vector>

using namespace std;

struct Node {

    int data;

    Node *left;
    Node *right;

    Node ( int val ){

        data = val;

        left = NULL;
        right = NULL;

    }

};

void preorder ( Node* root , vector<int> &res ) {

    if ( root == NULL ) return;

    cout<<root->data<<endl;

    preorder ( root->left , res );

    preorder ( root->right , res );

}

int main () {

    vector<int>res;

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    preorder ( root , res );

    for ( int node: res ) {

        cout<<node<<" ";

    }

    return 0;

}

