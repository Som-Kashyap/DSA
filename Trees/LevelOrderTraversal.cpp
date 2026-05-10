// Problem: LC 102

// Approach: Initialize pointer from root , move it down storing current node into the queue,push left and right if applicable

// Why this works? : front node is selected and popped,subsequent left and right nodes are pushed,size of the queue is being updated every iteration,then nodes are pushed to the vector (level wise as no. of iterations=no. of nodes at each level)

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node( int val ) {

        val = data;

        left = NULL;
        right = NULL;

    }
};

vector<vector<int>> levelorder ( Node* root ) {

    vector<vector<int>>ans;
    queue<Node*>q;

    q.push ( root );

    while ( !q.empty() ) {

        int size = q.size();
        vector<int>level;

        for ( int i = 0; i < size; i++ ) {

            Node* node = q.front();
            q.pop();

            if ( node->left ) q.push ( node->left );
            if ( node->right ) q.push ( node->right );

            level.push_back ( node->data );

        }
        
        ans.push_back ( level );

    }

    return ans;

}

int main () {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    levelorder ( root );

    return 0;

}