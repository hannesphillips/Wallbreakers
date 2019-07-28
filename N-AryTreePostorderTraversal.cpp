/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        // Empty tree
        if(root == NULL) return {};
        // Root only
        if(root->children.empty()) return {root->val};
        
        vector<int> res;
        traverse(res, root);
        res.push_back(root->val);       // Finish with root at end
        
        return res;
    }
    
    /* Traverse to leaf vector, add values, recurse to parent
    node. Continue to append child vectors then their parents
    until entire tree is visited */
    void traverse(vector<int>& r, Node* curr) {
        vector<Node*> kids = curr->children;
        
        for(int i = 0; i < kids.size(); i++) {
            if(!(kids[i]->children.empty()))
                traverse(r, kids[i]);
            
            r.push_back(kids[i]->val);
        }
        return;
    }
};