class Solution {
public:
    int titleToNumber(string s) {
        int c = 0, sz = s.size();
        for(int i = 0; i < sz; i++)
            c += pow(26, (sz -i-1)) * (int(s.at(i)) - 64);
        
        return c;
    }
    
};