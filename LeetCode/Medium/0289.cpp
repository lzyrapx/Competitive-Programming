/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-07-26 01:08:08
 */ 
class Solution {
public:
    /*
    原本为1的cell，若周围只有0或1个cell为1的话，则变为0；
    原本为1的cell，若周围有2或3个cell为1的话，仍未1保持不变；
    原本为1的cell，若周围有超过3个cell为1的话，则变为0；
    原本为0的cell，若周围有3个cell为1的话，则变为1；
    
    要求； space in-place
    */
    int count(vector<vector<int>>&board, int row, int col) {
        int sum = 0;
        for(int i = row - 1; i <= row + 1; i++) {
            for(int j = col - 1; j <= col + 1; j++) {
                if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) {
                    sum += (board[i][j] & 1);
                }
            }
        }
        sum -= (board[row][col] & 1);
        return sum;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt = count(board, i, j);
                // 2, 3表示存活
                // 0, 1表示死亡
                if(board[i][j] == 1) {
                    if(cnt == 2 || cnt == 3) {
                        board[i][j] = 3; 
                    }
                }
                if(board[i][j] == 0) {
                    if(cnt == 3) {
                        board[i][j] = 2; 
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};