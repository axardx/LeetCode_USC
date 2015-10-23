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
    int minDepth(TreeNode* root) {
        
        if ( root == NULL )
            return 0;
        
        if ( root->right == NULL )
            return minDepth(root->left)+1;
        
        else if ( root->left == NULL )
            return minDepth(root->right)+1;
        
        else
            return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    int minDepth(TreeNode* root) {
        if ( !root )
            return 0;
        else if ( !root->left && !root->right )
            return 1;
        
        vector<TreeNode*> tmp;
        tmp.push_back(root);
        int count = 0;
        
        while ( !tmp.empty() ) {
            
            count++;
            int n = tmp.size();
            for ( int i = 0; i < n; i++ ) {
                TreeNode* node = tmp.back();
                tmp.pop_back();
                if ( node->left == NULL && node->right == NULL )
                    return count;
                
                if ( node->left )
                    tmp.insert(tmp.begin(), node->left);
                if ( node->right )
                    tmp.insert(tmp.begin(), node->right);
            }
        }
    }
};