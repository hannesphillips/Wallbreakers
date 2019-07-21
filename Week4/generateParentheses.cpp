class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(!n) return {};
        if(n == 1) return {"()"};
        
        set<string> s;
        pearComb(s, "", 0, 2*n, 0);
        
        vector<string> res;
        for(auto p : s)
            res.push_back(p);
        
        return res;
    }
    
    void pearComb(set<string>& r, string s, int i, int n, int bal) {
        if(bal < 0) return;                 // ')' before an opening '('
        if(i == n && bal == 0) {            // Balance set of parenthesis
            r.insert(s);
            return;
        }
        if(i == n) return;                  // Unbalanced
        
        s += "(";                           // Expand recursive tree
        pearComb(r, s, i+1, n, bal+1);
        s[i] = ')';
        pearComb(r, s, i+1, n, bal-1);
        
        return;
    }
};