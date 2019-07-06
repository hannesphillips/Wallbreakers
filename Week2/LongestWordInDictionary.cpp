class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string> wordset;
        string res = "";
        
        for(auto w : words) wordset.insert(w);
        
        for(auto w : words) {
            if(w.length() > res.length() || w.length() == res.length() && w.compare(res) < 0) {
                bool flag = true;
                
                for(int i = 1; i < w.length(); i++) {
                    if(wordset.find(w.substr(0, i)) == wordset.end()) {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    res = w;
            }
        }
        
        return res;
    }
};