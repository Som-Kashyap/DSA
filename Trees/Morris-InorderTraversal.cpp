#include<iostream>
#include<vector>

using namespace std;

struct Node {

    int val;
    Node* left;
    Node* right;

    Node( int data ) {

        val = data;
        left = NULL;
        right = NULL;

    }
};

vector<int> Inorder(Node* root, vector<int>& inorder) {
    Node* curr = root;

    while (curr) {

        if (curr->left == NULL) {

            inorder.push_back(curr->val);
            curr = curr->right;

        } 

        else {

            Node* prev = curr->left;

            while (prev->right && prev->right != curr) {

                prev = prev->right;

            }

            if (prev->right == NULL) {

                prev->right = curr; 
                curr = curr->left; 

            } else {

                prev->right = NULL; 
                inorder.push_back(curr->val);
                curr = curr->right;

            }
        }
    }

    return inorder;

}

int main () {

    struct Node* root = new Node(1);
    root->right = new Node(3);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);

    vector<int>inorder;

    Inorder ( root , inorder );

    for ( int nodes : inorder ) {

        cout<<nodes<<" ";

    }
    cout<<endl;

    return 0;

}