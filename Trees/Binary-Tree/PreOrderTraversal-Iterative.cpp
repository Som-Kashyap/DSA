// Problem: 144

// Approach: Initate pointer from root and move pointer leftwards storing nodes in stack and res vector , follow order ( root->left->right). Move pointer to right on reaching leaf node( as the while loop ends )!

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node ( int val ) {

        data = val;
        left = NULL;
        right = NULL;

    }

};

vector<int> PreOrder ( Node* root ) {

    vector<int>res;
    stack<Node*>st;

    Node* node = root;

    while ( !st.empty() || node ) {

        while ( node ) {

        st.push( node );
        res.push_back ( node->data );
        node = node->left;

        }

    if ( !st.empty() ) {

    node = st.top();
    st.pop();

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

    vector<int>result = PreOrder( root );

    for ( int val : result ) {

        cout<<val<<" ";

    }
    cout<<endl;

    return 0;
    
}