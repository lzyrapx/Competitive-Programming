/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-07 23:31:47
 */
class Solution {
public:
    // find minimum sum
    // 从一行到下一行，只能选择间距不超过1的列
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.size() == 0) {
            return 0;
        }
        vector<vector<int>>dp(A.size(), vector<int>(A[0].size(), 0));;
        for(int j = 0; j < A[0].size(); j++) {
            dp[0][j] = A[0][j];
        }
        int ans = INT_MAX;
        for(int i = 1; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                if(j > 0 && j < A[0].size() - 1) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + A[i][j];
                }
                if(j > 0 && j >= A[0].size() - 1) {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + A[i][j];
                }
                if(j == 0 && j < A[0].size() - 1) {
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + A[i][j];
                }
            }
        }
        for(int j = 0; j < A[0].size(); j++) {
            cout << dp[A.size() - 1][j] << endl;
            ans = min(ans, dp[A.size() - 1][j]);
        }
        return ans;
    }
};