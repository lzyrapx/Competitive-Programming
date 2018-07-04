class Solution {
public:
    int dir[4][2] ={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool bfs(vector<vector<char>>& board, string& word, int x, int y, int num)
    {
        if(num == word.size()) return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        if(board[x][y] != word[num]) return false;
        board[x][y] = '\0';
        for(int k = 0; k < 4; k++) 
        {
            if(bfs(board, word , x + dir[k][0], y + dir[k][1], num + 1)) {
                return true;
            }
        }
        board[x][y] = word[num];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(n == 0) return false;
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(bfs( board, word, i , j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};