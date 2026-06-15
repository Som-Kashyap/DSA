// Problem LC: 235

// Approach: Lowest Common Ancestor is the node lying at the first intersection of the paths originating from the target nodes. If there is a node having a target on each of the left and the right sub-trees, that node is the LCA.

#include<iostream>

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if( !root ) return NULL;

        else if( p->val >= root->val && q->val <= root->val ) return root;

        else if( p->val <= root->val && q->val >= root->val ) return root;

        else if( p->val <= root->val && q->val <= root->val )  return lowestCommonAncestor( root->left , p , q );

            else  return lowestCommonAncestor( root->right , p , q );

 }

 int main() {

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(0);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(3);
    root->left->left->right->right = new TreeNode(5);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);


    TreeNode* res = lowestCommonAncestor( root , p , q );

    cout<<"LCA is: "<<res->val<<endl;

    return 0;

 }