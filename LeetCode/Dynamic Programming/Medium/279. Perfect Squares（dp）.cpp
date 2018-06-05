class Solution {
public:
    int numSquares(int n) {
        vector<int>dp{0};
        int sz = dp.size();
        dp.resize(max(sz, n+1), INT_MAX);
        for(int i=1; i * i <= n; i++) {
            for(int j= max(sz , i * i ); j <= n; j++) {
                dp[j] = min(dp[j],dp[j - i*i] + 1);
            }
        }
        return dp[n];
    }
};