// Problem: Print root to node path

// Approach: Preorder traversal is followed and nodes are pushed to path vector , nodes having no children && not matching the target are popped and false is returned , true is returned if target node is found

#include<iostream>
#include<vector>

using namespace std;

struct Node {

    int val;
    Node* left;
    Node* right;

    Node ( int data ) {

        val = data;
        left = NULL ; right = NULL;

    }

};

bool RootToNodePath ( Node* root , vector<int> &path , int &target  ) {

    if ( root == NULL ) {

        return false;

    }

    path.push_back ( root->val );

    if ( root->val == target ) return true;

    if ( RootToNodePath ( root->left , path , target ) || RootToNodePath ( root->right , path , target ) ) return true;

    path.pop_back ();

    return false;

}

int main () {

    vector<int>path;
    int target = 7;

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    if ( !root ) {

        throw runtime_error ("Root is NULL!");

    }

    RootToNodePath ( root , path , target );

    for ( int pathnodes : path ) {

        cout<<pathnodes<<" ";

    }
    cout<<endl;

    return 0;

}