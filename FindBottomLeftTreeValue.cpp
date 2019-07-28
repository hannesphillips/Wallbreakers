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
    int findBottomLeftValue(TreeNode* root) {
        // Map holds left most leaf at each depth in the tree
        unordered_map<int, int> levels;
        int maxDepth = 1;
        
        dive(root, 1, maxDepth, levels);
        return levels[maxDepth];
    }
    
    /* Iterate through tree inorder right to left. Overwriting right to
    left ensures the leftmost leaf is present in the map. Track greatest leaf
    depth to pull that value from map at end */
    void dive(TreeNode* t, int curr_depth, int& d, unordered_map<int, int>& m) {
        if(t == NULL) return;
        
        if(t->left == NULL && t-> right == NULL) {
            if(curr_depth > d) d = curr_depth;
            m[curr_depth] = t->val;
            return;
        }
        
        dive(t->right, curr_depth + 1, d, m);
        dive(t->left, curr_depth + 1, d, m);
    }
};