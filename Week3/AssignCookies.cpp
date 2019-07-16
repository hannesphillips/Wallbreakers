class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int happy = 0;
        
        // Sorting both sets allows for simpler iteration
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int gp = 0, sp = 0;
        // If a cookie s, satisfies a child g
        // move to the next child
        while(gp < g.size() && sp < s.size()) {
            if(s[sp] >= g[gp]) {
                gp++;
                happy++;
            }
            sp++;
        }
        
        return happy;
    }
};