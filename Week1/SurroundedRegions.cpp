class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        
        int row = board.size(), col = board[0].size();
        if(row < 3 || col < 3) return;
        
        // Set all Os to a variable character
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = '?';
            }
        }
        
        // Replace all edge variables and their neighbors with original char
        for(int i = 0; i < col; i++) {
            if(board[0][i] == '?') fillEdge(0, i, board, row, col);
            if(board[row-1][i] == '?') fillEdge(row-1, i, board, row, col);
        }
        for(int i = 0; i < row; i++) {
            if(board[i][0] == '?') fillEdge(i, 0, board, row, col);
            if(board[i][col-1] == '?') fillEdge(i, col-1, board, row, col);
        }
        
        // Replace remaining variable characters with X
        // aka they are surrounded regions
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == '?')
                    board[i][j] = 'X';
            }
        }
        return;
    }
    
    /* Recursive search for edge special characters and all special characters
    that form a path to the edge */
    void fillEdge(int r, int c, vector<vector<char>>& board, int row, int col) {
        if(r < 0 || r >= row || c < 0 || c >= col) return;
        if(board[r][c] != '?') return;
        
        board[r][c] = 'O';
        fillEdge(r-1, c, board, row, col);
        fillEdge(r+1, c, board, row, col);
        fillEdge(r, c-1, board, row, col);
        fillEdge(r, c+1, board, row, col);
    }
   
};