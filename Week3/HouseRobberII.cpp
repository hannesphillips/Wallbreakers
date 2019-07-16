class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        /* Even and odd starting point with inclusion of first or last house */
        int rob1 = nums[0];
        int nrob1 = 0;
        int rob2 = 0;
        int nrob2 = 0;
        
        /* Included first house and last house accounted for out of loop.
        Tally running total of each house, alternating to avoid adjacency. */
        for(int i = 1; i < nums.size() - 1; i++) {
            if(!(i % 2))
            {
                rob1 = max(rob1 + nums[i], rob2);
                nrob1 = max(nrob1 + nums[i], nrob2);
            }
            else {
                rob2 = max(rob2 + nums[i], rob1);
                nrob2 = max(nrob2 + nums[i], nrob1);
            }
        }       
        if(nums.size() % 2)
            nrob1 = max(nrob1 + nums[nums.size()-1], nrob2);
        else
            nrob2 = max(nrob2 + nums[nums.size()-1], nrob1);
        
        return max(max(rob1, rob2), max(nrob1, nrob2));
    }
};