class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        bool carry = true;
        
        for(int i = digits.size()-1; i >= 0; i--) {
            if(carry) {
                if(digits.at(i) == 9)
                    v.insert(v.begin(), 0);
                else {
                    v.insert(v.begin(), digits.at(i) + 1);
                    carry = false;
                }
            }
            else
                v.insert(v.begin(), digits.at(i));
            
        }
        if(carry) v.insert(v.begin(), 1);
        return v;
    }
};