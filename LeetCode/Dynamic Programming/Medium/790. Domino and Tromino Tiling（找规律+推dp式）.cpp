class Solution {
public:
    const int mod = 1e9 + 7;
    long long dp[1234];
    int numTilings(int N) {
        if(N==0) return 0;
        // 找规律 and 推公式
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        dp[4] = 11;
        for(int i = 5;i <= N; i++)
        {
            dp[i] = (2LL * dp[i-1] % mod + dp[i-3] % mod) % mod;
            dp[i] %= mod;
        }
        return dp[N];
    }
};