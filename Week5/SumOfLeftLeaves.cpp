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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        getSum(sum, root, 0);
        
        return sum;
    }
    
    void getSum(int& x, TreeNode* t, int l) {
        if(t == NULL) return;
        
        if(t->left == NULL && t->right == NULL) {
            if(l) x += t->val;
            return;
        }
        getSum(x, t->left, 1);
        getSum(x, t->right, 0);
    }
};