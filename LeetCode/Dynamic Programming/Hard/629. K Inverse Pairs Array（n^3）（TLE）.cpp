class Solution {
public:
    const int mod = 1e9+7;
    int kInversePairs(int n, int k) {
        if(k == 0) return 1;
        if(n == 0) return 0;
        // dp[i][j] 表示[1,i]的乱序组合中有j个逆序对，那么答案就是dp[n][k].
        //dp[n][k] = dp[n - 1][k] + dp[n - 1][k-1] + ... + dp[n - 1][k - n + 1]
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i <= n ; i++)
        {
            for(int j = 0; j < i; j++)
            {
                for(int t = 0; t <= k; t++)
                {
                    if(0 <= t - j && t - j <= k) 
                    {
                        dp[i][t] =( dp[i][t] + dp[i - 1][t - j] ) % mod;
                        dp[i][t] %= mod;
                    }     
                }
            }
        }
        return dp[n][k];
    }
};