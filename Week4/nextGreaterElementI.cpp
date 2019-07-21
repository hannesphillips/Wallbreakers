class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()) return {};
        
        int l;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            l = nums2.size();
            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) l = j;
                if(l != nums2.size() && nums2[j] > nums1[i]) {
                    res.push_back(nums2[j]);
                    goto z;
                }
            }
            res.push_back(-1);
            z:;
        }
        return res;
    }
};