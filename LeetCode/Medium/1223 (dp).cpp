/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx/Competitive-Programming/tree/master/LeetCode
 * @Date: 2020-03-11 23:28:40
 */
class Solution {
public:
    int mod = 1e9 + 7;
    // 1 <= n <= 5000
    // rollMax.length == 6
    int dieSimulator(int n, vector<int>& rollMax) {
        rollMax.insert(rollMax.begin(), 0);
        vector<vector<long long>>dp(n + 1, vector<long long>(6 + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 6; j++) {
                long long sum = 0;
                for(int num = 1; num <= rollMax[j] && i - num >= 0; num++) {
                    sum += (dp[i - num][0] - dp[i - num][j] + mod) % mod;
                }
                dp[i][j] = sum;
                dp[i][0] = (dp[i][0] + sum) % mod;
            }
        }
        return dp[n][0];
    }
};