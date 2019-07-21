class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < 2) return;
        if(k == 0) return;
        if(k > nums.size()) k %= nums.size();
        queue<int> rot;
        
        for(auto x : nums) rot.push(x);
        for(int i = 0; i < rot.size() - k; i++){
            rot.push(rot.front());
            rot.pop();
        }
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = rot.front();
            rot.pop();
        }
    }
};