class Solution {
public:
    int minCut(string s) {
        if(s.size() == 0 ) return 0;
        if(s.size() == 1) return 0;
        int len = s.size();
        // dp[i] 表示从 i 开始到结尾的最小割
        vector<int>dp(len + 1, 0);
        
        //isPa[i][j]表示 字符串[i,j] 是否是回文串
        vector<vector<bool>>isPa(len + 1, vector<bool>(len + 1, false));
        for(int i = 0; i <= len; i++)
        {
            dp[i] = len - i - 1;
        }

        for(int i = len - 1; i >= 0; --i)
        {
            for(int j = i; j < len; j++)
            {
                if(s[i] == s[j] && (j - i <= 1 || isPa[i + 1][j - 1] == true))
                {
                    isPa[i][j]  = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }
        return dp[0];
    }
};