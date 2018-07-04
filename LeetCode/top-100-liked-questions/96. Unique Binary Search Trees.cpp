class Solution {
public:
    // 卡特兰数
    long long numTrees(int n) {
        if(n==0)return 0;
        if(n==1) return 1;
        vector<long long>dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i = 2;i <= n; i++) {
            dp[i] = 0;
            for(int j = 0; j < i; j++) {
                dp[i] += (dp[j] * dp[i - j - 1]);
            }
        }
        return dp[n];
    }
};