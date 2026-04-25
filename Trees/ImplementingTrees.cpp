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

int main () {

    Node* root = new Node(1);
    Node* n1 = new Node(2);

    addChild ( root , n1 );

    return 0;

}