class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i;
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            i = (l + r) / 2;                    // Midpoint to search by
            if(nums[i] == target) return i;
            
            if(target > nums[i]) l = i + 1;     // Search left or right branch
            else r = i - 1;
        }
        return -1;
    }
};