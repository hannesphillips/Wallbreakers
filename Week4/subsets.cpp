class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};
        if(nums.size() == 1) return {{}, nums};
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        vector<int> v;
        subsetHelp(nums, v, res, 0);
        
        return res;
    }
    void subsetHelp(vector<int>& nums, vector<int>& v, vector<vector<int>>& r, int i) {
        r.push_back(v); // Add each subset here
        
        // Expand combinations and recursively expand set;
        for(int l = i; l < nums.size(); l++) {
            v.push_back(nums[l]);
            subsetHelp(nums, v, r, l+1);
            
            v.pop_back();
        }
        return;
    }
};