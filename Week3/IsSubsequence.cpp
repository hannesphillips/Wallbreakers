class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        
        for(auto c : t) {
            if(c == s[si])
                si++;
        }
        
        if(si == s.size()) return true;
        return false;
    }
};