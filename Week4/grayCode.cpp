class Solution {
public:
    vector<int> grayCode(int n) {
        if(!n) return {0};
        
        vector<int> v;
        
        /* Utilize binary shifting properties.
        Right shifting then xor yields values with a single bit difference */
        for(int i = 0; i < (1 << n); i++) {
            int j = i >> 1;
            // cout << "i: " << i << " i >> 1: " << j << " i xor i >> 1: " << (i ^ j) << endl;
            v.push_back(i ^ j);
        }
        return v;
    }
};