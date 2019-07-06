class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> phrs;    
        int loc, k = 0;
        
        while(loc != string::npos) {
            loc = str.find(' ', k);
            phrs.push_back(str.substr(k, loc - k));
            
            k = loc + 1;
        }
        if(phrs.size() != pattern.length()) return false;
        // for(auto i : phrs) cout << i << endl;
        
        map<char, string> mapping;
        set<string> mapped;
        
        for(int i = 0; i < pattern.length(); i++) {
            if(mapping.find(pattern[i]) != mapping.end()) {
                if(mapping[pattern[i]] != phrs[i])
                    return false;
            }
            else {
                if(mapped.find(phrs[i]) != mapped.end())
                    return false;
                
                mapping.insert({pattern[i], phrs[i]});
                mapped.insert(phrs[i]);
            }
        }
        
        return true;
    }
};