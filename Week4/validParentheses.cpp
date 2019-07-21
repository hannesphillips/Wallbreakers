class Solution {
public:
    bool isValid(string s) {
        stack<char> syn;
        
        for(auto c : s) {
            if(c == '[' || c == '(' || c == '{')
                syn.push(c);
            else {
            if(syn.empty()) return false;                       // Unmatched ']', ')', or '}'
                if(syn.top() == '(' && c == ')') syn.pop();     // Proper matches
                else if(syn.top() == '[' && c == ']') syn.pop();
                else if(syn.top() == '{' && c == '}') syn.pop();
                else return false;
            }
        }
        // Unclosed pair
        if(syn.size()) return false;
        
        return true;
    }
};