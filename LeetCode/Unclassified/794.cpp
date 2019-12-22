/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-28 10:49:37
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-28 10:49:37
 */
class Solution {
public:
    // X first, O second
    // if we can reach the states, return true, or return false
    bool validTicTacToe(vector<string>& board) {
        int cnt0 = 0, cntx = 0;
        char last;
        for(auto& s : board) {
            for(char c : s) {
                if(c == 'X') cntx++;
                else if(c == 'O') cnt0++;
            }
        }
        // X should be equal or one more than 0
        // Only at most one player can win
        // it X win, it must have one more than 0
        // if 0 win, it must have the same as X
        if(cntx != cnt0 && cntx != cnt0 + 1) return false;
        if(check(board, 'X') && cntx != cnt0 + 1) return false;
        if(check(board, 'O') && cntx != cnt0) return false;
        return true;
    }
    int check(vector<string>&board, char c) {
        for(int i = 0; i <= 2; i ++) {
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == c) {
                return true;
            }
        }
        for(int i = 0; i <= 2; i ++) {
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == c) {
                return true;
            }
        }
        if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if(board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
        return false;
    }
};