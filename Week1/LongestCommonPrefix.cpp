class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string prefix = "";
        char t;
        for(int i = 0; i < strs.at(0).length(); i++) {
            t = strs.at(0).at(i);
            
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs.at(j).size()) return prefix;
                if(strs.at(j).at(i) != t) return prefix;
            }
            prefix += t;
        }
        return prefix;
    }
};