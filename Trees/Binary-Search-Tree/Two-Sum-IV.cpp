// Problem LC: 653

// Approach: BST-Iterator is used, two pointers are initialized as objects and are moved accordingly to get the required sum. Nodes are stored in a stack for both the pointers in straight and reverse fashion for l and r.

// TC: O(N)
// SC: O(h)*2

#include<iostream>
#include<stack>

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

class BSTIterator{

    private:
    stack<TreeNode*>st;
    bool reverse = true;

      void pushAll(TreeNode* node) {

        while( node ) {

            node = reverse ? node->right : node->left;
            
        }
    }

    public:

    BSTIterator(TreeNode* root, bool isReverse ) {

        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(TreeNode* node) {

        return !st.empty();

    }
    
    int next() {

        TreeNode* temp = st.top();
        st.pop();

        if( !reverse ) pushAll(temp->right);

        else pushAll(temp->left);

        return temp->val;
    }

    bool FindTarget(TreeNode* root , int k) {

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while( i < j ) {

            int sum = i + j;

            if ( sum > k ) j = r.next();

            else if( sum==k ) return true;

            else i = l.next();
        }
        return false;
    }
};

