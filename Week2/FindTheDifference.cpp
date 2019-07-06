class Solution {
public:
    char findTheDifference(string s, string t) {
        multiset<char> sset(s.begin(), s.end());
        multiset<char> tset(t.begin(), t.end());
        
        for(auto i : tset)
            if(tset.count(i) != sset.count(i))
                return i;
        return 'a';
    }
};