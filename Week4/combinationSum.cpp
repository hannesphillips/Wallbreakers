class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return {{}};
        
        // Sorting ensures logic check on sum
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;
        vector<int> v;
        
        DFS(candidates, res, v, 0, target);
        
        return res;
    }
    
    void DFS(vector<int>& c, vector<vector<int>>& r, vector<int>& v, int dex, int t) {
        // Set reaches target, add to solution set
        if(t == 0) {
            r.push_back(v);
            return;
        }
        
        /* Expand set path, if lowest value in vector causes set
        to surpass target, all remaining values will exceed as well -> break, 
        then backtrack. Otherwise, add to combination and recursively continue */
        for(int i = dex; i < c.size(); i++) {
            if(c[i] > t) break;
            
            v.push_back(c[i]);
            DFS(c, r, v, i, t-c[i]);
            v.pop_back();
        }
    }
};