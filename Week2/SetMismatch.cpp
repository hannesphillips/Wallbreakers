class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        multiset<int> num(nums.begin(), nums.end());
        int dup, miss;
        
        for(int i = 1; i <= nums.size(); i++) {
            if(num.find(i) == num.end()) miss = i;
            else
                if(num.count(i) == 2) dup = i;
        }
        return {dup, miss};
    }
};