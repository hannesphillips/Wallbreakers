class Solution {
public:
    string reverseWords(string s) {
        size_t wp;
        string res = "", sub;
        
        wp = s.find(' ');
        if(wp == string::npos) return swapString(s);
        
        for(int i = 0; i < s.size(); i++) {
            wp = s.find(' ', i);
            sub = s.substr(i, wp-i);
            
            res += swapString(sub);
            
            if(wp == string::npos) break; 
            res += ' ';
            i += wp-i;
        }
        return res;
    }
    
    string swapString(string s) {
        char t;
        
        for(int j = 0; j < s.size()/2; j++) {
            t = s.at(j);
            s.at(j) = s.at(s.size()-1-j);
            s.at(s.size()-1-j) = t;
        }
        return s;
    }
};