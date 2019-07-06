class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        multiset<string> words;
        unordered_set<string> bans;
        for(auto i : banned)
            bans.insert(i);
        
        string s = "", res;
        int cnt = 0;
        
        for(auto c : paragraph) {
            if(isalpha(c))
                s += tolower(c);
            else if(s.length()) {
                if(bans.find(s) == bans.end())
                    words.insert(s);
                s.clear();
            }
        }
        if(s.length())
            if(bans.find(s) == bans.end())
                words.insert(s);
        
        for(auto i : words)
            if(words.count(i) > cnt) {
                res = i;
                cnt = words.count(i);
            }
        return res;
    }
};