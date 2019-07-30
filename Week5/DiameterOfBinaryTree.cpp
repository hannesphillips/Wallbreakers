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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int dim = 0;
        expand(root, dim);
        
        return dim;
    }
    int expand(TreeNode* t, int& dim) {
        if(t == NULL) return 0;
        
        int l = expand(t->left, dim);
        int r = expand(t->right, dim);
        
        dim = max(dim, l + r);
        return max(l, r) + 1;
    }
};