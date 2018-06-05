class Solution {
public:
    int getMoneyAmount(int n)
    {
        if(n == 1) return 0;
        // dp[i][j] 表示 在范围 [i,j] 中赢所需要最少的钱。
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
        for(int i = 0; i < n - 1;i++) 
        {
            dp[i][i+1] = i + 1;
        }
        
        for(int len = 1; len < n; len++)
        {
            for(int i = 0; i + len < n; i++)
            {
                int j = i + len;
                for(int k = i + 1; k < j; k++) 
                { //dp[i][j]就应该遍历切分点找出最小的值，这个切分点可能把问题分成左边或者右边，要取最大值才能保证所有的值都能赢
                    
                    if(dp[i][j] == 0) dp[i][j] = k + 1 + max(dp[i] [k - 1],dp[k + 1][j]);
                    
                    dp[i][j] = min(dp[i][j], k + 1 + max(dp[i][k - 1],dp[k + 1][j]));
                } 
            }
        }
        return dp[0][n-1];
    }
};