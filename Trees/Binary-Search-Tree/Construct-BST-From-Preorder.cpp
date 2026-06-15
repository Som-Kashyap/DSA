// Problem LC: 1008

// Approach: First element of the preorder array is the root of the BST, property of BST is then used accoring to which for any given node, (left->val<root->val<right->val)

#include<iostream>
#include<climits>
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

 TreeNode* buildBST( vector<int>& preorder , int &i, long max ) {

        if( i == preorder.size() || preorder[i] > max ) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]); 

        root->left = buildBST( preorder , i , root->val );
        root->right = buildBST( preorder , i , max );
        
        return root;
        
    }

int main() {

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(12);

    vector<int>preorder = {8,5,1,7,10,12};
    int i = 0;
    TreeNode* res = buildBST(preorder , i , LONG_MAX);

    cout<<"Root of the resulting tree is: "<<res->val<<endl;

    return 0;

}