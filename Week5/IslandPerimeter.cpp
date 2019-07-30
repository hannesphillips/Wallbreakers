class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        if(grid[0].empty()) return 0;
        
        int perim = 0;
        int r = grid.size();
        int c = grid[0].size();
        
        // Pad edges with 0s (water)
        vector<int> fill (c+2, 0);
        grid.push_back(fill);
        grid.insert(grid.begin(), fill);
        
        for(int i = 0; i < r; i++) {
            grid[i+1].push_back(0);
            grid[i+1].insert(grid[i+1].begin(), 0);
        }
        
        /* Scan neighboring cells. If neighbor is
        land mass, 1 less edge accounts to perimeter */
        for(int i = 1; i < r+1; i++) {
            for(int j = 1; j < c+1; j++) {
                if(grid[i][j]) {
                    perim += 4 - (grid[i-1][j] + grid[i+1][j] +
                                 grid[i][j-1] + grid[i][j+1]);
                }
            }
        }
        return perim;
    }
};