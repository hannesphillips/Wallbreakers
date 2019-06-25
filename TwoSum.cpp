class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> n;
        
        for(int i = 0; i < nums.size(); i++) {
            if(n.count(target - nums[i]) != 0)
                return {n[target - nums[i]], i};
            n.insert({nums[i], i});
        }
        return {0, 0};
    }
};