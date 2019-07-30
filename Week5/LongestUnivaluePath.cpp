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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        
        int path = 0;
        expand(root, path);
        
        return path;
    }
    
    int expand(TreeNode* t, int& p) {
        if(t == NULL) return 0;
        
        int l = expand(t->left, p);
        int r = expand(t->right, p);
        
        
        if(t->left != NULL && t->left->val == t->val)
            l++;
        else l = 0;
        
        if(t->right != NULL && t->right->val == t->val)
            r++;
        else r = 0;
        
        p = max(p, l + r);
        return max (l, r);
    }
};