// Problem LC:173

// Approach: Left sub-tree elements of the nodes are pushed to a stack, this maintains in-order traversal order since stack is LIFO. The function next() returns the smallest untravelled node that is node->left where node=st.top().

#include<iostream>
#include<vector>
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

class BSTIterator {

    private:
    stack<TreeNode*>st;

    public:

    BSTIterator(TreeNode* root) {

        pushLeft(root);

    }

    void pushLeft(TreeNode* node) {

        while( node ) {

            st.push(node);
            node=node->left;
        }
    }

    bool hasNext() {

        return !st.empty();

    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        int result = node->val;

        if( node->right ) pushLeft(node->right);

        return result;

    }
};

TreeNode* createTree(TreeNode* root , int val ) {

    if( !root ) return new TreeNode(val);

    if( val < root->val ) root->left = createTree(root->left , val);
    else root->right = createTree(root->right , val);

    return root;

}

int main () {

    TreeNode* root = nullptr;
    vector<int>values = {7, 3, 15, 9, 20};

    for( int value : values) {

        createTree(root,value);

    }

    BSTIterator it(root);

    return 0;
}
