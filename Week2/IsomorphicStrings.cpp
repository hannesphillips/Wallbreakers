class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> key;
        set<char> mapped;
        
        for(int i = 0; i < s.length(); i++) {
            if(key.find(s[i]) != key.end()) {
                if(key[s[i]] != t[i]) return false;
            }
            else
            {
                if(mapped.find(t[i]) != mapped.end()) return false;
                key.insert({s[i], t[i]});
                mapped.insert(t[i]);
            }
        }
        
        
        return true;
    }
};