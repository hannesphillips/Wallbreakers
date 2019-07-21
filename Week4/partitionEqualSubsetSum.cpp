class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2) return false;
        if(nums.size() == 2) return nums[0] == nums[1];
        
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        for(auto x : nums) sum += x;
        if(sum % 2) return false;
        
        return partComb(nums, 0, sum / 2);
    }
    
    bool partComb(vector<int> nums, int i, int target) {
        // Matched totalSum / 2
        if(target == 0)
            return true;
        
        // Tried all values, cannot be partitioned
        if(i >= nums.size()) return false;
        
        // Values exceeded sum, bactrack
        if(target < 0) return false;
        
        // Attempt to validate current set
        if(partComb(nums, i+1, target - nums[i]))
            return true;
        
        int l = i + 1;
        // Acquire next index that is not a duplicate
        while(l < nums.size() && nums[i] == nums[l]) l++;
        
        return partComb(nums, l, target);
    }
};