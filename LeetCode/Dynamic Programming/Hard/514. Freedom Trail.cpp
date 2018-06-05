class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ring_len = ring.size();
        int key_len = key.size();
        if(ring_len == 0 || key_len == 0) return 0;
        // dp[i][j] 表示当前匹配到key的第 i 个字母，ring的第 j 个字母在12点钟方向的总贡献
        vector<vector<int>> dp(key_len + 1, vector<int>(ring_len + 1, INT_MAX));
        //要匹配key的下一个字母时，可以从上一个状态顺时针或者逆时针转移到现在的状态。 
        for(int i = 0; i < key_len; i++)
        {
            for(int j = 0; j < ring_len; j++)
            {
                if(key[i] == ring[j])
                {
                    if(i == 0)
                    {
                        dp[i][j] = min(j,ring_len - j); // 顺时针 和 逆时针
                    }
                    else
                    {
                        for(int k = 0; k < ring_len; k ++)
                        {
                            if(dp[i-1][k] != INT_MAX)
                            {
                                dp[i][j] = min(dp[i][j], dp[i-1][k] + min(abs(j - k), ring_len - abs(j - k)));
                            }
                        }
                    }
                }
            }
        }
        int ans = dp[key_len - 1][0];
        for(int j = 1; j < ring_len; j++)
        {
            ans = min(ans,dp[key_len - 1][j]);
        }
        return ans + key_len;    
        
    }
};