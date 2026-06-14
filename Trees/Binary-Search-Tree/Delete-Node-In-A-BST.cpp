// Problem LC:450

// Approach: The required node is located and the right-most node of the left sub-tree is linked to parent node of the right sub-tree,this is then linked to the parent node of the target node

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

    TreeNode* findLastRight( TreeNode* root ) {

        if( !root->right ) return root;

        else return findLastRight( root->right );

    }

    
    TreeNode* helper( TreeNode* root ) {

        if( !root->left ) return root->right;
        else if( !root->right ) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRightChild = findLastRight( root->left );

        lastRightChild->right = rightChild;
        return root->left;

    }

TreeNode* deleteNode(TreeNode* root, int key) {
        
        if( !root ) return root;

        if( root->val == key ) return helper(root);
        TreeNode* dummy = root;

        while( root ) {

            if( root->val > key ) {

                if( root->left && root->left->val == key ) {

                    root->left = helper( root->left );

                }
                else{
                    root = root->left;
                }
            }
            else {

                if( root->right && root->right->val == key ) {

                    root->right = helper( root->right );

                }
                root = root->right;
            }
        }
        return dummy;
    }


    int main () {

        TreeNode* root = new TreeNode(5);
        root->right = new TreeNode(6);
        root->right->right = new TreeNode(7);
        root->left = new TreeNode(3);
        root->left->right = new TreeNode(4);
        root->left->left = new TreeNode(2);

        int key = 3;

        TreeNode* res = deleteNode( root , key );

        cout<<"Root of the resulting tree is: "<<res->val<<endl;

        return 0;

    }