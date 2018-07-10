class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0) return false;
        unordered_set<char>row[10];
        unordered_set<char>column[10];
        unordered_set<char>block[3][3];
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0 ; j < m; j++) 
            {
                char c = board[i][j];
                if (c == '.') continue;
                if(row[i].count(c) > 0) return false;
                if(column[j].count(c) > 0) return false;
                if(block[i / 3][j / 3].count(c) > 0) return false;
                row[i].insert(c);
                column[j].insert(c);
                block[i / 3][j / 3].insert(c);
            }
        }
        return true;
    }
};