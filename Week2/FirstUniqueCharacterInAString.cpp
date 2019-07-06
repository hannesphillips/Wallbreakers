class Solution {
public:
    int firstUniqChar(string s) {
        int res = s.length();
        multiset<char> letters;
        int coord[26];
        
        for(int i = res - 1; i >= 0; i--) {
            letters.insert(s[i]);
            coord[s[i] - 'a'] = i;
        }
    
        for(int i = 0; i < 26; i++)
            if(letters.count('a' + i) == 1)
                res = min(res, coord[i]);
        
        if(res == s.length()) return -1;
        return res;
    }
};