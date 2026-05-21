#include<iostream>
#include<vector>

using namespace std;

struct Node {

    int data;
    
    vector<Node*>children;

    Node ( int val ) {

        data = val;

    }
};

void addChild ( Node* parent , Node* child ) {

    if ( parent!=nullptr ) {

        parent->children.push_back ( child );

        cout<<"parent:"<<parent->data<<" and child:"<<child->data<<endl;

    }

    else throw runtime_error("Parent node is empty!");

}

void printParents ( Node* node , Node* parent ) {

    if ( parent = NULL ) cout<<node->data<<"-> null(0)"<<endl;

    else cout<<node->data<<"->"<<parent->data<<endl;

    for ( auto child : node->children ) printParents ( child , node );

}

int main () {

    Node* root = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);

    addChild ( root , n1 );
    addChild (root , n2);

    printParents ( n1 , root );

    return 0;

}