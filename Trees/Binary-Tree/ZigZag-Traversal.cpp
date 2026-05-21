// Problem : LC 103

// Approach: Mostly same as level-order,create a flag LeftToRight to select the index where nodes are pushed in the vector,toggle it after every iteration
            

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{

    int val;
     TreeNode* left;
     TreeNode* right;

    TreeNode( int data ) {7

        val=data;
        left = NULL;
        right = NULL;

    }

};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        queue<TreeNode*>q;
        vector<vector<int>>ans;

          if ( !root ) return ans;

        bool LeftToRight = true;

        q.push( root );

        while ( !q.empty() ) {

            int size = q.size();
            vector<int>level(size);

            for ( int i = 0; i < size; i++ ) {

                TreeNode* node = q.front();

                q.pop();

                int index = (LeftToRight ? i : size-i-1);

                level[index] = node->val;

                 if ( node->left ) q.push ( node->left );

                if ( node->right ) q.push ( node->right );

            }

            LeftToRight = !LeftToRight;
             ans.push_back ( level );

        }
        return ans;
    }

void print ( const vector<vector<int>>& ans ) {

        for ( auto &level : ans ) {

            for ( int val : level ) {

                cout<<val<<" ";

            }
            cout<<endl;
        }
    }

   int main () {

        struct TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(9);
        root->right = new TreeNode(20);
        root->right->left = new TreeNode(15);
        root->right->right = new TreeNode(7);

        vector<vector<int>> ans = zigzagLevelOrder ( root );
     
        print ( ans );

        return 0;

    }