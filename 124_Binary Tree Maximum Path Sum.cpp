// refer to discussion on LeetCode

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
    int maxsum = INT_MIN;
    
    int traverse(TreeNode* root) {
        if ( root == NULL)
            return 0;
        
        int left = max(traverse(root->left), 0);
        int right = max(traverse(root->right), 0);
        
        maxsum = max(maxsum, left + right + root->val );
        return max(left, right) + root->val;
    }
    
    
    int maxPathSum(TreeNode* root) {
        
        traverse(root);
        return maxsum;
        
    }
};