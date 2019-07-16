class Solution {
public:
    vector<int> partitionLabels(string S) {
        if(!S.length()) return {};
        
        vector<int> res;
        int char_ind[26];
        for(int i = 0; i < S.length(); i++)
            char_ind[S[i] - 'a'] = i;
        
        string s;
        int part_ceil = 0;
        /* Expand partition. Determine last occurence of character
        Partition continues until all occurences of visited characters
        are utilized (i == part_ceil)
        Push partition length and reset */
        for(int i = 0; i < S.length(); i++) {
            s += S[i];
            part_ceil = max(part_ceil, char_ind[S[i] - 'a']);
            if(i == part_ceil) {
                res.push_back(s.length());
                s.clear();
            }
        }
        return res;
    }
};