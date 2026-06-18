// Problem LC:530

// Approach: prev variable is maintained for finding diff bw curr and prev node which is then assigned value of curr node.
//           Inorder traversal is used to find diff of sorted nodes

//  TC: O(n) for traversal
//  SC: O(logn)

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

int getMinimumDifference(TreeNode* root , int prev , int &minDiff) {
        
        if( !root ) return minDiff;

        getMinimumDifference( root->left , prev , minDiff );

        if( prev >= 0 ) minDiff = abs(min( minDiff , root->val - prev ));

        prev = root->val;

        getMinimumDifference( root->right , prev , minDiff );

        return minDiff;
    }

    int main() {

        TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->right = new TreeNode(6);

        int prev = -1;
        int minDiff = INT_MAX;

        int res = getMinimumDifference( root , prev , minDiff );

        cout<<"Minimum difference is: "<<res<<endl;

        return 0;
    }