class Solution {
public:
    int numJewelsInStones(string J, string S) {
        /* Construct map for lookup */
        unordered_map<char, int> jewels;
        for(int i = 0; i < J.length(); i++) {
            jewels.insert({J[i], i});
        }
        
        int cnt = 0;
        for(int i = 0; i < S.length(); i++) {
            if(jewels.find(S[i]) != jewels.end())
                cnt++;
        }
        return cnt;
    }
};