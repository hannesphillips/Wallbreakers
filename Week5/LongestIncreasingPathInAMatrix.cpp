class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        
        // Store longest path at each coordinate, minimizes repetitive work
        vector<vector<int>> pathMem(matrix.size(), vector<int>(matrix[0].size(), -1));
        
        int longest = 1;
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                longest = max(longest, getNodePathLen(matrix, i, j, -1, pathMem));
        
        return longest;
    }
    
    /* Check if next value in each direction is greater than the previous cell.
    If mem at that coord is not -1, we have encountered this value already, extract
    and utilize it's longest path. Otherwise expand in each direction and retain max
    path length */
    int getNodePathLen(vector<vector<int>>& M, int i, int j, int val, vector<vector<int>>& mem)
    {
        if(i < 0 || j < 0 || i >= M.size() || j >= M[0].size()) return 0;
        
        if(M[i][j] <= val) return 0;
        if(mem[i][j] >= 0) return mem[i][j];
        
        val = M[i][j];
        int m1 = max(getNodePathLen(M, i-1, j, val, mem), getNodePathLen(M, i+1, j, val, mem));
        int m2 = max(getNodePathLen(M, i, j-1, val, mem), getNodePathLen(M, i, j+1, val, mem));
        mem[i][j] = 1 + max(m1, m2);
        
        return mem[i][j];
    }
};