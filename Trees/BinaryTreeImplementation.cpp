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

void preorder ( Node* root , vector<int> &Pre ) {

    if ( root == NULL ) return;

    Pre.push_back ( root->data );

    preorder ( root->left , Pre );

    preorder ( root->right , Pre );

}

void inorder ( Node* root , vector<int> &In) { 

    if ( root == NULL ) return;

    inorder ( root->left , In );

    In.push_back ( root->data );

    inorder ( root->right , In );

}

void postorder ( Node* root , vector<int> &Post ) {

    if ( root == NULL ) return;

    postorder ( root->left , Post );

    postorder ( root->right , Post );

    Post.push_back ( root->data );

}

int main () {

    vector<int>Pre;
    vector<int>In;
    vector<int>Post;

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(4);

    preorder ( root , Pre );

    cout<<"Pre-order traversal:- "<<endl;

    for ( int node: Pre ) {

        cout<<node<<" ";

    }
    cout<<endl;

    inorder ( root , In );

    cout<<"In-order traversal:- "<<endl;

    for ( int node : In ) {

        cout<<node<<" ";

    }
    cout<<endl;

    postorder ( root , Post );
    
    cout<<"Post-order traversal:- "<<endl;

    for ( int node : Post ) {

        cout<<node<<" ";

    }
    cout<<endl;

    return 0;

}

