class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> vals;
        vector<int> res;
        
        for(auto i : nums1)
            vals.insert(i);
        for(auto j : nums2)
            if(vals.find(j) != vals.end()) {
                res.push_back(j);
                vals.erase(j);
            }
        
        return res;
    }
};