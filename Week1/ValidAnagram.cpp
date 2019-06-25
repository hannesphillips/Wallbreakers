class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        
        array<int, 26> cnt;
        cnt.fill(0);
        
        for(int i = 0; i < s.length(); i++) {
            cnt[s[i]- 'a'] += 1;
            cnt[t[i] - 'a'] -= 1;
        }
        
        for(auto& x : cnt)
            if(x != 0)
                return false;
        return true;
    }
};