/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-05 10:12:03
 */
class Solution {
public:
    // matrix: 300 * 300
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 1) {
                dp[i][0] = 1;
                cnt++;
            }
        }
        for(int j = 1; j < m; j++) {
            if(matrix[0][j] == 1) {
                dp[0][j] = 1;
                cnt++;
            }
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 1) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    cnt += dp[i][j];
                }
            }
        }
        return cnt;
    }
};