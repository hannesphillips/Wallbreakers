class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int sz = s.size();
        for(int i = 0; i < sz/2; i++) {
            tmp = s.at(i);
            s.at(i) = s.at(sz - 1 - i);
            s.at(sz - 1 - i) = tmp;
        }
    }
};