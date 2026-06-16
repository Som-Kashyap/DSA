// Problem: Inorder successor of BST

// Approach: Property of BST is used to traverse the given BST and succ is updated whenever a node having val>k and val<succ is found.

// TC: O(logn) for traversal
// SC: O(1) no extra space

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* successor( TreeNode* root, TreeNode* k ) {

    TreeNode* succ = NULL;

    if(!root) return NULL;

    while( root ) {

        if( root->val > k->val ) {

            succ = root;
            root=root->left;
        }

        else if( root->val <= k->val ) root=root->right;

    }
    return succ;
}

int main () {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(10);

    TreeNode* k = new TreeNode(3);

    TreeNode* res = successor( root , k );

    cout<<"The successor is: "<<res->val<<endl;

    return 0;

}