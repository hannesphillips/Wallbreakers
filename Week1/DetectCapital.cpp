class Solution {
public:
    bool detectCapitalUse(string word) {
        bool AllCaps = true, Camel = true;
        if(islower(word.at(0))) {                   // First letter not capital
            for(int i = 1; i < word.size(); i++)
                if(isupper(word.at(i)))
                    return false;
        }
        
        for(int i = 1; i < word.size(); i++) {
            if(islower(word.at(i)))                 // Check all caps
                AllCaps = false;
            if(isupper(word.at(i)))                 // Check 1st capital and all lower
                Camel = false;
        }
        
        if(AllCaps | Camel) return true;
        return false;
    }
};