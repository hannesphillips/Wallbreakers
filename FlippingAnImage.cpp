class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r = A.size(), c = A.at(0).size();
        vector<vector<int>> res;
        
        for(int i = 0; i < r; i++) {
            vector<int> v;
            for(int j = 0; j < c; j++){ 
                if(A.at(i).at(j) == 0) v.push_back(1);
                else v.push_back(0);
            }
            for(int k = 0; k < c/2; k++) {
                int t = v.at(k);
                v.at(k) = v.at(c-1-k);
                v.at(c-1-k) = t;
            }
            res.push_back(v);
        }
        return res;
    }
};