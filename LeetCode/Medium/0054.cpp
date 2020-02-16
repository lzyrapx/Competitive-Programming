/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-16 23:53:14
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if(matrix.size() == 0) {
            return ans;
        }
        int turn = 1;
        int L = 0, R = matrix[0].size() - 1;
        int U = 0, D = matrix.size() - 1;
        while(ans.size() != matrix.size() * matrix[0].size()) {
            if(turn) {
                for(int i = L; i <= R; i++) {
                    ans.push_back(matrix[U][i]);
                }
                U++;
                for(int i = U; i <= D; i++) {
                    ans.push_back(matrix[i][R]);
                }
                R--;
            }
            else {
                for(int i = R; i >= L; --i) {
                    ans.push_back(matrix[D][i]);
                }
                D--;
                for(int i = D; i >= U; --i) {
                    ans.push_back(matrix[i][L]);
                }
                L++;
            }
            turn = !turn;
        }
        return ans;
    }
};