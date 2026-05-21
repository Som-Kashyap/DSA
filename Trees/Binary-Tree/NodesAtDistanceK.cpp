// Problem: LC-863

// Approach: Point to the target nodes and move outwards from it until distance equals k. Parent nodes are stored in hashmap for upward traversal. Visited nodes are stored in a hashmap to avoid re-traversal. 

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

struct Node{

    int val;
    Node* left;
    Node* right;

    Node( int data ) {

        val = data;
        left = NULL;
        right = NULL;

    }

};

void addParents ( Node* root , int k , Node* target , unordered_map<Node* , Node*> &parents ) {

    queue<Node*>q;

    q.push ( root );

    while ( !q.empty() ) {

        Node* node = q.front();
        q.pop();

        if( node->left ) {

            q.push( node->left );
            parents[ node->left ] = node;

        } 

        if( node->right ) {

            q.push( node->right );
            parents[ node->right ] = node;

        }
    }
}

vector<int> NodesAtDiatnceK( Node* root , int k , Node* target , vector<int> &resNodes ) {

    unordered_map<Node* , Node*>parents;
    unordered_map<Node* , bool>visited;
    queue<Node*>queue;

    queue.push( target );
    visited[ target ] = true;

    int currlevel = 0;

    addParents( root , k , target , parents );

    while( !queue.empty() ) {

        int size = queue.size();

        if ( currlevel++ == k ) break;

        for ( int i = 0; i < size; i++ ) {

            Node* node = queue.front();
            queue.pop();

            if ( node->left && !visited[node->left] ) {

                queue.push( node->left );
                visited[ node->left ] = true;

            }

            if ( node->right && !visited[ node->right ] ) {

                queue.push( node->right );
                visited[ node->right ] = true;

            }

            if ( parents[node] && !visited[parents[node]] ) {

                queue.push( parents[node] );
                visited[ parents[node] ] = true;

            }
        }
    }

    while ( !queue.empty() ) {

        Node* node = queue.front();
        queue.pop();

        resNodes.push_back( node->val );
        
    }

    return resNodes;

}

int main () {

    struct Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->right = new Node(4);
    root->left->right->left = new Node(7);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    int k = 2;
    Node* target = root->left;

    vector<int>resNodes;

    NodesAtDiatnceK ( root , k , target , resNodes );

    for ( int res : resNodes ) {

        cout<<res<<" ";

    }
    cout<<endl;

    return 0;

}