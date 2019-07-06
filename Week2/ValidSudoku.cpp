class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        if(!chk_row(board)) return false;
        
        if(!chk_col(board)) return false;
        
        if(!chk_sq(board)) return false;
        
        return true;
    }
    
    bool chk_sq(vector<vector<char>>& board) {
        set<char> square;
        
        for(int i = 0; i < 9; i++) {
            
            for(int j = 0; j < 3; j++) {
                int r = j + 3*(i/3);
                
                for(int k = 0; k < 3; k++) {
                    int c = k + 3*(i%3);
                    
                    if(board[r][c] != '.') {
                        if(square.find(board[r][c]) != square.end())
                            return false;
                    
                        square.insert(board[r][c]);
                    }
                }
            }
            square.clear();
        }
        return true;
    }
    
    bool chk_row(vector<vector<char>>& board) {
        set<char> row;
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(row.find(board[i][j]) != row.end())
                        return false;
                    
                    row.insert(board[i][j]);
                }
            }
            row.clear();
        }
        return true;
    }
    
    bool chk_col(vector<vector<char>>& board) {
        set<char> col;
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[j][i] != '.') {
                    if(col.find(board[j][i]) != col.end())
                        return false;
                
                    col.insert(board[j][i]);
                }
            }
            col.clear();
        }
        return true;
    }
};