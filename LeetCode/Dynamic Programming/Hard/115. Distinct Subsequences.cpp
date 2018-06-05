class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        // dp[i][j] 表示 t[0,i] 和 s[0,j] 中 S 的 不同子序列 等于 T 的个数。答案就是dp[lens][lent]
        vector<vector<int>> dp(lent + 1, vector<int>(lens + 1, 0));
        // 注意：空串也是任意字符串的一个子序列
        for(int i = 0; i < lent; i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0; i < lens; i++)
        {
            dp[0][i] = 1;
        }
        for(int i = 1; i <= t.size(); i++)
        {
            for(int j = 1; j <= s.size(); j++)
            {
                if(t[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[lent][lens];
    }
};