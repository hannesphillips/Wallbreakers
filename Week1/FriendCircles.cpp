class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        
        int cnt = 0;
        int span = M.size();
        // Each index represents a student
        // Maintain log of each person being in a friend circle
        vector<bool> friended (span, false);
        
        for(int i = 0; i < span; i++) {
            if(!friended[i]) {
                friended[i] = true;
                expandCircle(i, friended, M);
                cnt++;
            }
        }
        return cnt;
    }
    
    void expandCircle(int i, vector<bool>& friended, vector<vector<int>>& M) {
        for(int j = 0; j < M.size(); j++) {
            /* Verify all friendships of student i */
            if(!friended[j] && i != j && M[i][j]) {
                friended[j] = true;
                expandCircle(j, friended, M);
            }
        }
    }
};