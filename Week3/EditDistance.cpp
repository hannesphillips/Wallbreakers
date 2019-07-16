class Solution {
public:
    int minDistance(string word1, string word2) {
        int r = word2.length() + 1;
        int c = word1.length() + 1;
        
        int dis[r][c] = {0};
        // Table tracking edit distance of substr
        
        // Init top and left edge of table with edit vs null string (i.e. inserts)
        for(int i = 0; i < c; i++)
            dis[0][i] = i;
        for(int i = 1; i < r; i++)
            dis[i][0] = i;
        
        /* Based on logic table, equal characters => pull diagonal value
        else, 1 + min of horizontal, vertical, and diagonal neigbor */
        for(int i = 1; i < r; i++) {
            for(int j = 1; j < c; j++) {
                if(word2[i-1] == word1[j-1]) 
                    dis[i][j] = dis[i-1][j-1];
                else
                    dis[i][j] = min(min(dis[i-1][j], dis[i][j-1]), dis[i-1][j-1]) + 1;
            }
        }
        
        // for(int i = 0; i < r; i++) {
        //     for(int j = 0; j < c; j++)
        //         cout << dis[i][j] << ' ';
        //     cout << endl;
        // }
        
        // Return bottom right value
        return dis[r-1][c-1];
    }
}