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
    bool hasPathSum(TreeNode* root, int sum) {
        
        int ans = 0;
        return PathSum(root, ans, sum);
    }
    
    bool PathSum(TreeNode* root, int ans, int sum) {
        
        if ( !root )
            return false;
        
        if ( root->left == NULL && root->right == NULL )
            return ans+root->val == sum;
        
        return PathSum(root->left, ans+root->val, sum) || PathSum(root->right, ans+root->val, sum);
        
    }
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Another Solution from Discussion in LeetCode


bool hasPathSum(struct TreeNode* root, int sum) {
    
    if (!root)
        return false;
    
    if (!root->right && !root->left)
        return sum == root->val;
    
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}