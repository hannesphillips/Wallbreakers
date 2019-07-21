class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k > nums.size()) return false;
        
        int total = 0;
        for(auto x : nums) total += x;
        // All integers in a partition must have equivalent sums
        if(total % k) return false;
        
        sort(nums.begin(), nums.end());
        // If a value exists that is larger than the required sum of a partition, exit
        if(nums[nums.size()-1] > total / k) return false;
        
        vector<vector<int>> v (k);
        return kpartComb(nums, v, nums.size() - 1, total / k);
    }
    
    bool kpartComb(vector<int>& nums, vector<vector<int>>& parts, int dex, int t) {
        // Once all values have been utilized, we may return true
        if(dex < 0) return true;
        
        /* Take each value in nums and place it in a partition it does not
        cause to exceed the sum. Working in reverse utilizes values that can
        satisfy a partition sooner (speed up). Continue to recursively do so.
        If a value cannot be placed, back track, remove last value from its 
        partition and try another. Continue process until all values used (true)
        or all possible failed combinations are utilized (false). */
        int x = nums[dex];
        for(int i = 0; i < parts.size(); i++) {
            
            int part_sum = accumulate(parts[i].begin(), parts[i].end(), 0);
            if(part_sum + x <= t) {
                parts[i].push_back(x);
                
                if(kpartComb(nums, parts, dex - 1, t))
                    return true;
                
                parts[i].pop_back();
            }
            
            /* If value was tested in an empty partition,
            its's futile to continue testing this value in the
            current arrangement */
            if(!part_sum) break;
        }
        return false;
    }
};