// Problem LC:701

// Approach: Insert position of the required node is found,new node is created and linked while maintaing the order as that of a BST

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if( !root ) return new TreeNode(val);

        TreeNode* curr = root;

        while( true ) {

            if( curr->val <= val ) {

                if( curr->right != NULL ) {

                    curr = curr->right;

                }
                else{
                curr->right = new TreeNode(val);
                break;
                }
            }

            else {

                if( curr->left != NULL ) {

                    curr = curr->left;

                }
                else{
                curr->left = new TreeNode(val);
                break;
                }
            }
        }
        return root;
    }

    int main () {

        TreeNode* root = new TreeNode(4);
        root->right = new TreeNode(7);
        root->left = new TreeNode(2);
        root->left->right = new TreeNode(3);
        root->left->left = new TreeNode(1);

        int val = 5;

        TreeNode* res = insertIntoBST( root , val );

        cout<<"Root of the resulting tree is: "<<res->val<<endl;

        return 0;
        
    }