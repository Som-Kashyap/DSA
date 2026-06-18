// Problem LC:99

// Approach: inorder-traversal is used and pointers are initialized, values are swapped as discrepanices in BST order are found.
//  If the last pointer remains NULL, it means that the incorrectly placed nodes are adjacent and are swapped, else first and last are swapped.

//  TC: O(N) for morris traversal
//  SC: O(1) no extra space

#include<iostream>
#include<climits>

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

class RecoverBST{

    private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;

    public:

    void inorder(TreeNode* root) {

        if( !root ) return;

        inorder( root->left );

        if( prev->val > root->val ) {

            if( first == NULL ) {
                first = prev;
                mid = root;
            }
            else{

                last = root;

            }
        }
        
        prev = root;
        inorder( root->right );
    }

    void recover() {

        first = mid = last = NULL;

        prev = new TreeNode(INT_MIN);

        inorder(root);

        if( first && last ) swap( first->val , last->val );

        else if( first && mid ) swap( first->val , mid->val );

    }
};

