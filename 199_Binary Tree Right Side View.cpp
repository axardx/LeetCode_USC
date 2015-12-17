/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        queue<TreeNode*> tmp;
        
        if ( root )
            tmp.push(root);
        
        while ( !tmp.empty() ) {
            int size = tmp.size();
            for ( int i = 1; i <= size; i++ ) {
                TreeNode* node = tmp.front();
                if ( i == size )
                    ans.push_back(node->val);
                if ( node->left )
                    tmp.push(node->left);
                if ( node->right )
                    tmp.push(node->right);
                tmp.pop();
            }
        }
        
        return ans;
        
    }
};


// refer to discussion on LeetCode

class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};