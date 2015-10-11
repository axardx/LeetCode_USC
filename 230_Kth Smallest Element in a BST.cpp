// refer to http://www.geeksforgeeks.org/find-k-th-smallest-element-in-bst-order-statistics-in-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> tmp;
        TreeNode *node;
        
        // Inorder traverse - Left->Root->Right
        while ( root ) {
            tmp.push(root);
            root = root->left;
        }
        
        while ( !tmp.empty() ) {
            TreeNode *node = tmp.top();
            tmp.pop();
            k--;
            if ( k == 0 )
                return node->val;
            
            if ( node->right ) {
                node = node->right;
                
                while ( node ) {
                    tmp.push(node);
                    node = node->left;
                }
            }
        }
    }
};