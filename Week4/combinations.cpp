class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if(k == 0) return {{}};
        
        vector<vector<int>> res;
        vector<int> v;
        combo(res, v, 1, n, k);
        
        return res;
    }
    
    void combo(vector<vector<int>>& r, vector<int>& v, int in, int n, int k) {
        // If set size = k, done with that possibility
        if(v.size() == k) {
            r.push_back(v);
            return;
        }
        
        // Build combinations
        for(int i = in; i <= n; i++) {
            v.push_back(i);
            combo(r, v,  i+1, n, k);        // Recursively expand
            v.pop_back();
        }
    }
};