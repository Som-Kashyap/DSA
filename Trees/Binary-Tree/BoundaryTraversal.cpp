// Problem: LC 545

// Approach: Functions are called in order ( LeftNodes->LeafNodes->RightNodes ) , left ( excluding leaves ) and leaf nodes are added to the result vector. Right nodes ( excluding leaves ) are added in reverse order.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {

    int val;
    Node* left;
    Node* right;

    Node ( int data ) {

        val = data;
        left = NULL;
        right = NULL;

    }

};


bool IsLeaf ( Node* root ) {

    if (root == NULL) return false; 
    return !root->left && !root->right;

}

void AddLeft ( Node* root , vector<int>& ans ) {

    Node* curr = root->left;

    while ( curr ) {

        if ( !IsLeaf( curr ) ) ans.push_back ( curr->val );

        if ( curr->left ) curr = curr->left;

        else curr = curr->right;

    }
  
}

void AddLeaf ( Node* root , vector<int>& ans ) {

    queue<int>leaf;

    Node* curr = root;

    if ( IsLeaf ( curr ) ) {

        ans.push_back ( curr->val );
        return;

    }

    if ( curr->left ) AddLeaf ( curr->left , ans );
    if ( curr->right ) AddLeaf ( curr->right , ans );

}

void AddRight ( Node* root , vector<int>& ans ) {

    Node* curr = root->right;
    vector<int>right;

    while ( curr ) {

        if ( !IsLeaf ( curr ) ) right.push_back ( curr->val );

        if ( curr->right ) curr = curr->right;

        else curr = curr->left;

    }

    for ( int i = right.size()-1; i >= 0 ; --i ) {

        ans.push_back ( right[i] );

    }

}

int main () {

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    vector<int>ans;
    ans.push_back ( root->val );

    AddLeft ( root , ans );
    AddLeaf ( root , ans );
    AddRight ( root , ans );

    for ( int nodes : ans ) {

        cout<<nodes<<" ";

    }
    cout<<endl;

    return 0;

}