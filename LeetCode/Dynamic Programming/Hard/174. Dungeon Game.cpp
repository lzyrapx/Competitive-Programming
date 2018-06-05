class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // dp[i][j] 表示从(i,j)走到(n,m)的所需要的最小血量, 答案就是dp[0][0]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        dp[m-1][n-1] = max(1,1 - dungeon[m - 1][n - 1]);
        
        //初始化
        for(int i = m - 2; i >= 0; --i)
        {
            dp[i][n - 1] = max(dp[i + 1][n - 1] - dungeon[i][n - 1], 1);
        }
        for(int j = n - 2; j >= 0; --j)
        {
            dp[m - 1][j] = max(dp[m - 1][j + 1] - dungeon[m - 1][j], 1);
        }
        
        for(int i = m - 2; i >= 0; --i)
        {
            for(int j = n - 2; j >= 0; --j)
            {
                dp[i][j] = max(1 , min(dp[i + 1][j] , dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};