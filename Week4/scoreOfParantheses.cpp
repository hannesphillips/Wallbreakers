class Solution {
public:
    int scoreOfParentheses(string S) {
        if(S.length() == 0) return 0;
        if(S.length() % 2) return -1;
        
        stack<int> p;
        p.push(0);
        
        for(auto c : S) {
            // Build stack of init value for new open parens
            if(c == '(') 
                p.push(0);
            // Resolve pairs 1 for 1st (), 2* prev value for (()) so on
            else {
                int tmp = p.top();
                p.pop();
                p.top() += max(1, 2 * tmp);
            }
        }
        return p.top();
    }
};