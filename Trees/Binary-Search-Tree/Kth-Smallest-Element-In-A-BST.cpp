// Problem LC: 230

// Approach: array formed from in-order traversal of a BST is always sorted,and kth smallest is simply array[k-1] for such an array

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

 void inorderTraversal( TreeNode* root, int k , vector<int>& inorder ) {

        if( !root ) return;

        inorderTraversal(root->left , k , inorder );
        inorder.push_back(root->val);
        inorderTraversal(root->right , k , inorder);

    }

int kthSmallest(TreeNode* root, int k) {
        
        vector<int>inorder;

        inorderTraversal( root , k , inorder );

        return inorder[k-1];

    }

    int main() {

        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(1);
        root->left->right = new TreeNode(2);
        root->right = new TreeNode(4);
        
        int k = 1;

        cout<<"Kth smallest element is: "<<kthSmallest(root,k)<<endl;

        return 0;

    }