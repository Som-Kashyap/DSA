// Problem: LC-94

// Approach: Initiate pointer from root , move down storing nodes into stack , push elements to res vector in order while removing them from the stack , order:( left->root->right)

// Invariant: At the end of the while loop , st.top() represents leaf node of left sub-tree

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

vector<int> inOrder ( Node* root ) {

    vector<int>res;
    stack<Node*>st;

    Node* node = root;

    while ( !st.empty() || node ) {

        while ( node ) {

        st.push( node);

        node = node->left;

        }

        if ( !st.empty() ) {

    node = st.top();
    st.pop();

    res.push_back( node->data );

    node = node->right;
    
    }
}

    return res;
}

int main () {

    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

   vector<int>result = inOrder ( root );

   for ( int val : result ) {

    cout<<val<<" ";

   }
   cout<<endl;

    return 0;
    
}