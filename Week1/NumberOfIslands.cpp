class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        
        int cnt = 0;
        int row = grid.size(), col = grid[0].size();
        /* Matrix tracking if each value has been processed */
        vector<vector<bool>> seen (row, vector<bool>(col, false));
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                /* If we encounter a 1 for the first time 
                increment island count and discover all
                of its neighbors */
                if(!seen[i][j] && grid[i][j] == '1') {
                    cnt++;
                    chk_neighbors(i, j, grid, seen);
                }
            }
        }
        return cnt;
    }
    
    void chk_neighbors(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& seen) {
        /* 
        Check valid coordinates only
        Check only if it hasn't been processed already (prevents loop)
        Check only if it's a '1'
        */
        if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size()- 1 || seen[i][j] || grid[i][j] == '0') 
            return;
        
        seen[i][j] = true; // Flag it and continue
        chk_neighbors(i - 1, j, grid, seen);
        chk_neighbors(i + 1, j, grid, seen);
        chk_neighbors(i, j - 1, grid, seen);
        chk_neighbors(i, j + 1, grid, seen);
    }
};