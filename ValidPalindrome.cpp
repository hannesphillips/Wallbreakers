class Solution {
public:
    bool isPalindrome(string s) {
        int f = 0, b = s.size()-1;
        while(f < b) {
            while(f < s.size() && !isalnum(s.at(f))) f++;
            while(b > 0 && !isalnum(s.at(b))) b--;
            
            if(f > b) break;
            if(tolower(s.at(f)) != tolower(s.at(b))) return false;
            f++;
            b--;
        }
        
        return true;
    }
};