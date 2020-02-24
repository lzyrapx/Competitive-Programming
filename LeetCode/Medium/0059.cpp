/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-02-17 00:12:42
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n, 0));
        int turn = 1;
        int L = 0, R = n - 1;
        int U = 0, D = n - 1;
        int k = 1;
        while(k - 1 < n * n) {
            if(turn) {
                for(int i = L; i <= R; i++) {
                    ans[U][i] = k;
                    k++;
                }
                U++;
                for(int i = U; i <= D; i++) {
                    ans[i][R] = k;
                    k++;
                }
                R--;
            }
            else {
                for(int i = R; i >= L; --i) {
                    ans[D][i] = k;
                    k++;
                }
                D--;
                for(int i = D; i >= U; --i) {
                    ans[i][L] = k;
                    k++;
                }
                L++;
            }
            turn = !turn;
        }
        return ans;
    }
};