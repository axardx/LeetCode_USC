// refer to discussion in LeetCode

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if ( !root )
            return NULL;
        if ( root == p || root == q )
            return root;
        
        TreeNode* l = lowestCommonAncestor( root->left, p, q);
        TreeNode* r = lowestCommonAncestor( root->right, p, q);
        
        if ( l && r )
            return root;
        else if ( !l )
            return r;
        else
            return l;
        
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *lca = root;
        while (lca) {
            if (lca == p || lca == q || (lca->val > min(p->val, q->val) && lca->val < max(p->val, q->val)) )
                break;
            else if (lca->val < min(p->val, q->val))
                lca = lca->right;
            else if (lca->val > max(p->val, q->val))
                lca = lca->left;
        }
        return lca;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }
        // check if the current value is larger than both nodes , go left
        if(p->val < root->val && q->val < root->val){
            lowestCommonAncestor(root->left , p , q);
            // go right
        }else if(p->val > root->val && q->val > root->val){
            lowestCommonAncestor(root->right , p , q);
        }// my LCA
        else{
            return root;
        }
    }
};
