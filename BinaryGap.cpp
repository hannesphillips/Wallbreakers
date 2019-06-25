class Solution {
public:
    int binaryGap(int N) {
        if(N == 0) return 0;
        int max_gap = 0, gap, t = 1;
        string s = bitset<32>(N).to_string();
        s = s.substr(s.find('1'));
        
        if(s.find('1', 1) == string::npos) return 0;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == '1') {
                gap = t;
                if(gap > max_gap) max_gap = gap;
                t = 0;
            }
            t++;
        }
        return max_gap;
    }
};