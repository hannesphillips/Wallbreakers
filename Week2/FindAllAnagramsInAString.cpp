class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int psz = p.length();
        if(psz > s.length()) return {};
        
        multiset<char> key(p.begin(), p.end());
        vector<int> res;
        multiset<char> comp(s.begin(), s.begin() + psz);
        
        for(int i = 0; i < s.length() - psz + 1; i++) {
            if(key == comp) res.push_back(i);
           
            comp.erase(comp.find(s[i]));
            comp.insert(s[i + psz]);
        }
        return res;
    }
};