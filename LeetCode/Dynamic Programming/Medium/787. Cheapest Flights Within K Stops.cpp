class Solution {
public:
    const int INF = 0x3f3f3f3f;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) { // K 是中转站
        
        // dp[i][j] 表示 从起点 到 i 经过 <= j 站  的最小花费
        vector<vector<int>>dp(n+2,vector<int>(K+2,0));
        for(int i=0;i<=n;i++) 
        {
            for(int j=0;j<=K+1;j++) 
            {
                dp[i][j] = INF;
            }
        }
        dp[src][0] = 0;
        for(int i = 1; i <= K + 1 ; i++) //steps
        {
            for(int j = 0; j <= n - 1;j++) { // dest
                dp[j][i] = dp[j][i - 1];
            }
            for(auto f: flights)
            {
                dp[f[1]][i] = min(dp[f[1]][i], dp[f[0]][i-1] + f[2]); 
            }
        }
        if(dp[dst][K+1] == INF) return -1;
        return dp[dst][K+1]; // 记得算上最后一站
    }
};