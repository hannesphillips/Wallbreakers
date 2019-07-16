class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0;
        // Sorting pairs translates to greatest min values
        // at all even indices
        for(int i = 0; i < nums.size(); i += 2)
            res += nums[i];
        
        return res;
    }
};