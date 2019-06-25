class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size(), col = A.at(0).size();
        vector<vector<int>> x;
        vector<int> tmp;
        cout << row << ' ' << col << endl;
        
        for(int j = 0; j < col; ++j) {
            tmp.clear();
            for(int i = 0; i < row; ++i) {
                tmp.push_back(A.at(i).at(j));
            }
            x.push_back(tmp);
        }
        return x;
    }
};