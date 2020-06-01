/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-05-31 00:13:15
 */ 
class Solution {
public:
    long long dp[51][101][51];
    int mod = 1e9 + 7;
    // 1 <= n <= 50
    // 1 <= m <= 100
    // 0 <= k <= n
    // maximum answer = m^n * n!
    int numOfArrays(int n, int m, int k) {
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j <= m; j++) {
            dp[1][j][1] = 1;
        }
        // legth: i, maximum element: j, cost: c
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int c = 1; c <= k; c++) {
                    
                    long long sum = 0;
                    // 添加[1, j] 中的数字到数组的最后
                    sum = (sum + j * dp[i - 1][j][c]) % mod;
                    
                    // 添加 j 到数组的最后
                    for(int x = 1; x < j; x++) {
                        sum = (sum + dp[i - 1][x][c - 1]) % mod;
                    }
                    dp[i][j][c] = (dp[i][j][c] + sum) % mod;
                }
            }
        }
        long long ans = 0;
        for(int j = 1; j <= m; j++) {
            ans = (dp[n][j][k] + ans) % mod;
        }
        return ans;
    }
};