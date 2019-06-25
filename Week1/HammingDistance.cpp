class Solution {
public:
    int hammingDistance(int x, int y) {
        int ham = 0;
        string s = bitset<32>(x ^ y).to_string();
        if(s.find('1') == string::npos) return 0;
        
        s = s.substr(s.find('1'));
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') ham++;
        }
        return ham;
    }
};