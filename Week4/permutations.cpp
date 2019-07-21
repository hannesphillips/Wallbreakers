class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {{}};
        if(nums.size() == 1) return {{nums[0]}};

        set<vector<int>> s;
        // Set to eliminate duplicates
        permuteHelp(nums, s, 0);
        
        vector<vector<int>> res;
        for(auto v : s)
            res.push_back(v);
        
        return res;
    }
    
    void permuteHelp(vector<int>& nums, set<vector<int>>& s, int in) {
        
        for(int i = in; i < nums.size(); i++) {
            // Swap values to grow permutation set
            int tmp = nums[i];
            nums[i] = nums[in];
            nums[in] = tmp;
            
            // Recurse on swapped "array"
            permuteHelp(nums, s, in+1);
            // Add to set
            s.insert(nums);
            
            // Reset for next iteration
            tmp = nums[i];
            nums[i] = nums[in];
            nums[in] = tmp;
        }
    }
};