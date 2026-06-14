// Problem LC:2476

// Approach: In-order of the BST is stored in an array,lower_bound is used to find the first element just greater than the query,edge-cases like absence of either the max or min are evaluated,and {min,max} is pushed to ans array

#include<iostream>
#include<vector>
#include<algorithm> 

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

void inorder(TreeNode* root, vector<int> &arr) {

    if(root == nullptr) return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);

}

vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {

    vector<vector<int>> ans;
    vector<int> arr; 
    inorder(root, arr);
    int n = arr.size();

    for(auto &val : queries) {

        int i = lower_bound(arr.begin(), arr.end(), val) - arr.begin();

        if(i < n && arr[i] == val) {
            ans.push_back({val, val});
        }
        else if(i == 0) {
            ans.push_back({-1, arr[0]});
        }
        else if(i == n) {
            ans.push_back({arr[n-1], -1}); 
        }
        else {
            ans.push_back({arr[i-1], arr[i]});
        }

    }

    return ans;

}


int main() {

    vector<int> queries = {2, 5, 16};

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(13);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(15);
    root->right->right->left = new TreeNode(14);

     vector<vector<int>> result = closestNodes(root, queries);

   
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]"<<" ";
    }
    cout<<endl;

    return 0 ;
}
