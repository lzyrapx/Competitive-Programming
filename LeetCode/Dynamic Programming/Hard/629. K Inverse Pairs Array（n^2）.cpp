class Solution {
public:
    const int mod = 1e9+7;
    int kInversePairs(int n, int k) {
        if(k == 0) return 1;
        if(n == 0) return 0;
        // dp[i][j] 表示[1,i]的乱序组合中有j个逆序对，那么答案就是dp[n][k].
        
        // 举个例子手推得到：
        //dp[n][k] = dp[n - 1][k] + dp[n - 1][k-1] + ... + dp[n - 1][k - n + 1]
        //我们可以用k+1代替k，得到：
        //dp[n][k+1] = dp[n - 1][k+1] + dp[n - 1][k] + ... + dp[n - 1][k + 1 - n + 1]
        //用第二个等式减去第一个等式可以得到：
        //dp[n][k+1] = dp[n][k] + dp[n - 1][k+1] - dp[n - 1][k - n + 1]
        //将k+1换回成k，可以得到：
        //dp[n][k] = dp[n-1][k] + dp[n][k-1] - dp[n-1][k-n](k >= n)
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= k; j++)
            {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                dp[i][j] %= mod;
                if(j >= i)
                {
                    dp[i][j] = (dp[i][j] - dp[i-1][j - i] + mod) % mod;
                    dp[i][j] %= mod;
                }
            }
        }
        return dp[n][k];
    }
};