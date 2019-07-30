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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) 
            return true;
        if(root1 == NULL && root2 != NULL ||
          root1 != NULL && root2 == NULL) 
            return false;
        
        vector<int> leafval1;
        getLeaves(leafval1, root1); // Acquire leaf value sequence of tree 1
        
        int x = 0;
        return tree2Sim(leafval1, x, root2); // Compare with tree 2 and return
    }
    
    /* When a leaf node is reached, compare with tree 1 leaf vector.
    If match, increment index counter and continue, else return false.
    Boolean comparison in recursion tree will bubble up correct value */
    bool tree2Sim(vector<int> l, int& dex, TreeNode* r) {
        if(r == NULL) return true;
        if(r->left == NULL && r->right == NULL) {
            if(dex >= l.size()) return false;
            if(r->val != l[dex]) return false;
            
            dex++;
            return true;
        }
        
        return tree2Sim(l, dex, r->left) && tree2Sim(l, dex, r->right);
    }
    
    /* Push leaf nodes to vector */
    void getLeaves(vector<int>& l, TreeNode* r) {
        if(r == NULL) return;
        if(r->left == NULL && r->right == NULL) {
            l.push_back(r->val);
            return;
        }
        
        getLeaves(l, r->left);
        getLeaves(l, r->right);
        return;
    }
};