class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        if(word == "") return false;
        
        int r = board.size(), c = board[0].size();
        
        if(r == 1 && c == 1 && word.length() == 1) return word[0] == board[0][0];
        if(word.length() > r * c) return false;
        
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(board[i][j] == word[0]) {
                    if(search(board, i, j, word, 0))
                        return true;
                }
            }
        }   
        return false;
    }
    
    /* Backtracking recursive approach. Expand graph edges if node
    matches next character in word. Set char to '-' to prevent cycles.
    If index reaches size of word we have found the word in the grapg, return true.
    If not backtrack tree and continue. */
    bool search(vector<vector<char>>& b, int i, int j, string& word, int dex) {
        if(dex == word.length()) return true;
        
        if(i < 0 || i >= b.size() || j < 0 || j >= b[0].size()) return false;
        if(b[i][j] != word[dex]) return false;

        char c = b[i][j];
        b[i][j] = '-';
        
        dex++;
        bool res = search(b, i, j - 1, word, dex) || search(b, i + 1, j, word, dex) ||
            search(b, i, j + 1, word, dex) || search(b, i - 1, j, word, dex);
        
        b[i][j] = c;
        
        return res;
    }
};